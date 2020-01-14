#include "line_editing.h"

struct winsize	g_win;

int	wininfo(void)
{
	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &g_win) == -1)
		return (-1);
	return (0);
}
