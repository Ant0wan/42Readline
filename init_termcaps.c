#include "line_editing.h"

struct s_termcaps	g_tc;
struct termios		g_termios;
struct termios		g_termios_backup;

static void	get_terms_value(void)
{
	g_tc.cl = tgetstr("cl", NULL);
	g_tc.cm = tgetstr("cm", NULL);
	g_tc.vi = tgetstr("vi", NULL);
	g_tc.ve = tgetstr("ve", NULL);
	g_tc.ab = tgetstr("AB", NULL);
	g_tc.reset = tgetstr("me", NULL);
	g_tc.ku = tgetstr("ku", NULL);
	g_tc.kd = tgetstr("kd", NULL);
	g_tc.kl = tgetstr("kl", NULL);
	g_tc.kr = tgetstr("kr", NULL);
}

static int	init_termcaps(void)
{
	int	ret;
	char	*term_name;

	term_name = getenv("TERM");
	if (term_name == NULL)
	{
		printf("Specify a terminal type with 'TERM=<type>'.\n");
		return (-1);
	}
	ret = tgetent(NULL, term_name);
	if (ret == -1)
	{
		printf("Could not access the termcap data base.\n");
		return (-1);
	}
	else if (ret == 0)
	{
		printf("Terminal type '%s' is not defined in termcap database (or too little information).\n", term_name);
		return (-1);
	}
	get_terms_value();
	return (0);
}

int	set_interactive_mode(void)
{
	if (init_termcaps() == 0)
	{
		if (tcgetattr(STDIN_FILENO, &g_termios) == -1)
			return (-1);
		if (tcgetattr(STDIN_FILENO, &g_termios_backup) == -1)
			return (-1);
		g_termios.c_lflag &= ~(ICANON);
		g_termios.c_lflag &= ~(ECHO);
		if (tcsetattr(STDIN_FILENO, 0, &g_termios) == -1)
			return (-1);
	}
	return (0);
}

int	reset_terminal(void)
{
	if (tcsetattr(STDIN_FILENO, 0, &g_termios_backup) == -1)
		return (-1);
}
