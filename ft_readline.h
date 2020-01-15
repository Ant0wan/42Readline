#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define NUM_TC_STRINGS (sizeof(tc_strings) / sizeof(struct _tc_string))

struct s_termcaps
{
/* The key sequences output by the arrow keys, if this terminal has any. */
	char	*cl;
	char	*cm;
	char	*vi;
	char	*ve;
	char	*ab;
	char	*reset;
	char	*ku;
	char	*kd;
	char	*kl;
	char	*kr;
};

struct termcaps_string
{
	const char *const	var;
	char			**value;
};

/* Variables that hold the screen dimensions, used by the display code. */
struct s_screen
{
	int	width;
	int	height;
	int	chars;
};

extern struct s_termcaps		g_tc;
extern struct termios			g_termios;
extern struct termios			g_termios_backup;
extern struct s_screen			g_screen;
extern const struct termcaps_string	*g_tc_strings;

int	get_screensize(int tty);
int	is_interactive(void);
int	reset_terminal(void);

union	u_buffer
{
	unsigned int	value;
	char		buf[sizeof(unsigned int)];
};

int	get_input(void);
int	output(int c);

#endif
