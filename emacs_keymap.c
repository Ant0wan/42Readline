#include "ft_readline.h"

/* An array of function pointers, one for each possible key.
   If the type byte is ISKMAP, then the pointer is the address of
   a keymap. */


struct s_keymap_entry	g_emacs_standard_keymap[] =
{ /* 127 entries */
  { ISFUNC, rl_void }, /* Control keys. */	/* Control-@ */
  { ISFUNC, rl_void },			/* Control-a */
  { ISFUNC, cursor_l },			/* Control-b */
  { ISFUNC, kill_line },		/* Control-c */
  { ISFUNC, rl_delete },			/* Control-d */
  { ISFUNC, rl_void },			/* Control-e */
  { ISFUNC, cursor_r },			/* Control-f */
  { ISFUNC, rl_void },				/* Control-g */
  { ISFUNC, rl_backspace },			/* Control-h */
  { ISFUNC, autocomplete },			/* Control-i */
  { ISFUNC, rl_void },			/* Control-j */
  { ISFUNC, clear_eol },			/* Control-k */
  { ISFUNC, clear_scr },			/* Control-l */
  { ISFUNC, rl_void },			/* Control-m */
  { ISFUNC, rl_void },		/* Control-n */
  { ISFUNC, rl_void },		/* Control-o */
  { ISFUNC, history_up },		/* Control-p */
  { ISFUNC, rl_void },			/* Control-q */
  { ISFUNC, rl_void },	/* Control-r */
  { ISFUNC, rl_void },	/* Control-s */
  { ISFUNC, rl_void },		/* Control-t */
  { ISFUNC, rl_void },		/* Control-u */
  { ISFUNC, rl_void },			/* Control-v */
  { ISFUNC, rl_void },		/* Control-w */
  { ISKMAP, rl_void },	/* Control-x */
  { ISFUNC, rl_void },				/* Control-y */
  { ISFUNC, rl_void },		/* Control-z */
  { ISKMAP, start_select }, /* Control-[ */
  { ISFUNC, rl_void },		/* Control-\ */
  { ISFUNC, close_select },			/* Control-] */
  { ISFUNC, rl_void },		/* Control-^ */
  { ISFUNC, rl_void },			/* Control-_ */
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
  { ISFUNC, rl_backspace }		/* RUBOUT */
};









struct s_keymap_entry	g_emacs_ctlx_keymap[] =
{
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_delete },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, history_up },
	{ ISFUNC, history_down },
	{ ISFUNC, cursor_r },
	{ ISFUNC, cursor_l },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_end },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_home },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, cursor_u },
	{ ISFUNC, cursor_d },
	{ ISFUNC, wd_right },
	{ ISFUNC, wd_left },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void },
	{ ISFUNC, rl_void }
 };
