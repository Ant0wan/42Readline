#ifndef LINE_H
# define LINE_H

# define READLINE_DEFAULT_BUFFER_SIZE 256

struct s_line
{
	char	*buffer;
	size_t	len;
};

extern struct s_line	g_line;

void    init_line_buffer(void);

# define CNULL  0x00
# define CCOPY  0x01
# define CCUT   0x02

struct s_clipboard
{
	char	str[1024];
	int	l;
};

extern struct s_clipboard	g_clipboard;

#endif
