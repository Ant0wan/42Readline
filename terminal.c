#include "ft_readline.h"

struct s_screen	g_screen;

int		get_screensize(int tty)
{
	struct winsize	window_size;

	if (ioctl(tty, TIOCGWINSZ, &g_win) == -1)
		return (-1);
	else
	{
		window_size.ws_col = tgetnum ("co");
		window_size.ws_row = tgetnum("li");
		if ((window_size.ws_col | window_size.ws_row) == -1)
			return (-1);
	}
	g_screen.width = window_size.ws_col;
	g_screen.height = window_size.ws_row;
	g_screen.chars = g_screen.width * g_screen.height;
	return (0);
}

static int	redisplay_after_sigwinch(void)
{
	/* Clear the last line (assuming that the screen size change will result in
           either more or fewer characters on that line only) and put the cursor at
           column 0.  Make sure the right thing happens if we have wrapped to a new
           screen line. */
}

/* Redisplay the current line after a SIGWINCH is received. */
int		resize_terminal(void)
{
	if (get_screensize(STDIN_FILENO) == -1)
		return (-1);
	if (redisplay_after_sigwinch() == -1)
		return (-1);
	return (0);
}

