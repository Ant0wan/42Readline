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

	int c;
	while ((c = get_input()))
	{
		if (output(c) != 1)
			return (1);
	}
	reset_terminal();
	return (0);
}
