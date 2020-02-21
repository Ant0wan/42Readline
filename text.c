#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
struct s_clipboard		g_clipboard = { .str = NULL, .l = 0 };

int				g_full_completion = 1;

void	init_line_buffer(void)
{
	g_line_state_invisible.size_buf = 512;
	g_line_state_invisible.line = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
	ft_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
	g_display.cpos_buffer_position = 0;
	g_line_state_invisible.len = 0;
}

static void	l_expand(void)
{
	char	*new;
	size_t	lold;

	lold = g_line_state_invisible.size_buf;
	g_line_state_invisible.size_buf = lold * 2;
	new = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
	ft_bzero(new, lold * 2);
	ft_strncpy(new, g_line_state_invisible.line, lold);
	free(g_line_state_invisible.line);
	g_line_state_invisible.line = new;
}

void	insert_text(const char *string, int len)
{
//	printf("\n\nlen:%d, cpos:%d, line:%d\n\n", len, g_display.cpos_buffer_position, g_line_state_invisible.len);
	while (len + g_line_state_invisible.len >= g_line_state_invisible.size_buf)
		l_expand();
	if (g_display.cpos_buffer_position < g_line_state_invisible.len)
	{
		ft_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position + len]),
			&(g_line_state_invisible.line[g_display.cpos_buffer_position]),
			g_line_state_invisible.len - g_display.cpos_buffer_position);
	}
	ft_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), string, len);
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
			ft_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), &(g_line_state_invisible.line[g_display.cpos_buffer_position + 1]), g_line_state_invisible.len - g_display.cpos_buffer_position + 1);
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
			ft_memmove(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), &(g_line_state_invisible.line[g_display.cpos_buffer_position + 1]), g_line_state_invisible.len - g_display.cpos_buffer_position + 1);
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
	ft_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
	g_display.cpos_buffer_position = 0;
	g_line_state_invisible.len = 0;
	g_cursor.last_c_pos = 0;
	if (g_cursor.last_v_pos != g_display.vis_botlin)
		ft_putstr(tgoto(tgetstr("DO", NULL), 0, g_display.vis_botlin - g_cursor.last_v_pos));
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
			ft_putstr(tgoto(g_termcaps.backspace, 0, 0));
			--g_cursor.last_c_pos;
		}
		else
		{
			g_cursor.last_c_pos = g_screen.width - 1;
			--g_cursor.last_v_pos;
			ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
			ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
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
			ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
			ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
		}
		else
		{
			++g_cursor.last_c_pos;
			ft_putstr(tgoto(g_termcaps.forward_char, 0, 0));
		}
		g_display.cpos_buffer_position += 1;
		update_line();
	}
}

void	cursor_d(void)
{
	int	len_last_line;

	if (g_cursor.last_v_pos != g_display.vis_botlin)
	{
		len_last_line = (g_display.visible_prompt_length + g_line_state_invisible.len) % g_screen.width;
		if (g_cursor.last_v_pos == g_display.vis_botlin - 1
			&& g_cursor.last_c_pos > len_last_line)
		{
			ft_putstr(tgoto(g_termcaps.ch, 0, len_last_line));
			g_display.cpos_buffer_position = g_line_state_invisible.len;
		}
		else
			g_display.cpos_buffer_position += g_screen.width;
		++g_cursor.last_v_pos;
		ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
		update_line();
	}
}

void	cursor_u(void)
{
	if (g_cursor.last_v_pos != 0)
	{
		if (g_cursor.last_v_pos == 1 && g_cursor.last_c_pos < g_display.visible_prompt_length)
		{
			ft_putstr(tgoto(g_termcaps.ch, 0, g_display.visible_prompt_length));
			g_display.cpos_buffer_position = 0;
		}
		else
			g_display.cpos_buffer_position -= g_screen.width;
		--g_cursor.last_v_pos;
		ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
		update_line();
	}
}

static void	clear_line(void)
{
	rl_home();
	ft_putstr(g_termcaps.clreol);
	g_line_state_invisible.len = 0;
	ft_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
}

void	history_up(void)
{
	char	*s;

	s = prev_hist();
	if (s)
	{
		clear_line();
		insert_text(s, ft_strlen(s));
	}
}

void	autocomplete(void)
{
	char	*su;
	int	len;

	su = suggest();
	if (su)
	{
		len = ft_strlen(su);
		if (len)
		{
			insert_text(su, len);
			if (g_full_completion == 1)
				insert_text(" ", 1);
		}
		free(su);
	}
	g_full_completion = 0;
}

void	history_down(void)
{
	char	*s;

	s = next_hist();
	if (s)
	{
		clear_line();
		insert_text(s, ft_strlen(s));
		if (s == g_vline)
		{
			free(g_vline);
			g_vline = NULL;
		}
	}
}

void	rl_home(void)
{
	g_cursor.last_c_pos = g_display.visible_prompt_length;
	if (g_cursor.last_c_pos > 0)
		ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
	if (g_cursor.last_v_pos > 0)
	{
		ft_putstr(tgoto(tgetstr("UP", NULL), 0, g_cursor.last_v_pos));
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
		ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
		g_display.cpos_buffer_position = g_line_state_invisible.len;
	}
	if (g_cursor.last_v_pos != g_display.vis_botlin)
	{
		ft_putstr(tgoto(tgetstr("DO", NULL), 0, g_display.vis_botlin - g_cursor.last_v_pos));
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
	ft_putstr(g_termcaps.clrpag);
	update_line();
}

/* Function to use to replace all NULL in keymap */
void	rl_void(void)
{
	ft_putstr(tgetstr("bl", NULL));
	return;
}

void	paste_via_input(unsigned long v)
{
	union u_buffer	u;
	int		len;

	len = 0;
	u.value = v;
	while (len < 8 && u.buf[len])
		++len;
	insert_text(&(u.buf[0]), len);
}

/* Ctrl+K: Cut the part of the line after the cursor, adding it to the clipboard. */
void	clear_eol(void)
{
	if (g_display.cpos_buffer_position != g_line_state_invisible.len)
	{
		g_clipboard.l = g_line_state_invisible.len - g_display.cpos_buffer_position;
		if (g_clipboard.str != NULL)
			free(g_clipboard.str);
		g_clipboard.str = ft_strndup(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_clipboard.l);
		ft_bzero(&(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_clipboard.l);
		g_line_state_invisible.len -= g_clipboard.l;
		update_line();
	}
}

/* Ctrl+Y: Paste the last thing you cut from the clipboard. The y here stands for “yank”. */
void	clip_paste(void)
{
	insert_text(g_clipboard.str, g_clipboard.l);
}

/* Ctrl+U: Cut the part of the line before the cursor, adding it to the clipboard. */
void	clear_befline(void)
{
	int	rest;

	if (g_display.cpos_buffer_position != 0)
	{
		if (g_clipboard.str != NULL)
			free(g_clipboard.str);
		g_clipboard.str = ft_strndup(g_line_state_invisible.line, g_display.cpos_buffer_position);
		g_clipboard.l = g_display.cpos_buffer_position;
		g_line_state_invisible.len -= g_display.cpos_buffer_position;
		ft_memmove(g_line_state_invisible.line, &(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_display.cpos_buffer_position);
		ft_bzero(&(g_line_state_invisible.line[g_line_state_invisible.len]), g_clipboard.l);
		g_display.cpos_buffer_position = 0;
		rl_home();
	}
}

/* Ctrl+W: Cut the word before the cursor, adding it to the clipboard. */
void	cut_prev_wd(void)
{
	int	start;

	if (g_display.cpos_buffer_position != 0)
	{
		if (g_clipboard.str != NULL)
			free(g_clipboard.str);
		start = g_display.cpos_buffer_position;
		while (start && g_line_state_invisible.line[start - 1] == ' ')
			--start;
		while (start && g_line_state_invisible.line[start - 1] != ' ')
			--start;
		g_clipboard.l = g_display.cpos_buffer_position - start;
		g_clipboard.str = ft_strndup(&(g_line_state_invisible.line[start]), g_clipboard.l);
		ft_memmove(&(g_line_state_invisible.line[start]), &(g_line_state_invisible.line[g_display.cpos_buffer_position]), g_line_state_invisible.len - g_display.cpos_buffer_position);
		g_line_state_invisible.len -= g_clipboard.l;
		ft_bzero(&(g_line_state_invisible.line[g_line_state_invisible.len]), g_clipboard.l);
		g_display.cpos_buffer_position = start;
		update_line();
	}
}
