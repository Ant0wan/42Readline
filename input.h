#ifndef INPUT_H
# define INPUT_H

union	u_buffer
{
	unsigned long	value;
	char		buf[sizeof(unsigned long)];
};

union u_buffer	read_key(void);

struct	s_quote
{
	char	c;
	char	*no_quote_prompt;
	int	no_quote_prompt_len;
	int	handle;
};

extern struct s_quote	g_quote;

#endif
