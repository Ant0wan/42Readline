#include "ft_readline.h"

struct s_screen		g_screen;
struct s_termcaps	g_termcaps = {0};
struct termios		g_termios;
struct termios		g_termios_backup;

struct s_term			g_term =
{
	.terminal_name = NULL,
	.term_string_buffer = NULL,
	.term_buffer = NULL,
	.autowrap = 0,
	.terminal_can_insert = 0,
	.has_meta = 0
};

const struct s_termcaps_string	g_tc_strings[] =
{
	{"@7", &g_termcaps.at7}, /* 0 */
	{"DC", &g_termcaps.DC}, /* 1 */
	{"E3", &g_termcaps.clrscroll}, /* 2 */
	{"IC", &g_termcaps.IC}, /* 3 */
	{"ce", &g_termcaps.clreol}, /* 4 */
	{"ch", &g_termcaps.ch}, /* 5 */
	{"cl", &g_termcaps.clrpag}, /* 6 */
	{"cr", &g_termcaps.cr}, /* 7 */
	{"dc", &g_termcaps.dc}, /* 8 */
	{"ei", &g_termcaps.ei}, /* 9 */
	{"ic", &g_termcaps.ic}, /* 10 */
	{"im", &g_termcaps.im}, /* 11 */
	{"kD", &g_termcaps.kD},	/* 12 delete */
	{"kH", &g_termcaps.kH},	/* 13 home down ?? */
	{"kI", &g_termcaps.kI},	/* 14 insert */
	{"kd", &g_termcaps.kd},  /* 15 */
	{"ke", &g_termcaps.ke},	/* 16 end keypad mode */
	{"kh", &g_termcaps.kh},	/* 17home */
	{"kl", &g_termcaps.kl}, /* 18 */
	{"kr", &g_termcaps.kr}, /* 19 */
	{"ks", &g_termcaps.ks},	/* 20 start keypad mode */
	{"ku", &g_termcaps.ku}, /* 21 */
	{"le", &g_termcaps.backspace}, /* 22 */
	{"mm", &g_termcaps.mm}, /* 23 */
	{"mo", &g_termcaps.mo}, /* 24 */
	{"nd", &g_termcaps.forward_char}, /* 25 */
	{"pc", &g_termcaps.pc}, /* 26 */
	{"up", &g_termcaps.up}, /* 27 */
	{"vb", &g_termcaps.visible_bell}, /* 28 */
	{"vs", &g_termcaps.vs}, /* 29 */
	{"ve", &g_termcaps.ve} /* 30 */
};

/* Inititalize termcaps. Get termcaps values. */
void	get_term_capabilities(char **bp)
{
	register int	i;

	i = 0;
	while (i < NUM_TC_STRINGS)
	{
		*(g_tc_strings[i].value) = tgetstr((char *)g_tc_strings[i].var, bp);
		++i;
	}
}

int	get_screensize(int tty)
{
	struct winsize	window_size;

	if (ioctl(tty, TIOCGWINSZ, &window_size) == -1)
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

///* Redisplay the current line after a SIGWINCH is received. */
//int	resize_terminal(void)
//{
//	if (get_screensize(STDIN_FILENO) == -1)
//		return (-1);
//	if (redisplay_after_sigwinch() == -1)
//		return (-1);
//	return (0);
//}

int	init_terminal(void)
{
	char	*buffer;

	if (g_term.terminal_name == NULL)
		g_term.terminal_name = "dumb";
	if (get_screensize(STDIN_FILENO) == -1)
		return (-1);
	if (g_term.term_string_buffer == NULL)
		g_term.term_string_buffer = (char*)malloc(2032);
	if (g_term.term_buffer == NULL)
		g_term.term_buffer = (char*)malloc(4080);
	if (tgetent(g_term.term_buffer, g_term.terminal_name) <= 0)
	{
		if (g_term.term_string_buffer)
			free(g_term.term_string_buffer);
		if (g_term.term_buffer)
			free(g_term.term_buffer);
		g_term.term_buffer = NULL;
		g_term.term_string_buffer = NULL;
		return (-1); /* not to handle crap cases */
	}
	buffer = g_term.term_string_buffer;
	get_term_capabilities(&buffer);
	g_term.autowrap = (tgetflag("am") && tgetflag("xn"));
	g_term.terminal_can_insert = (g_termcaps.IC || g_termcaps.im || g_termcaps.ic);
	g_term.has_meta = (tgetflag("km") != 0);
	bind_keys(g_emacs_standard_keymap);
/*	For VI_MODE only, coming...
	bind_termcap(vi_movement_keymap);
	bind_termcap(vi_insertion_keymap);
*/
	return (0);
}
