#include "ft_readline.h"

struct s_screen			g_screen;

const struct termcaps_string	g_tc_strings[] =
{
	{"@7", &term_at7},
	{"DC", &term_DC},
	{"E3", &term_clrscroll},
	{"IC", &term_IC},
	{"ce", &term_clreol},
	{"cl", &term_clrpag},
	{"cr", &term_cr},
	{"dc", &term_dc},
	{"ei", &term_ei},
	{"ic", &term_ic},
	{"im", &term_im},
	{"kD", &term_kD},	/* delete */
	{"kH", &term_kH},	/* home down ?? */
	{"kI", &term_kI},	/* insert */
	{"kd", &term_kd},
	{"ke", &term_ke},	/* end keypad mode */
	{"kh", &term_kh},	/* home */
	{"kl", &term_kl},
	{"kr", &term_kr},
	{"ks", &term_ks},	/* start keypad mode */
	{"ku", &term_ku},
	{"le", &term_backspace},
	{"mm", &term_mm},
	{"mo", &term_mo},
	{"nd", &term_forward_char},
	{"pc", &term_pc},
	{"up", &term_up},
	{"vb", &visible_bell},
	{"vs", &term_vs},
	{"ve", &term_ve},
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

int		get_screensize(int tty)
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
int		resize_terminal(void)
{
	if (get_screensize(STDIN_FILENO) == -1)
		return (-1);
	if (redisplay_after_sigwinch() == -1)
		return (-1);
	return (0);
}

