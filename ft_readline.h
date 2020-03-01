#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <signal.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "bind.h"
# include "keymaps.h"
# include "input.h"
# include "terminal.h"
# include "utils.h"
# include "display.h"
# include "line.h"
# include "tty.h"
# include "history.h"
# include "completion.h"

# define SIGWINCH 28

char	*ft_readline(const char *prompt);

#endif
