#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
static void	l_expand(void)
{
	char	*new;
	size_t	lold;

	lold = g_rl_line.size_buf;
	g_rl_line.size_buf = lold * 2;
	new = (char*)malloc(sizeof(char) * g_rl_line.size_buf);
	strncpy(new, g_rl_line.line_buffer, lold);
	free(g_rl_line.line_buffer);
	g_rl_line.line_buffer = new;
}

void	insert_text(const char *string, int len)
{
	if (g_rl_line.line_buffer == NULL)
	{
		g_rl_line.line_buffer = (char*)malloc(sizeof(char) * g_rl_line.size_buf);
		g_rl_line.line_buffer[0] = '\0';
	}
	if (len + g_rl_line.len >= g_rl_line.size_buf)
		l_expand();
	strncat(g_rl_line.line_buffer, string, len);
	g_rl_line.len += len;
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
