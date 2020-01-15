#include "ft_readline.h"

# include <stdio.h>
# include <string.h>

int	main(int argc, char **argv)
{
	char	*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = ft_readline((char *)NULL);
		if (input == 0)
			break;
		printf("%s\n", input);
		if (strcmp(input, "exit") == 0)
			break;
		free(input);
	}
/*
	if (is_interactive() == -1)
		exit(EXIT_FAILURE);

	int c;
	while ((c = get_input()))
	{
		if (output(c) != 1)
			return (1);
	}
	reset_terminal();
*/
	return (0);
}
