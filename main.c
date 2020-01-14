#include "line_editing.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (is_interactive() == -1)
		exit(EXIT_FAILURE);

	struct winsize	win;
	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &win) == -1)
		exit(EXIT_FAILURE);

	if (tputs(tgoto(g_tc.cm, win.ws_col + 1, win.ws_row + 1), 1, output))
		return (1);
	if (5 != write(STDOUT_FILENO, "hello", 5))
		return (1);
	else
		return (0);

	reset_terminal();
	return (0);
}
