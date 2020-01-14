#include "line_editing.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	set_interactive_mode();
	reset_terminal();
	return (0);
}
