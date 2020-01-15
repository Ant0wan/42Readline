#include "ft_readline.h"

/* Bind the arrow key sequences from the termcap description in MAP. */
void	bind_termcap_arrow_keys(t_keymap map)
{
	t_keymap	xkeymap;

	xkeymap = g_keymap;
	g_keymap = map;
}
