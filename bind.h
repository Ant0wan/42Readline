#ifndef BIND_H
# define BIND_H

# include "keymaps.h"

extern struct s_keymap_entry	*g_keymap;

/* Bind functions */
void	bind_keys(struct s_keymap_entry *keymap);

/* Action functions */
//void	rl_abort(void);
//void	rl_backward_char(void);
//void	rl_backward_char_search(void);
//void	rl_backward_kill_line(void);
//void	rl_backward_kill_word(void);
//void	rl_backward_word(void);
//void	rl_beginning_of_history(void);
//void	rl_beg_of_line(void);
//void	rl_call_last_kbd_macro(void);
//void	rl_capitalize_word(void);
//void	rl_char_search(void);
void	clear_scr(void);
void	clear_eol(void);
//void	rl_complete(void);
void	rl_delete(void);
void	rl_backspace(void);
//void	rl_delete_horizontal_space(void);
//void	rl_digit_argument(void);
//void	rl_do_lowercase_version(void);
//void	rl_downcase_word(void);
//void	rl_end_kbd_macro(void);
//void	rl_end_of_history(void);
//void	rl_end_of_line(void);
//void	rl_exchange_point_and_mark(void);
//void	rl_forward_char(void);
//void	rl_forward_search_history(void);
//void	rl_forward_word(void);
//void	rl_get_next_history(void);
//void	rl_get_previous_history(void);
void	rl_insert(int c);
void	cursor_l(void);
void	cursor_r(void);
void	history_up(void);
void	history_down(void);
//void	rl_insert_comment(void);
//void	rl_insert_completions(void);
void	kill_line(void);
//void	rl_kill_word(void);
//void	rl_newline(void);
//void	rl_noninc_forward_search(void);
//void	rl_noninc_reverse_search(void);
//void	rl_possible_completions(void);
//void	rl_quoted_insert(void);
//void	rl_re_read_init_file(void);
//void	rl_reverse_search_history(void);
//void	rl_revert_line(void);
//void	rl_rubout(void);
//void	rl_set_mark(void);
//void	rl_start_kbd_macro(void);
//void	rl_tab_insert(void);
//void	rl_tilde_expand(void);
//void	rl_transpose_chars(void);
//void	rl_transpose_words(void);
//void	rl_undo_command(void);
//void	rl_unix_line_discard(void);
//void	rl_unix_word_rubout(void);
//void	rl_upcase_word(void);
//void	rl_vi_editing_mode(void);
//void	rl_set_emacs_ctlx_keymap(void);
//void	rl_set_emacs_meta_keymap(void);
//void	rl_yank(void);
//void	rl_yank_last_arg(void);
//void	rl_yank_nth_arg(void);
//void	rl_yank_pop(void);

#endif
