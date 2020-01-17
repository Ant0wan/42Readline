#include "ft_readline.h"

/* An array of function pointers, one for each possible key.
   If the type byte is ISKMAP, then the pointer is the address of
   a keymap. */


struct s_keymap_entry	g_emacs_standard_keymap[] =
{ /* 127 entries */
  { ISFUNC, NULL }, /* Control keys. */	/* Control-@ */
  { ISFUNC, NULL },			/* Control-a */
  { ISFUNC, NULL },			/* Control-b */
  { ISFUNC, exit },		/* Control-c */
  { ISFUNC, NULL },			/* Control-d */
  { ISFUNC, NULL },			/* Control-e */
  { ISFUNC, NULL },			/* Control-f */
  { ISFUNC, NULL },				/* Control-g */
  { ISFUNC, NULL },			/* Control-h */
  { ISFUNC, NULL },			/* Control-i */
  { ISFUNC, NULL },			/* Control-j */
  { ISFUNC, NULL },			/* Control-k */
  { ISFUNC, NULL },			/* Control-l */
  { ISFUNC, NULL },			/* Control-m */
  { ISFUNC, NULL },		/* Control-n */
  { ISFUNC, NULL },		/* Control-o */
  { ISFUNC, NULL },		/* Control-p */
  { ISFUNC, NULL },			/* Control-q */
  { ISFUNC, NULL },	/* Control-r */
  { ISFUNC, NULL },	/* Control-s */
  { ISFUNC, NULL },		/* Control-t */
  { ISFUNC, NULL },		/* Control-u */
  { ISFUNC, NULL },			/* Control-v */
  { ISFUNC, NULL },		/* Control-w */
  { ISKMAP, NULL },	/* Control-x */
  { ISFUNC, NULL },				/* Control-y */
  { ISFUNC, NULL },		/* Control-z */
  { ISKMAP, NULL }, /* Control-[ */
  { ISFUNC, NULL },		/* Control-\ */
  { ISFUNC, NULL },			/* Control-] */
  { ISFUNC, NULL },		/* Control-^ */
  { ISFUNC, NULL },			/* Control-_ */
  { ISFUNC, rl_insert }, /* The start of printing characters. */ /* SPACE */
  { ISFUNC, rl_insert },		/* ! */
  { ISFUNC, rl_insert },		/* " */
  { ISFUNC, rl_insert },		/* # */
  { ISFUNC, rl_insert },		/* $ */
  { ISFUNC, rl_insert },		/* % */
  { ISFUNC, rl_insert },		/* & */
  { ISFUNC, rl_insert },		/* ' */
  { ISFUNC, rl_insert },		/* ( */
  { ISFUNC, rl_insert },		/* ) */
  { ISFUNC, rl_insert },		/* * */
  { ISFUNC, rl_insert },		/* + */
  { ISFUNC, rl_insert },		/* , */
  { ISFUNC, rl_insert },		/* - */
  { ISFUNC, rl_insert },		/* . */
  { ISFUNC, rl_insert },		/* / */
  { ISFUNC, rl_insert }, /* Regular digits. */	/* 0 */
  { ISFUNC, rl_insert },		/* 1 */
  { ISFUNC, rl_insert },		/* 2 */
  { ISFUNC, rl_insert },		/* 3 */
  { ISFUNC, rl_insert },		/* 4 */
  { ISFUNC, rl_insert },		/* 5 */
  { ISFUNC, rl_insert },		/* 6 */
  { ISFUNC, rl_insert },		/* 7 */
  { ISFUNC, rl_insert },		/* 8 */
  { ISFUNC, rl_insert },		/* 9 */
  { ISFUNC, rl_insert }, /* A little more punctuation. */ /* : */
  { ISFUNC, rl_insert },		/* ; */
  { ISFUNC, rl_insert },		/* < */
  { ISFUNC, rl_insert },		/* = */
  { ISFUNC, rl_insert },		/* > */
  { ISFUNC, rl_insert },		/* ? */
  { ISFUNC, rl_insert },		/* @ */
  { ISFUNC, rl_insert }, /* Uppercase alphabet. */ /* A */
  { ISFUNC, rl_insert },		/* B */
  { ISFUNC, rl_insert },		/* C */
  { ISFUNC, rl_insert },		/* D */
  { ISFUNC, rl_insert },		/* E */
  { ISFUNC, rl_insert },		/* F */
  { ISFUNC, rl_insert },		/* G */
  { ISFUNC, rl_insert },		/* H */
  { ISFUNC, rl_insert },		/* I */
  { ISFUNC, rl_insert },		/* J */
  { ISFUNC, rl_insert },		/* K */
  { ISFUNC, rl_insert },		/* L */
  { ISFUNC, rl_insert },		/* M */
  { ISFUNC, rl_insert },		/* N */
  { ISFUNC, rl_insert },		/* O */
  { ISFUNC, rl_insert },		/* P */
  { ISFUNC, rl_insert },		/* Q */
  { ISFUNC, rl_insert },		/* R */
  { ISFUNC, rl_insert },		/* S */
  { ISFUNC, rl_insert },		/* T */
  { ISFUNC, rl_insert },		/* U */
  { ISFUNC, rl_insert },		/* V */
  { ISFUNC, rl_insert },		/* W */
  { ISFUNC, rl_insert },		/* X */
  { ISFUNC, rl_insert },		/* Y */
  { ISFUNC, rl_insert },		/* Z */
  { ISFUNC, rl_insert }, /* Some more punctuation. */	/* [ */
  { ISFUNC, rl_insert },		/* \ */
  { ISFUNC, rl_insert },		/* ] */
  { ISFUNC, rl_insert },		/* ^ */
  { ISFUNC, rl_insert },		/* _ */
  { ISFUNC, rl_insert },		/* ` */
  { ISFUNC, rl_insert }, /* Lowercase alphabet. */ /* a */
  { ISFUNC, rl_insert },		/* b */
  { ISFUNC, rl_insert },		/* c */
  { ISFUNC, rl_insert },		/* d */
  { ISFUNC, rl_insert },		/* e */
  { ISFUNC, rl_insert },		/* f */
  { ISFUNC, rl_insert },		/* g */
  { ISFUNC, rl_insert },		/* h */
  { ISFUNC, rl_insert },		/* i */
  { ISFUNC, rl_insert },		/* j */
  { ISFUNC, rl_insert },		/* k */
  { ISFUNC, rl_insert },		/* l */
  { ISFUNC, rl_insert },		/* m */
  { ISFUNC, rl_insert },		/* n */
  { ISFUNC, rl_insert },		/* o */
  { ISFUNC, rl_insert },		/* p */
  { ISFUNC, rl_insert },		/* q */
  { ISFUNC, rl_insert },		/* r */
  { ISFUNC, rl_insert },		/* s */
  { ISFUNC, rl_insert },		/* t */
  { ISFUNC, rl_insert },		/* u */
  { ISFUNC, rl_insert },		/* v */
  { ISFUNC, rl_insert },		/* w */
  { ISFUNC, rl_insert },		/* x */
  { ISFUNC, rl_insert },		/* y */
  { ISFUNC, rl_insert },		/* z */
  { ISFUNC, rl_insert }, /* Final punctuation. */ /* { */
  { ISFUNC, rl_insert },		/* | */
  { ISFUNC, rl_insert },		/* } */
  { ISFUNC, rl_insert },		/* ~ */
  { ISFUNC, NULL },		/* RUBOUT */
};

//struct s_keymap_entry	g_emacs_standard_keymap[] =
//{
//  /* Control keys. */
//  { ISFUNC, rl_set_mark },			/* Control-@ */
//  { ISFUNC, rl_beg_of_line },			/* Control-a */
//  { ISFUNC, rl_backward_char },			/* Control-b */
//  { ISFUNC, NULL },		/* Control-c */
//  { ISFUNC, rl_delete },			/* Control-d */
//  { ISFUNC, rl_end_of_line },			/* Control-e */
//  { ISFUNC, rl_forward_char },			/* Control-f */
//  { ISFUNC, rl_abort },				/* Control-g */
//  { ISFUNC, rl_rubout },			/* Control-h */
//  { ISFUNC, rl_complete },			/* Control-i */
//  { ISFUNC, rl_newline },			/* Control-j */
//  { ISFUNC, rl_kill_line },			/* Control-k */
//  { ISFUNC, rl_clear_screen },			/* Control-l */
//  { ISFUNC, rl_newline },			/* Control-m */
//  { ISFUNC, rl_get_next_history },		/* Control-n */
//  { ISFUNC, NULL },		/* Control-o */
//  { ISFUNC, rl_get_previous_history },		/* Control-p */
//  { ISFUNC, rl_quoted_insert },			/* Control-q */
//  { ISFUNC, rl_reverse_search_history },	/* Control-r */
//  { ISFUNC, rl_forward_search_history },	/* Control-s */
//  { ISFUNC, rl_transpose_chars },		/* Control-t */
//  { ISFUNC, rl_unix_line_discard },		/* Control-u */
//  { ISFUNC, rl_quoted_insert },			/* Control-v */
//  { ISFUNC, rl_unix_word_rubout },		/* Control-w */
//  { ISKMAP, rl_set_emacs_ctlx_keymap },	/* Control-x */
//  { ISFUNC, rl_yank },				/* Control-y */
//  { ISFUNC, NULL },		/* Control-z */
//  { ISKMAP, rl_set_emacs_meta_keymap }, /* Control-[ */
//  { ISFUNC, NULL },		/* Control-\ */
//  { ISFUNC, rl_char_search },			/* Control-] */
//  { ISFUNC, NULL },		/* Control-^ */
//  { ISFUNC, rl_undo_command },			/* Control-_ */
//
//  /* The start of printing characters. */
//  { ISFUNC, rl_insert },		/* SPACE */
//  { ISFUNC, rl_insert },		/* ! */
//  { ISFUNC, rl_insert },		/* " */
//  { ISFUNC, rl_insert },		/* # */
//  { ISFUNC, rl_insert },		/* $ */
//  { ISFUNC, rl_insert },		/* % */
//  { ISFUNC, rl_insert },		/* & */
//  { ISFUNC, rl_insert },		/* ' */
//  { ISFUNC, rl_insert },		/* ( */
//  { ISFUNC, rl_insert },		/* ) */
//  { ISFUNC, rl_insert },		/* * */
//  { ISFUNC, rl_insert },		/* + */
//  { ISFUNC, rl_insert },		/* , */
//  { ISFUNC, rl_insert },		/* - */
//  { ISFUNC, rl_insert },		/* . */
//  { ISFUNC, rl_insert },		/* / */
//
//  /* Regular digits. */
//  { ISFUNC, rl_insert },		/* 0 */
//  { ISFUNC, rl_insert },		/* 1 */
//  { ISFUNC, rl_insert },		/* 2 */
//  { ISFUNC, rl_insert },		/* 3 */
//  { ISFUNC, rl_insert },		/* 4 */
//  { ISFUNC, rl_insert },		/* 5 */
//  { ISFUNC, rl_insert },		/* 6 */
//  { ISFUNC, rl_insert },		/* 7 */
//  { ISFUNC, rl_insert },		/* 8 */
//  { ISFUNC, rl_insert },		/* 9 */
//
//  /* A little more punctuation. */
//  { ISFUNC, rl_insert },		/* : */
//  { ISFUNC, rl_insert },		/* ; */
//  { ISFUNC, rl_insert },		/* < */
//  { ISFUNC, rl_insert },		/* = */
//  { ISFUNC, rl_insert },		/* > */
//  { ISFUNC, rl_insert },		/* ? */
//  { ISFUNC, rl_insert },		/* @ */
//
//  /* Uppercase alphabet. */
//  { ISFUNC, rl_insert },		/* A */
//  { ISFUNC, rl_insert },		/* B */
//  { ISFUNC, rl_insert },		/* C */
//  { ISFUNC, rl_insert },		/* D */
//  { ISFUNC, rl_insert },		/* E */
//  { ISFUNC, rl_insert },		/* F */
//  { ISFUNC, rl_insert },		/* G */
//  { ISFUNC, rl_insert },		/* H */
//  { ISFUNC, rl_insert },		/* I */
//  { ISFUNC, rl_insert },		/* J */
//  { ISFUNC, rl_insert },		/* K */
//  { ISFUNC, rl_insert },		/* L */
//  { ISFUNC, rl_insert },		/* M */
//  { ISFUNC, rl_insert },		/* N */
//  { ISFUNC, rl_insert },		/* O */
//  { ISFUNC, rl_insert },		/* P */
//  { ISFUNC, rl_insert },		/* Q */
//  { ISFUNC, rl_insert },		/* R */
//  { ISFUNC, rl_insert },		/* S */
//  { ISFUNC, rl_insert },		/* T */
//  { ISFUNC, rl_insert },		/* U */
//  { ISFUNC, rl_insert },		/* V */
//  { ISFUNC, rl_insert },		/* W */
//  { ISFUNC, rl_insert },		/* X */
//  { ISFUNC, rl_insert },		/* Y */
//  { ISFUNC, rl_insert },		/* Z */
//
//  /* Some more punctuation. */
//  { ISFUNC, rl_insert },		/* [ */
//  { ISFUNC, rl_insert },		/* \ */
//  { ISFUNC, rl_insert },		/* ] */
//  { ISFUNC, rl_insert },		/* ^ */
//  { ISFUNC, rl_insert },		/* _ */
//  { ISFUNC, rl_insert },		/* ` */
//
//  /* Lowercase alphabet. */
//  { ISFUNC, rl_insert },		/* a */
//  { ISFUNC, rl_insert },		/* b */
//  { ISFUNC, rl_insert },		/* c */
//  { ISFUNC, rl_insert },		/* d */
//  { ISFUNC, rl_insert },		/* e */
//  { ISFUNC, rl_insert },		/* f */
//  { ISFUNC, rl_insert },		/* g */
//  { ISFUNC, rl_insert },		/* h */
//  { ISFUNC, rl_insert },		/* i */
//  { ISFUNC, rl_insert },		/* j */
//  { ISFUNC, rl_insert },		/* k */
//  { ISFUNC, rl_insert },		/* l */
//  { ISFUNC, rl_insert },		/* m */
//  { ISFUNC, rl_insert },		/* n */
//  { ISFUNC, rl_insert },		/* o */
//  { ISFUNC, rl_insert },		/* p */
//  { ISFUNC, rl_insert },		/* q */
//  { ISFUNC, rl_insert },		/* r */
//  { ISFUNC, rl_insert },		/* s */
//  { ISFUNC, rl_insert },		/* t */
//  { ISFUNC, rl_insert },		/* u */
//  { ISFUNC, rl_insert },		/* v */
//  { ISFUNC, rl_insert },		/* w */
//  { ISFUNC, rl_insert },		/* x */
//  { ISFUNC, rl_insert },		/* y */
//  { ISFUNC, rl_insert },		/* z */
//
//  /* Final punctuation. */
//  { ISFUNC, rl_insert },		/* { */
//  { ISFUNC, rl_insert },		/* | */
//  { ISFUNC, rl_insert },		/* } */
//  { ISFUNC, rl_insert },		/* ~ */
//  { ISFUNC, rl_rubout },		/* RUBOUT */
//};

// struct s_keymap_entry	g_emacs_meta_keymap[] =
// {
//   /* Meta keys.  Just like above, but the high bit is set. */
//   { ISFUNC, NULL },	/* Meta-Control-@ */
//   { ISFUNC, NULL },	/* Meta-Control-a */
//   { ISFUNC, NULL },	/* Meta-Control-b */
//   { ISFUNC, NULL },	/* Meta-Control-c */
//   { ISFUNC, NULL },	/* Meta-Control-d */
//   { ISFUNC, NULL },	/* Meta-Control-e */
//   { ISFUNC, NULL },	/* Meta-Control-f */
//   { ISFUNC, abort },			/* Meta-Control-g */
//   { ISFUNC, backward_kill_word },	/* Meta-Control-h */
//   { ISFUNC, tab_insert },		/* Meta-Control-i */
//   { ISFUNC, vi_editing_mode },	/* Meta-Control-j */
//   { ISFUNC, NULL },	/* Meta-Control-k */
//   { ISFUNC, NULL },	/* Meta-Control-l */
//   { ISFUNC, vi_editing_mode }, 	/* Meta-Control-m */
//   { ISFUNC, NULL },	/* Meta-Control-n */
//   { ISFUNC, NULL },	/* Meta-Control-o */
//   { ISFUNC, NULL },	/* Meta-Control-p */
//   { ISFUNC, NULL },	/* Meta-Control-q */
//   { ISFUNC, revert_line },		/* Meta-Control-r */
//   { ISFUNC, NULL },	/* Meta-Control-s */
//   { ISFUNC, NULL },	/* Meta-Control-t */
//   { ISFUNC, NULL },	/* Meta-Control-u */
//   { ISFUNC, NULL },	/* Meta-Control-v */
//   { ISFUNC, NULL },	/* Meta-Control-w */
//   { ISFUNC, NULL },	/* Meta-Control-x */
//   { ISFUNC, yank_nth_arg },		/* Meta-Control-y */
//   { ISFUNC, NULL },	/* Meta-Control-z */
//   { ISFUNC, complete },		/* Meta-Control-[ */
//   { ISFUNC, NULL },	/* Meta-Control-\ */
//   { ISFUNC, backward_char_search },	/* Meta-Control-] */
//   { ISFUNC, NULL },	/* Meta-Control-^ */
//   { ISFUNC, NULL },	/* Meta-Control-_ */
// 
//   /* The start of printing characters. */
//   { ISFUNC, set_mark },		/* Meta-SPACE */
//   { ISFUNC, NULL },	/* Meta-! */
//   { ISFUNC, NULL },	/* Meta-" */
//   { ISFUNC, insert_comment },	/* Meta-# */
//   { ISFUNC, NULL },	/* Meta-$ */
//   { ISFUNC, NULL },	/* Meta-% */
//   { ISFUNC, tilde_expand },		/* Meta-& */
//   { ISFUNC, NULL },	/* Meta-' */
//   { ISFUNC, NULL },	/* Meta-( */
//   { ISFUNC, NULL },	/* Meta-) */
//   { ISFUNC, insert_completions },	/* Meta-* */
//   { ISFUNC, NULL },	/* Meta-+ */
//   { ISFUNC, NULL },	/* Meta-, */
//   { ISFUNC, digit_argument }, 	/* Meta-- */
//   { ISFUNC, yank_last_arg},		/* Meta-. */
//   { ISFUNC, NULL },	/* Meta-/ */
// 
//   /* Regular digits. */
//   { ISFUNC, digit_argument }, 	/* Meta-0 */
//   { ISFUNC, digit_argument }, 	/* Meta-1 */
//   { ISFUNC, digit_argument }, 	/* Meta-2 */
//   { ISFUNC, digit_argument }, 	/* Meta-3 */
//   { ISFUNC, digit_argument }, 	/* Meta-4 */
//   { ISFUNC, digit_argument }, 	/* Meta-5 */
//   { ISFUNC, digit_argument }, 	/* Meta-6 */
//   { ISFUNC, digit_argument }, 	/* Meta-7 */
//   { ISFUNC, digit_argument }, 	/* Meta-8 */
//   { ISFUNC, digit_argument }, 	/* Meta-9 */
// 
//   /* A little more punctuation. */
//   { ISFUNC, NULL },	/* Meta-: */
//   { ISFUNC, NULL },	/* Meta-; */
//   { ISFUNC, beginning_of_history },	/* Meta-< */
//   { ISFUNC, possible_completions },	/* Meta-= */
//   { ISFUNC, end_of_history },	/* Meta-> */
//   { ISFUNC, possible_completions },	/* Meta-? */
//   { ISFUNC, NULL },	/* Meta-@ */
// 
//   /* Uppercase alphabet. */
//   { ISFUNC, do_lowercase_version },	/* Meta-A */
//   { ISFUNC, do_lowercase_version },	/* Meta-B */
//   { ISFUNC, do_lowercase_version },	/* Meta-C */
//   { ISFUNC, do_lowercase_version },	/* Meta-D */
//   { ISFUNC, do_lowercase_version },	/* Meta-E */
//   { ISFUNC, do_lowercase_version },	/* Meta-F */
//   { ISFUNC, do_lowercase_version },	/* Meta-G */
//   { ISFUNC, do_lowercase_version },	/* Meta-H */
//   { ISFUNC, do_lowercase_version },	/* Meta-I */
//   { ISFUNC, do_lowercase_version },	/* Meta-J */
//   { ISFUNC, do_lowercase_version },	/* Meta-K */
//   { ISFUNC, do_lowercase_version },	/* Meta-L */
//   { ISFUNC, do_lowercase_version },	/* Meta-M */
//   { ISFUNC, do_lowercase_version },	/* Meta-N */
//   { ISFUNC, do_lowercase_version },	/* Meta-O */
//   { ISFUNC, do_lowercase_version },	/* Meta-P */
//   { ISFUNC, do_lowercase_version },	/* Meta-Q */
//   { ISFUNC, do_lowercase_version },	/* Meta-R */
//   { ISFUNC, do_lowercase_version },	/* Meta-S */
//   { ISFUNC, do_lowercase_version },	/* Meta-T */
//   { ISFUNC, do_lowercase_version },	/* Meta-U */
//   { ISFUNC, do_lowercase_version },	/* Meta-V */
//   { ISFUNC, do_lowercase_version },	/* Meta-W */
//   { ISFUNC, do_lowercase_version },	/* Meta-X */
//   { ISFUNC, do_lowercase_version },	/* Meta-Y */
//   { ISFUNC, do_lowercase_version },	/* Meta-Z */
// 
//   /* Some more punctuation. */
//   { ISFUNC, NULL },		/* Meta-[ */	/* was rl_arrow_keys */
//   { ISFUNC, delete_horizontal_space },	/* Meta-\ */
//   { ISFUNC, NULL },		/* Meta-] */
//   { ISFUNC, NULL },		/* Meta-^ */
//   { ISFUNC, yank_last_arg },			/* Meta-_ */
//   { ISFUNC, NULL },		/* Meta-` */
// 
//   /* Lowercase alphabet. */
//   { ISFUNC, NULL },	/* Meta-a */
//   { ISFUNC, backward_word },		/* Meta-b */
//   { ISFUNC, capitalize_word }, 	/* Meta-c */
//   { ISFUNC, kill_word },		/* Meta-d */
//   { ISFUNC, NULL },	/* Meta-e */
//   { ISFUNC, forward_word },		/* Meta-f */
//   { ISFUNC, NULL },	/* Meta-g */
//   { ISFUNC, NULL },	/* Meta-h */
//   { ISFUNC, NULL },	/* Meta-i */
//   { ISFUNC, NULL },	/* Meta-j */
//   { ISFUNC, NULL },	/* Meta-k */
//   { ISFUNC, downcase_word },		/* Meta-l */
//   { ISFUNC, NULL },	/* Meta-m */
//   { ISFUNC, noninc_forward_search },	/* Meta-n */
//   { ISFUNC, NULL },	/* Meta-o */	/* was rl_arrow_keys */
//   { ISFUNC, noninc_reverse_search },	/* Meta-p */
//   { ISFUNC, NULL },	/* Meta-q */
//   { ISFUNC, revert_line },		/* Meta-r */
//   { ISFUNC, NULL },	/* Meta-s */
//   { ISFUNC, transpose_words }, 	/* Meta-t */
//   { ISFUNC, upcase_word },		/* Meta-u */
//   { ISFUNC, NULL },	/* Meta-v */
//   { ISFUNC, NULL },	/* Meta-w */
//   { ISFUNC, NULL },	/* Meta-x */
//   { ISFUNC, yank_pop },		/* Meta-y */
//   { ISFUNC, NULL },	/* Meta-z */
// 
//   /* Final punctuation. */
//   { ISFUNC, NULL },	/* Meta-{ */
//   { ISFUNC, NULL },	/* Meta-| */
//   { ISFUNC, NULL },	/* Meta-} */
//   { ISFUNC, tilde_expand },		/* Meta-~ */
//   { ISFUNC, backward_kill_word },	/* Meta-rubout */
// };
// 
struct s_keymap_entry	g_emacs_ctlx_keymap[] =
{
   	/* Control keys. */
	{ ISFUNC, NULL },		/* Control-@ */
	{ ISFUNC, NULL },		/* Control-a */
	{ ISFUNC, NULL },		/* Control-b */
	{ ISFUNC, NULL },		/* Control-c */
	{ ISFUNC, NULL },		/* Control-d */
	{ ISFUNC, NULL },		/* Control-e */
	{ ISFUNC, NULL },		/* Control-f */
//	{ ISFUNC, abort },				/* Control-g */
	{ ISFUNC, NULL },				/* Control-g */
	{ ISFUNC, NULL },		/* Control-h */
	{ ISFUNC, NULL },		/* Control-i */
	{ ISFUNC, NULL },		/* Control-j */
	{ ISFUNC, NULL },		/* Control-k */
	{ ISFUNC, NULL },		/* Control-l */
	{ ISFUNC, NULL },		/* Control-m */
	{ ISFUNC, NULL },		/* Control-n */
	{ ISFUNC, NULL },		/* Control-o */
	{ ISFUNC, NULL },		/* Control-p */
	{ ISFUNC, NULL },		/* Control-q */
	//{ ISFUNC, re_read_init_file },		/* Control-r */
	{ ISFUNC, NULL },		/* Control-r */
	{ ISFUNC, NULL },		/* Control-s */
	{ ISFUNC, NULL },		/* Control-t */
//	{ ISFUNC, undo_command },			/* Control-u */
	{ ISFUNC, NULL },			/* Control-u */
	{ ISFUNC, NULL },		/* Control-v */
	{ ISFUNC, NULL },		/* Control-w */
//	{ ISFUNC, exchange_point_and_mark },	/* Control-x */
	{ ISFUNC, NULL },	/* Control-x */
	{ ISFUNC, NULL },		/* Control-y */
	{ ISFUNC, NULL },		/* Control-z */
	{ ISFUNC, NULL },		/* Control-[ */
	{ ISFUNC, NULL },		/* Control-\ */
	{ ISFUNC, NULL },		/* Control-] */
	{ ISFUNC, NULL },		/* Control-^ */
	{ ISFUNC, NULL },		/* Control-_ */

	/* The start of printing characters. */
	{ ISFUNC, NULL },		/* SPACE */
	{ ISFUNC, NULL },		/* ! */
	{ ISFUNC, NULL },		/* " */
	{ ISFUNC, NULL },		/* # */
	{ ISFUNC, NULL },		/* $ */
	{ ISFUNC, NULL },		/* % */
	{ ISFUNC, NULL },		/* & */
	{ ISFUNC, NULL },		/* ' */
//	{ ISFUNC, start_kbd_macro },		/* ( */
//	{ ISFUNC, end_kbd_macro  },		/* ) */
	{ ISFUNC, NULL },		/* ( */
	{ ISFUNC, NULL  },		/* ) */
	{ ISFUNC, NULL },		/* * */
	{ ISFUNC, NULL },		/* + */
	{ ISFUNC, NULL },		/* , */
	{ ISFUNC, NULL },		/* - */
	{ ISFUNC, NULL },		/* . */
	{ ISFUNC, NULL },		/* / */

	/* Regular digits. */
	{ ISFUNC, NULL },		/* 0 */
	{ ISFUNC, NULL },		/* 1 */
	{ ISFUNC, NULL },		/* 2 */
	{ ISFUNC, NULL },		/* 3 */
	{ ISFUNC, NULL },		/* 4 */
	{ ISFUNC, NULL },		/* 5 */
	{ ISFUNC, NULL },		/* 6 */
	{ ISFUNC, NULL },		/* 7 */
	{ ISFUNC, NULL },		/* 8 */
	{ ISFUNC, NULL },		/* 9 */

	/* A little more punctuation. */
	{ ISFUNC, NULL },		/* : */
	{ ISFUNC, NULL },		/* ; */
	{ ISFUNC, NULL },		/* < */
	{ ISFUNC, NULL },		/* = */
	{ ISFUNC, NULL },		/* > */
	{ ISFUNC, NULL },		/* ? */
	{ ISFUNC, NULL },		/* @ */

	/* Uppercase alphabet. */
//	{ ISFUNC, do_lowercase_version },		/* A */
//	{ ISFUNC, do_lowercase_version },		/* B */
//	{ ISFUNC, do_lowercase_version },		/* C */
//	{ ISFUNC, do_lowercase_version },		/* D */
//	{ ISFUNC, do_lowercase_version },		/* E */
//	{ ISFUNC, do_lowercase_version },		/* F */
//	{ ISFUNC, do_lowercase_version },		/* G */
//	{ ISFUNC, do_lowercase_version },		/* H */
//	{ ISFUNC, do_lowercase_version },		/* I */
//	{ ISFUNC, do_lowercase_version },		/* J */
//	{ ISFUNC, do_lowercase_version },		/* K */
//	{ ISFUNC, do_lowercase_version },		/* L */
//	{ ISFUNC, do_lowercase_version },		/* M */
//	{ ISFUNC, do_lowercase_version },		/* N */
//	{ ISFUNC, do_lowercase_version },		/* O */
//	{ ISFUNC, do_lowercase_version },		/* P */
//	{ ISFUNC, do_lowercase_version },		/* Q */
//	{ ISFUNC, do_lowercase_version },		/* R */
//	{ ISFUNC, do_lowercase_version },		/* S */
//	{ ISFUNC, do_lowercase_version },		/* T */
//	{ ISFUNC, do_lowercase_version },		/* U */
//	{ ISFUNC, do_lowercase_version },		/* V */
//	{ ISFUNC, do_lowercase_version },		/* W */
//	{ ISFUNC, do_lowercase_version },		/* X */
//	{ ISFUNC, do_lowercase_version },		/* Y */
//	{ ISFUNC, do_lowercase_version },		/* Z */

	{ ISFUNC, NULL },		/* A */
	{ ISFUNC, NULL },		/* B */
	{ ISFUNC, NULL },		/* C */
	{ ISFUNC, NULL },		/* D */
	{ ISFUNC, NULL },		/* E */
	{ ISFUNC, NULL },		/* F */
	{ ISFUNC, NULL },		/* G */
	{ ISFUNC, NULL },		/* H */
	{ ISFUNC, NULL },		/* I */
	{ ISFUNC, NULL },		/* J */
	{ ISFUNC, NULL },		/* K */
	{ ISFUNC, NULL },		/* L */
	{ ISFUNC, NULL },		/* M */
	{ ISFUNC, NULL },		/* N */
	{ ISFUNC, NULL },		/* O */
	{ ISFUNC, NULL },		/* P */
	{ ISFUNC, NULL },		/* Q */
	{ ISFUNC, NULL },		/* R */
	{ ISFUNC, NULL },		/* S */
	{ ISFUNC, NULL },		/* T */
	{ ISFUNC, NULL },		/* U */
	{ ISFUNC, NULL },		/* V */
	{ ISFUNC, NULL },		/* W */
	{ ISFUNC, NULL },		/* X */
	{ ISFUNC, NULL },		/* Y */
	{ ISFUNC, NULL },		/* Z */

	/* Some more punctuation. */
	{ ISFUNC, NULL },		/* [ */
	{ ISFUNC, NULL },		/* \ */
	{ ISFUNC, NULL },		/* ] */
	{ ISFUNC, NULL },		/* ^ */
	{ ISFUNC, NULL },		/* _ */
	{ ISFUNC, NULL },		/* ` */

	/* Lowercase alphabet. */
	{ ISFUNC, NULL },		/* a */
	{ ISFUNC, NULL },		/* b */
	{ ISFUNC, NULL },		/* c */
	{ ISFUNC, NULL },		/* d */
//	{ ISFUNC, call_last_kbd_macro },		/* e */
	{ ISFUNC, NULL },		/* e */
	{ ISFUNC, NULL },		/* f */
	{ ISFUNC, NULL },		/* g */
	{ ISFUNC, NULL },		/* h */
	{ ISFUNC, NULL },		/* i */
	{ ISFUNC, NULL },		/* j */
	{ ISFUNC, NULL },		/* k */
	{ ISFUNC, NULL },		/* l */
	{ ISFUNC, NULL },		/* m */
	{ ISFUNC, NULL },		/* n */
	{ ISFUNC, NULL },		/* o */
	{ ISFUNC, NULL },		/* p */
	{ ISFUNC, NULL },		/* q */
	{ ISFUNC, NULL },		/* r */
	{ ISFUNC, NULL },		/* s */
	{ ISFUNC, NULL },		/* t */
	{ ISFUNC, NULL },		/* u */
	{ ISFUNC, NULL },		/* v */
	{ ISFUNC, NULL },		/* w */
	{ ISFUNC, NULL },		/* x */
	{ ISFUNC, NULL },		/* y */
	{ ISFUNC, NULL },		/* z */

	/* Final punctuation. */
	{ ISFUNC, NULL },		/* { */
	{ ISFUNC, NULL },		/* | */
	{ ISFUNC, NULL },		/* } */
	{ ISFUNC, NULL },		/* ~ */
	{ ISFUNC, NULL },		/* RUBOST */
//	{ ISFUNC, backward_kill_line },		/* RUBOUT */
 };
