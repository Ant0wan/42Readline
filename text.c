#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
extern struct s_termcaps	g_termcaps;

struct s_clipboard		g_clipboard = { .flag = CNULL, .str = NULL };

void	init_line_buffer(void)
{
	if (g_line_state_invisible.line == NULL)
	{
		g_line_state_invisible.size_buf = 512;
		g_line_state_invisible.line = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
		rl_bzero(g_line_state_invisible.line, 512);
	}
}

static void	l_expand(void)
{
	char	*new;
	size_t	lold;

	lold = g_line_state_invisible.size_buf;
	g_line_state_invisible.size_buf = lold * 2;
	new = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
	rl_bzero(new, lold * 2);
	rl_strncpy(new, g_line_state_invisible.line, lold);
	free(g_line_state_invisible.line);
	g_line_state_invisible.line = new;
}

void	insert_text(const char *string, int len)
{
	while (len + g_line_state_invisible.len >= g_line_state_invisible.size_buf)
		l_expand();
	if (g_display.cpos_buffer_position + len <= g_line_state_invisible.len + 1)
		rl_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position + len]), &(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_line_state_invisible.len - len - g_display.cpos_buffer_position + 2);
	rl_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), string, len);
	if (g_display.cpos_buffer_position >= len - 1 || g_line_state_invisible.len == 0)
		g_line_state_invisible.len += len;
	g_display.cpos_buffer_position += len;
	update_line();
}

void	rl_delete(void)
{
	if (g_display.cpos_buffer_position < g_line_state_invisible.len && g_line_state_invisible.len > 0)
	{
		if (g_line_state_invisible.line[g_display.cpos_buffer_position] && g_display.cpos_buffer_position <= g_line_state_invisible.len)
		{
			rl_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), &(g_line_state_invisible.line[g_display.cpos_buffer_position + 1]), g_line_state_invisible.len - g_display.cpos_buffer_position + 1);
			g_line_state_invisible.line[g_line_state_invisible.len + 1] = '\0';
			update_line();
			--g_line_state_invisible.len;
		}
		else if (g_display.cpos_buffer_position > 0)
		{
			g_line_state_invisible.line[g_display.cpos_buffer_position] = '\0';
			update_line();
			--g_line_state_invisible.len;
		}
	}
}

void	rl_backspace(void)
{
	if (g_display.cpos_buffer_position > 0)
	{
		cursor_l();
		if (g_line_state_invisible.line[g_display.cpos_buffer_position])
		{
			rl_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), &(g_line_state_invisible.line[g_display.cpos_buffer_position + 1]), g_line_state_invisible.len - g_display.cpos_buffer_position + 1);
			g_line_state_invisible.line[g_line_state_invisible.len + 1] = '\0';
		}
		else
			g_line_state_invisible.line[g_display.cpos_buffer_position] = '\0';
		update_line();
		--g_line_state_invisible.len;
	}
}

void	kill_line(void)
{
	write(STDOUT_FILENO, "^C", 2);
	rl_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
	g_display.cpos_buffer_position = 0;
	g_line_state_invisible.len = 0;
	g_cursor.last_c_pos = 0;
	if (g_cursor.last_v_pos != g_display.vis_botlin)
		tputs(tgoto(tgetstr("DO", NULL), 0, g_display.vis_botlin - g_cursor.last_v_pos), 1, output);
	g_cursor.last_v_pos = 0;
	write(STDOUT_FILENO, "\n", 1);
	update_line();
}

void	rl_insert(int c)
{
	char	s[1];

	s[0] = (char)c;
	insert_text(s, 1);
}

void	cursor_l(void)
{
	if (g_display.cpos_buffer_position > 0)
	{
		if (g_cursor.last_c_pos > 0)
		{
			tputs(tgoto(g_termcaps.backspace, 0, 0), 1, output);
			--g_cursor.last_c_pos;
		}
		else
		{
			g_cursor.last_c_pos = g_screen.width - 1;
			--g_cursor.last_v_pos;
			tputs(tgoto(tgetstr("up", NULL), 0, 0), 1, output);
			tputs(tgoto(tgetstr("ch", NULL), 0, g_cursor.last_c_pos), 1, output);
		}
		g_display.cpos_buffer_position -= 1;
		update_line();
	}
}

void	cursor_r(void)
{
	if (g_display.cpos_buffer_position < g_line_state_invisible.len)
	{
		if (g_cursor.last_c_pos == g_screen.width)
		{
			g_cursor.last_c_pos = 0;
			++g_cursor.last_v_pos;
			tputs(tgoto(tgetstr("do", NULL), 0, 0), 1, output);
			tputs(tgoto(tgetstr("ch", NULL), 0, g_cursor.last_c_pos), 1, output);
		}
		else
		{
			++g_cursor.last_c_pos;
			tputs(tgoto(g_termcaps.forward_char, 0, 0), 1, output);
		}
		g_display.cpos_buffer_position += 1;
		update_line();
	}
}

void	cursor_d(void)
{
	return;
}

void	cursor_u(void)
{
	return;
}

void	clear_line(void)
{
	rl_home();
	tputs(g_termcaps.clreol, 1, output);
	g_line_state_invisible.len = 0;
	rl_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
}

void	history_up(void)
{
	clear_line();
	insert_text("=>history command<=", 19); // test
}

void	autocomplete(void)
{
	insert_text("=>suggest<=", 11); // test
	insert_text(" ", 1); // test
}

void	history_down(void)
{
	return;
}

void	rl_home(void)
{
	g_cursor.last_c_pos = g_display.visible_prompt_length;
	if (g_cursor.last_c_pos > 0)
		tputs(tgoto(tgetstr("ch", NULL), 0, g_cursor.last_c_pos), 1, output);
	if (g_cursor.last_v_pos > 0)
	{
		tputs(tgoto(tgetstr("UP", NULL), 0, g_cursor.last_v_pos), 1, output);
		g_cursor.last_v_pos = 0;
	}
	g_display.cpos_buffer_position = 0;
	update_line();
}


void	rl_end(void)
{
	g_cursor.last_c_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) % g_screen.width;
	if (g_cursor.last_c_pos > 0)
	{
		tputs(tgoto(tgetstr("ch", NULL), 0, g_cursor.last_c_pos), 1, output);
		g_display.cpos_buffer_position = g_line_state_invisible.len;
	}
	if (g_cursor.last_v_pos != g_display.vis_botlin)
	{
		tputs(tgoto(tgetstr("DO", NULL), 0, g_display.vis_botlin - g_cursor.last_v_pos), 1, output);
		g_display.cpos_buffer_position = g_line_state_invisible.len;
		g_cursor.last_v_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) / g_screen.width;
	}
	update_line();
}

void	wd_right(void)
{
	while (g_line_state_invisible.line[g_display.cpos_buffer_position] == ' ' && g_display.cpos_buffer_position < g_line_state_invisible.len)
		cursor_r();
	while (g_line_state_invisible.line[g_display.cpos_buffer_position] != ' ' && g_display.cpos_buffer_position < g_line_state_invisible.len)
		cursor_r();
}

void	wd_left(void)
{
	while (g_display.cpos_buffer_position > 0 && g_line_state_invisible.line[g_display.cpos_buffer_position - 1] == ' ')
		cursor_l();
	while (g_display.cpos_buffer_position > 0 && g_line_state_invisible.line[g_display.cpos_buffer_position - 1] != ' ')
		cursor_l();
}

void	clear_scr(void)
{
	tputs(g_termcaps.clrpag, 1, output);
	update_line();
}

void	clear_eol(void)
{
	if (g_display.cpos_buffer_position == g_line_state_invisible.len)
		return;
	tputs(g_termcaps.clreol, 1, output);
	rl_bzero(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_line_state_invisible.len - g_display.cpos_buffer_position);
	g_line_state_invisible.len -= (g_line_state_invisible.len - g_display.cpos_buffer_position);
	update_line();
}

/* Function to use to replace all NULL in keymap */
void	rl_void(void)
{
	tputs(tgetstr("bl", NULL), 1, output);
	return;
}

void	start_select(void) /* Not done, would be done later */
{
//	tputs(tgetstr("mr", NULL), 1, output);
	return;
}

void	close_select(void) /* Not done, would be done later */
{
//	tputs(g_termcaps.ve, 1, output);
	return;
}

void	paste_clipboard(void) /* Not done, would be done later */
{
	g_clipboard.flag = CNULL;
 //	insert_text("=>history command<=", 19); // test
	return;
}

void	copy_selection(void) /* Not done, would be done later */
{
	if (g_clipboard.flag == CNULL)
		g_clipboard.flag = CCOPY;
 //	insert_text("=>history command<=", 19); // test
	return;
}

void	cut_selection(void)
{
	if (g_clipboard.flag == CNULL)
		g_clipboard.flag = CCOPY;
 //	insert_text("=>history command<=", 19); // test
	return;
}
