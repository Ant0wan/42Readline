#include "line_editing.h"

int	tc_move(void)
{
	union u_buffer	buffer_u;

	buffer_u.value = 0;
	while (read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf)))
		return (buffer_u.value);
	return (0);
}
