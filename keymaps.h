#ifndef KEYMAPS_H
# define KEYMAPS_H

# define KEYMAP_SIZE 257

/* The values that TYPE can have in a keymap entry. */
# define ISFUNC 0
# define ISKMAP 1
# define ISMACR 2

struct s_keymap_entry
{
	char	type;
	void	*func();
};

typedef struct s_keymap_entry[KEYMAP_SIZE] t_keymap;

extern t_keymap emacs_standard_keymap;
extern t_keymap emacs_meta_keymap;
extern t_keymap emacs_ctlx_keymap;

/* A pointer to the keymap that is currently in use.
    By default, it is the standard emacs keymap. */
extern t_keymap	g_keymap;

void	bind_termcap_arrow_keys(t_keymap map);

#endif
