#include "ft_readline.h"

///* The current style of editing. */
//struct s_input	g_input =
//{
//	.mode = IM_READLINE | IM_INSERT,
//	.last_command_was_kill = 0,
//	.numeric_arg = 1,
//	.explicit_arg = 0,
//	.arg_sign = 1
//};

static char	*readline_internal(void)
{
	union u_buffer	c;
	char		*value;

	value = NULL;
	c.value = 1;
	while (c.value)
	{
		c = read_key();

		//printf("%c%c%c%c\n", c.buf[0], c.buf[1], c.buf[2], c.buf[3]); /* Debug */
		printf("%d %d %d %d\n", (int)c.buf[0], (int)c.buf[1], (int)c.buf[2], (int)c.buf[3]); /* Debug */
		//printf("%d\n", c.value); /* Debug */
		if (enter_rc(c))
			return (value);
		if (isstdkey(c.value))
		{
			(g_emacs_standard_keymap[c.value].func)(c.value);
		}
		else if (isctrlkey(c))
		{
			/* should execute ctrl_keymap */
			(g_emacs_ctlx_keymap[c.buf[2]].func)();
	//		return (value);
		}
		else if (ismetachar(c))
		{
			/* should get meta keymap and get meta_keymap_entry[c.buf[1]] */
			return (value);
		}
	}
	return (value);
}

/* Read a line of input.
   Prompt with prompt. An NULL prompt means none.
   A return value of NULL means that EOF was encountered. */
char	*ft_readline(const char *prompt)
{
	char	*value;

	set_prompt(prompt);
	prep_terminal();
	initialize();
//	rl_set_signals(); /* should set signals for input */

	value = readline_internal();

	deprep_terminal();
//	rl_clear_signals(); /* should reset signals after input */
	return (value);
}
