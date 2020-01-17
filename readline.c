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

static void	readline_internal(union u_buffer c)
{
	if (isstdkey(c.value))
		(g_keymap[c.value].func)(c.value);
	else if (ismetachar(c))
	{
		/* should get meta keymap and get meta_keymap_entry[c.buf[1]] */
		return ;
	}
	else if (isctrlkey(c))
	{
		/* should execute ctrl_keymap */
		return ;
	}
}

/* Read a line of input.
   Prompt with prompt. An NULL prompt means none.
   A return value of NULL means that EOF was encountered. */
char	*ft_readline(const char *prompt)
{
	char	*value;

	/* 1. Check if EOF and clear input and settings */


	/* 2. Set things */
	set_prompt(prompt);
	initialize();
	prep_terminal();
//	rl_set_signals(); /* should set signals for input */

	union u_buffer	c; /* Debug */
	c = read_key(); /* Debug */
	readline_internal(c);
	prep_terminal();

	//printf("%c%c%c%c\n", c.buf[0], c.buf[1], c.buf[2], c.buf[3]); /* Debug */
	printf("%d %d %d %d\n", (int)c.buf[0], (int)c.buf[1], (int)c.buf[2], (int)c.buf[3]); /* Debug */
	//printf("%d\n", c.value); /* Debug */


//	rl_clear_signals(); /* should reset signals after input */
}
