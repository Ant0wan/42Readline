#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
static void	l_expand(void)
{
	char	*new;
	size_t	lold;

	lold = g_line_state_invisible.size_buf;
	g_line_state_invisible.size_buf = lold * 2;
	new = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
	strncpy(new, g_line_state_invisible.line, lold);
	free(g_line_state_invisible.line);
	g_line_state_invisible.line = new;
}

void	insert_text(const char *string, int len)
{
	if (g_line_state_invisible.line == NULL)
	{
		g_line_state_invisible.size_buf = 512;
		g_line_state_invisible.line = (char*)malloc(sizeof(char) * g_line_state_invisible.size_buf);
		g_line_state_invisible.line[0] = '\0';
	}
	if (len + g_line_state_invisible.len >= g_line_state_invisible.size_buf)
		l_expand();
	strncat(g_line_state_invisible.line, string, len);
	g_line_state_invisible.len += len;
	update_line();
}

void	kill_line(void)
{
	char	s[2];

	s[0] = '^';
	s[1] = 'C';
	insert_text(s, 2);
}

void	rl_insert(int c)
{
	char	s[1];

	s[0] = (char)c;
	insert_text(s, 1);
}

void	cursor_l(void)
{
	tputs(tgoto(*(g_tc_strings[21].value), 0, 0), 1, output);
}

void	cursor_r(void)
{
	tputs(tgoto(*(g_tc_strings[24].value), 0, 0), 1, output);
}

void	history_up(void)
{
	return;
}

void	history_down(void)
{
	return;
}

void	clear_scr(void)
{
	tputs(*(g_tc_strings[5].value), 1, output);
}
