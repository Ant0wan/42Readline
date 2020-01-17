#ifndef KEYMAPS_H
# define KEYMAPS_H

/* The values that TYPE can have in a keymap entry. */
# define ISFUNC 0
# define ISKMAP 1
# define ISMACR 2

struct s_keymap_entry
{
	char	type;
	void	(*func)();
};

extern struct s_keymap_entry	g_emacs_standard_keymap[];
extern struct s_keymap_entry	g_emacs_ctlx_keymap[];

/* Implement later
extern s_keymap_entry	g_emacs_meta_keymap;
*/

#endif
