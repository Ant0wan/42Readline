
#include "input.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	char		*input;
	union u_buffer	c;

	(void)argc;
	(void)argv;
	while (1)
	{
	//	input = ft_readline((char *)NULL);
		c = get_input();
		printf("%c%c%c%c\n", c.buf[0], c.buf[1], c.buf[2], c.buf[3]);
	}
	return (0);
}
