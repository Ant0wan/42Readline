#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>

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

char	*ft_readline(const char *prompt);

#endif
