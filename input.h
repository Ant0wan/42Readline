#ifndef INPUT_H
# define INPUT_H

union	u_buffer
{
	unsigned long	value;
	char		buf[sizeof(unsigned long)];
};

union u_buffer	read_key(void);

#endif
