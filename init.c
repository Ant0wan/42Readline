/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:21:50 by abarthel          #+#    #+#             */
/*   Updated: 2020/03/03 17:21:51 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/* Flags encapsulating the current readline state. */
static unsigned long	g_flags_readline_state = 0;
struct s_line		g_line = { .buffer = NULL, .len = 0 };

/* Initialize readline and terminal if not already. */
void	initialize(void)
{
	static int	initialized;

	/* If never been called, init terminal and data structures. */
	if (initialized == 0)
	{
		/* Allocate data structures. */
		if (g_line.buffer == NULL)
		{
			g_line.len = READLINE_DEFAULT_BUFFER_SIZE;
			g_line.buffer = (char*)malloc(g_line.len);
		}
		/* Initialize the terminal interface. */
		if (g_term.terminal_name == NULL)
			g_term.terminal_name = ft_getenv("TERM");
		tgetent(NULL, g_term.terminal_name);
		init_terminal();
		++initialized;
	}
}
