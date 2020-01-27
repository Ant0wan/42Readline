#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
extern struct s_termcaps g_termcaps;

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
	if (g_line_state_invisible.line == NULL)
	{ /* init line */
		g_line_state_invisible.size_buf = 512;
		g_line_state_invisible.line = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
		rl_bzero(g_line_state_invisible.line, 512);
	}
//	if (len + g_line_state_invisible.len >= g_line_state_invisible.size_buf)
//		l_expand();
	rl_strncpy(&(g_line_state_invisible.line[g_cursor.last_c_pos]), string, len);
	if (g_cursor.last_c_pos > len)
		g_line_state_invisible.len += len;
//	g_cursor.last_l_pos = 0;
	update_line(len);
	g_cursor.last_c_pos += len;
}

void	rl_delete(void)
{
	tputs(tgoto(g_termcaps.dc, 0, 0), 1, output);
}

void	rl_backspace(void)
{
	cursor_l();
	tputs(tgoto(g_termcaps.dc, 0, 0), 1, output);
}

void	kill_line(void)
{
	char	s[2];

	s[0] = '^';
	s[1] = 'C';
	insert_text(s, 2);
	rl_bzero(g_line_state_invisible.line, g_line_state_invisible.size_buf);
	g_cursor.last_c_pos = 0;
	write(STDOUT_FILENO, "\n", 1);
}

void	rl_insert(int c)
{
	char	s[1];

	s[0] = (char)c;
	insert_text(s, 1);
}

void	cursor_l(void)
{
	g_cursor.last_c_pos -= 1;
	tputs(tgoto(g_termcaps.backspace, 0, 0), 1, output);
}

void	cursor_r(void)
{
	g_cursor.last_c_pos += 1;
	tputs(tgoto(g_termcaps.forward_char, 0, 0), 1, output);
}

void	history_up(void)
{
	insert_text("=>history command<=", 19); // test
}

void	history_down(void)
{
	return;
}


void	clear_scr(void)
{
	tputs(g_termcaps.clrpag, 1, output);
}

void	clear_eol(void)
{
	tputs(g_termcaps.clreol, 1, output);
}
