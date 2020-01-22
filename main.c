#include "ft_readline.h"

/* For test purpose uniquely */

int	main(int argc, char **argv)
{
	char		*input;

	(void)argc;
	(void)argv;
	while (1)
	{
		input = ft_readline((char *)NULL);
//		printf("%s\n", input);
	}
	return (0);
}
