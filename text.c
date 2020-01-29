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
	char	s[2];

	s[0] = '^';
	s[1] = 'C';
	insert_text(s, 2);
	rl_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
	g_display.cpos_buffer_position = 0;
	g_line_state_invisible.len = 0;
	write(STDOUT_FILENO, "\n", 1);
	display_prompt();
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
		g_display.cpos_buffer_position -= 1;
		tputs(tgoto(g_termcaps.backspace, 0, 0), 1, output);
	}
}

void	cursor_r(void)
{
	if (g_display.cpos_buffer_position < g_line_state_invisible.len)
	{
		g_display.cpos_buffer_position += 1;
		tputs(tgoto(g_termcaps.forward_char, 0, 0), 1, output);
	}
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
	int	i;

	i = g_display.visible_prompt_length;
	tputs(tgoto(g_termcaps.cr, 0, 0), 1, output);
	g_display.cpos_buffer_position = 0;
	while (i--)
		tputs(tgoto(g_termcaps.forward_char, 0, 0), 1, output);
}


void	rl_end(void)
{
	while (g_display.cpos_buffer_position < g_line_state_invisible.len)
	{
		g_display.cpos_buffer_position += 1;
		tputs(tgoto(g_termcaps.forward_char, 0, 0), 1, output);
	}
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
	int	i;

	i = g_line_state_invisible.len - g_display.cpos_buffer_position;
	tputs(g_termcaps.clrpag, 1, output);
	display_prompt();
	write(STDOUT_FILENO, g_line_state_invisible.line, g_line_state_invisible.len);
	while (i--)
		tputs(tgoto(g_termcaps.backspace, 0, 0), 1, output);
}

void	clear_eol(void)
{
	tputs(g_termcaps.clreol, 1, output);
	rl_bzero(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_line_state_invisible.len - g_display.cpos_buffer_position);
	g_line_state_invisible.len -= (g_line_state_invisible.len - g_display.cpos_buffer_position);
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
