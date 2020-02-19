#include "ft_readline.h"

/* An array of function pointers, one for each possible key.
   If the type byte is ISKMAP, then the pointer is the address of
   a keymap. */


struct s_keymap_entry	g_emacs_standard_keymap[] =
{ /* 127 entries */
  { ISFUNC, rl_void }, /* Control keys. */	/* Control-@ */
  { ISFUNC, rl_home },			/* Control-a */
  { ISFUNC, cursor_l },			/* Control-b */
  { ISFUNC, kill_line },		/* Control-c */
  { ISFUNC, rl_delete },			/* Control-d */
  { ISFUNC, rl_end },			/* Control-e */
  { ISFUNC, cursor_r },			/* Control-f */
  { ISFUNC, rl_void },				/* Control-g */
  { ISFUNC, rl_backspace },			/* Control-h */
  { ISFUNC, rl_void },			/* Control-i */
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
  { ISFUNC, clear_befline },		/* Control-u */
  { ISFUNC, rl_void },			/* Control-v */
  { ISFUNC, cut_prev_wd },		/* Control-w */
  { ISKMAP, rl_void },	/* Control-x */
  { ISFUNC, clip_paste },				/* Control-y */
  { ISFUNC, rl_void },		/* Control-z */
  { ISKMAP, rl_void }, /* Control-[ */
  { ISFUNC, rl_void },		/* Control-\ */
  { ISFUNC, rl_void },			/* Control-] */
  { ISFUNC, rl_void },		/* Control-^ */
  { ISFUNC, rl_void },			/* Control-_ */
  { ISFUNC, rl_insert }, /* The start of printing characters. */ /* SPACE to TILDE */
	[ ' ' ... '~' ] = { ISFUNC, rl_insert },
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
