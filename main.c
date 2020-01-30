#include "ft_readline.h"

/* For test purpose uniquely */

int	main(int argc, char **argv)
{
	char		*input;

	(void)argc;
	(void)argv;
	//input = ft_readline((char *)NULL);
	while (input = ft_readline("$> "))
	{
		printf("\n\nvalue:\n%s\n", input);
		if (!strcmp(input, "exit"))
			break;
	}
	free(input);
	free_hist();
	return (0);
}
