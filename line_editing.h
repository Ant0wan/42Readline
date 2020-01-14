#ifndef LINE_EDITING_H
# define LINE_EDITING_H

#include <curses.h>
#include <term.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct s_termcaps
{
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

extern struct s_termcaps	g_tc;
extern struct termios		g_termios;
extern struct termios		g_termios_backup;
extern struct winsize		g_win;

int	wininfo(void);
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
