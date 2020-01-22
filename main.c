#include "ft_readline.h"

/* For test purpose uniquely */

int	main(int argc, char **argv)
{
	char		*input;

	(void)argc;
	(void)argv;
	//input = ft_readline((char *)NULL);
	input = ft_readline("$>");
	printf("%s\n", input);
	free(input);
	return (0);
}
