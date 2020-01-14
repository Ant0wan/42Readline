#include "line_editing.h"

int	get_input(void)
{
	union u_buffer	buffer_u;

	buffer_u.value = 0;
	if (read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf)))
		return (buffer_u.value);
	return (0);
}
