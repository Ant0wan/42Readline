#include "ft_readline.h"

/* Insert a string of text into the line at point.  This is the only
   way that you should do insertion.  _rl_insert_char () calls this
   function.  Returns the number of characters inserted. */
void	insert_text(const char *string, int len)
{
	
	return ;
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

	s[0] = c.buf[0];
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
