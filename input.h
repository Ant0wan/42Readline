#ifndef INPUT_H
# define INPUT_H

union	u_buffer
{
	unsigned int	value;
	char		buf[sizeof(unsigned int)];
};

union u_buffer	get_input(void);

#endif
