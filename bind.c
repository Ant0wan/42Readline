#include "ft_readline.h"

struct s_keymap_entry	*g_keymap;

void    bind_termcap(struct s_keymap_entry *keymap)
{
	g_keymap = keymap;
	(void)keymap;
	return;
}
