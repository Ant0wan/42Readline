#include "ft_readline.h"

/* An array of function pointers, one for each possible key.
   If the type byte is ISKMAP, then the pointer is the address of
   a keymap. */


struct s_keymap_entry	g_emacs_standard_keymap[] =
{ /* 127 entries */
  { ISFUNC, NULL }, /* Control keys. */	/* Control-@ */
  { ISFUNC, NULL },			/* Control-a */
  { ISFUNC, NULL },			/* Control-b */
  { ISFUNC, kill_line },		/* Control-c */
  { ISFUNC, NULL },			/* Control-d */
  { ISFUNC, NULL },			/* Control-e */
  { ISFUNC, NULL },			/* Control-f */
  { ISFUNC, NULL },				/* Control-g */
  { ISFUNC, NULL },			/* Control-h */
  { ISFUNC, NULL },			/* Control-i */
  { ISFUNC, NULL },			/* Control-j */
  { ISFUNC, NULL },			/* Control-k */
  { ISFUNC, clear_scr },			/* Control-l */
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









struct s_keymap_entry	g_emacs_ctlx_keymap[] =
{
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, history_up },
	{ ISFUNC, history_down },
	{ ISFUNC, cursor_r },
	{ ISFUNC, cursor_l },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
	{ ISFUNC, NULL },
 };
