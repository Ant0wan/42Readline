/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:23:05 by abarthel          #+#    #+#             */
/*   Updated: 2020/03/03 17:23:06 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	tcsetattr(STDIN_FILENO, TCSADRAIN, &g_termios);
	ft_putstr(*(g_tc_strings[28].value));
}

void	deprep_terminal(void)
{
	tcsetattr(STDIN_FILENO, TCSADRAIN, &g_termios_backup);
}
