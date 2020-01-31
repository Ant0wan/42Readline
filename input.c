#include "ft_readline.h"

union u_buffer	read_key(void)
{
	union u_buffer	buffer_u;

	buffer_u.value = 0;
	read(STDIN_FILENO, buffer_u.buf, sizeof(buffer_u.buf));
	return (buffer_u);
}
