#include "ft_readline.h"

unsigned long	g_flags_readline_state = 0;

void		setstate(unsigned long x)
{
	g_flags_readline_state |= x;
}

void		unsetstate(unsigned long x)
{
	g_flags_readline_state &= ~(x);
}

unsigned long	isstate(unsigned long x)
{
	return (g_flags_readline_state & x);
}
