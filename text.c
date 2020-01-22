#include "ft_readline.h"

void	rl_insert(int c)
{
	output(c);
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
