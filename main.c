#include "line_editing.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (is_interactive() == -1)
		exit(EXIT_FAILURE);

	struct winsize	win;
	printf("%d\n", ioctl(STDERR_FILENO, TIOCGWINSZ, &win));
	printf("col:%d\nrow:%d\n", win.ws_col, win.ws_row);

	reset_terminal();
	return (0);
}
