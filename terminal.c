#include "ft_readline.h"

struct s_screen			g_screen;
struct s_term			g_term = { .termnial_name = NULL };
struct s_termcaps		g_termcaps = {0};

const struct termcaps_string	g_tc_strings[] =
{
	{"@7", &g_termcaps.at7},
	{"DC", &g_termcaps.DC},
	{"E3", &g_termcaps.clrscroll},
	{"IC", &g_termcaps.IC},
	{"ce", &g_termcaps.clreol},
	{"cl", &g_termcaps.clrpag},
	{"cr", &g_termcaps.cr},
	{"dc", &g_termcaps.dc},
	{"ei", &g_termcaps.ei},
	{"ic", &g_termcaps.ic},
	{"im", &g_termcaps.im},
	{"kD", &g_termcaps.kD},	/* delete */
	{"kH", &g_termcaps.kH},	/* home down ?? */
	{"kI", &g_termcaps.kI},	/* insert */
	{"kd", &g_termcaps.kd},
	{"ke", &g_termcaps.ke},	/* end keypad mode */
	{"kh", &g_termcaps.kh},	/* home */
	{"kl", &g_termcaps.kl},
	{"kr", &g_termcaps.kr},
	{"ks", &g_termcaps.ks},	/* start keypad mode */
	{"ku", &g_termcaps.ku},
	{"le", &g_termcaps.backspace},
	{"mm", &g_termcaps.mm},
	{"mo", &g_termcaps.mo},
	{"nd", &g_termcaps.forward_char},
	{"pc", &g_termcaps.pc},
	{"up", &g_termcaps.up},
	{"vb", &g_termcaps.visible_bell},
	{"vs", &g_termcaps.vs},
	{"ve", &g_termcaps.ve}
};


/* Inititalize termcaps. Get termcaps values. */
int	get_term_capabilities(char **bp)
{
	register int	i;

	i = 0;
	while (i < NUM_TC_STRINGS)
	{
		*(g_tc_strings[i].value) = tgetstr((char *)tc_strings[i].var, bp);
		if (g_tc_string[i] == NULL)
			return (-1);
		++i;
	}
	return (0);
}

int	get_screensize(int tty)
{
	struct winsize	window_size;

	if (ioctl(tty, TIOCGWINSZ, &g_win) == -1)
		return (-1);
	else
	{
		window_size.ws_col = tgetnum ("co");
		window_size.ws_row = tgetnum("li");
		if ((window_size.ws_col | window_size.ws_row) == -1)
			return (-1);
	}
	g_screen.width = window_size.ws_col;
	g_screen.height = window_size.ws_row;
	g_screen.chars = g_screen.width * g_screen.height;
	return (0);
}

/* Redisplay the current line after a SIGWINCH is received. */
int	resize_terminal(void)
{
	if (get_screensize(STDIN_FILENO) == -1)
		return (-1);
	if (redisplay_after_sigwinch() == -1)
		return (-1);
	return (0);
}

int	init_terminal_io(const char *terminal_name)
{
}
