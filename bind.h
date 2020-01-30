#ifndef BIND_H
# define BIND_H

# include "keymaps.h"

extern struct s_keymap_entry	*g_keymap;

/* Bind functions */
void	bind_keys(struct s_keymap_entry *keymap);

/* Action functions */
void	start_select(void);
void	close_select(void);
void	paste_clipboard(void);
void    paste_via_input(unsigned long v);
void	copy_clipboard(void);
void	cut_clipboard(void);
void	wd_right(void);
void	wd_left(void);
void	clear_scr(void);
void	clear_eol(void);
void	clear_line(void);
void	autocomplete(void);
void    rl_home(void);
void    rl_void(void);
void    rl_end(void);
void	rl_delete(void);
void	rl_backspace(void);
void	rl_insert(int c);
void	cursor_l(void);
void	cursor_r(void);
void	cursor_u(void);
void	cursor_d(void);
void	history_up(void);
void	history_down(void);
void	kill_line(void);

#endif
