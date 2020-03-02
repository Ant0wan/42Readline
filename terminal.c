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
	{"DO", &g_termcaps.DO}, /* 2 */
	{"E3", &g_termcaps.clrscroll}, /* 3 */
	{"IC", &g_termcaps.IC}, /* 4 */
	{"UP", &g_termcaps.UP}, /* 5 */
	{"bl", &g_termcaps.bl}, /* 6 */
	{"cd", &g_termcaps.cd}, /* 7 */
	{"ce", &g_termcaps.clreol}, /* 8 */
	{"ch", &g_termcaps.ch}, /* 9 */
	{"cl", &g_termcaps.clrpag}, /* 10 */
	{"cr", &g_termcaps.cr}, /* 11 */
	{"dc", &g_termcaps.dc}, /* 12 */
	{"do", &g_termcaps.do1}, /* 13 */
	{"ei", &g_termcaps.ei}, /* 14 */
	{"ic", &g_termcaps.ic}, /* 15 */
	{"im", &g_termcaps.im}, /* 16 */
	{"kD", &g_termcaps.kD},	/* 17 delete */
	{"kH", &g_termcaps.kH},	/* 18 home down ?? */
	{"kI", &g_termcaps.kI},	/* 19 insert */
	{"kd", &g_termcaps.kd},  /* 20 */
	{"ke", &g_termcaps.ke},	/* 21 end keypad mode */
	{"kh", &g_termcaps.kh},	/* 22home */
	{"kl", &g_termcaps.kl}, /* 23 */
	{"kr", &g_termcaps.kr}, /* 24 */
	{"ks", &g_termcaps.ks},	/* 25 start keypad mode */
	{"ku", &g_termcaps.ku}, /* 26 */
	{"le", &g_termcaps.backspace}, /* 27 */
	{"mm", &g_termcaps.mm}, /* 28 */
	{"mo", &g_termcaps.mo}, /* 29 */
	{"nd", &g_termcaps.forward_char}, /* 30 */
	{"pc", &g_termcaps.pc}, /* 31 */
	{"up", &g_termcaps.up}, /* 32 */
	{"vb", &g_termcaps.visible_bell}, /* 33 */
	{"vs", &g_termcaps.vs}, /* 34 */
	{"ve", &g_termcaps.ve} /* 35 */
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
void	resize_terminal(int signo)
{
	(void)signo;
	get_screensize(STDIN_FILENO);
	redisplay_after_sigwinch();
}

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
