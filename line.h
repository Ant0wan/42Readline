#ifndef LINE_H
# define LINE_H

# define READLINE_DEFAULT_BUFFER_SIZE 256

struct s_line
{
	char	*buffer;
	size_t	len;
};

extern struct s_line	g_line;

#endif