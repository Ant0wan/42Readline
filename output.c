#include "line_editing.h"

int	output(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(char)) != sizeof(char))
		return (0);
	return (1);
}
