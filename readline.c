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
	init_line_buffer();
	value = g_line_state_invisible.line;
	update_line();
	while (c.value)
	{
		c = read_key();
		//printf("%c%c%c%c\n", c.buf[0], c.buf[1], c.buf[2], c.buf[3]); /* Debug */
		//printf("%d %d %d %d  %d %d %d %d\n", (int)c.buf[0], (int)c.buf[1], (int)c.buf[2], (int)c.buf[3], (int)c.buf[4], (int)c.buf[5], (int)c.buf[6], (int)c.buf[7]); /* Debug */
		//printf("%d\n", c.value); /* Debug */
	//	if (*g_quote.stack != '\0')
		if (enter_rc(c))
			return (value);
		if (isstdkey(c.value))
			(g_emacs_standard_keymap[c.value].func)(c.value);
		else if (isctrlkey(c))
		{
			if (mvctrlkey(c))
				c.buf[2] = c.buf[5] + 20;
			(g_emacs_ctlx_keymap[c.buf[2]].func)();
		}
		else if (ismetachar(c))
			return (value);
		else
			paste_via_input(c.value);
		value = g_line_state_invisible.line;
	}
	return (value);
}

/* Read a line of input.
   Prompt with prompt. An NULL prompt means none.
   A return value of NULL means that EOF was encountered. */
char	*ft_readline(const char *prompt)
{
	char	*value;

	prep_terminal();
	if (!g_hist)
		init_history();
	initialize();
	set_prompt(prompt);
	rl_set_signals(); /* should set signals for input */

	value = readline_internal();
	if (value[0])
		add_hentry(value, 1);

	deprep_terminal();
	rl_clear_signals(); /* should reset signals after input */
	return (value);
}
