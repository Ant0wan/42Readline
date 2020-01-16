#include "ft_readline.h"

void	prep_terminal(void)
{
	tcgetattr(STDIN_FILENO, &g_termios);
	tcgetattr(STDIN_FILENO, &g_termios_backup);
	g_termios.c_lflag &= ~(ICANON | ECHO);
//	g_termios.c_lflag |= ISIG;
	g_termios.c_lflag &= ~ISIG;
	g_termios.c_cc[VMIN] = 1;
	g_termios.c_cc[VTIME] = 0;
	/* Make sure we differentiate between CR and NL on input. */
	g_termios.c_iflag &= ~(ICRNL | INLCR); /* test */
	tcsetattr(STDIN_FILENO, 0, &g_termios);
}

void	deprep_terminal(void)
{
	tcsetattr(STDIN_FILENO, 0, &g_termios_backup);
}
