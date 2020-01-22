#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>

# include "bind.h"
# include "keymaps.h"
# include "input.h"
# include "terminal.h"
# include "utils.h"
# include "display.h"
# include "line.h"
# include "tty.h"

struct	s_line_buffer
{
	char	*line_buffer;
	size_t	size_buf;
	size_t	len;
};

extern struct s_line_buffer	g_rl_line;

char	*ft_readline(const char *prompt);

#endif
