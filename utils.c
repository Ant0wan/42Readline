#include "ft_readline.h"

int	output(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(int)) != sizeof(int))
		return (0);
	return (1);
}

int		rl_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c ^ (1 << 5));
	return (c);
}

int		rl_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c | (1 << 5));
	return (c);
}

int		isoctal(int c)
{
	return (c >= '0' && c <= '7');
}

int		isxdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int		hexvalue(int c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && (c) <= 'F')
		return (c - 'A' + 10);
	else
		return (c - '0');
}

int	ismetachar(union u_buffer c)
{
	return (c.buf[0] == 27 && c.buf[1] != 0);
}

int	isprintchr(int c)
{
	return (c >= 32 && c <= 126);
}

int	isstdkey(int c)
{
	return (c > 0 && c <= 127);
}

int	isctrlkey(union u_buffer c)
{
	return (c.buf[0] == 27 && c.buf[1] == 91);
}

int	mvctrlkey(union u_buffer c)
{
	return (c.buf[2] == 49 && c.buf[3] == 59 && c.buf[4] == 53);
}

int	enter_rc(union u_buffer c)
{
	return (c.buf[0] == 13 && c.buf[1] == 0);
}
