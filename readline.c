#include "ft_readline.h"

/* The current style of editing. */
struct s_input	g_input =
{
	.mode = IM_READLINE | IM_INSERT,
	.last_command_was_kill = 0,
	.numeric_arg = 1,
	.explicit_arg = 0,
	.arg_sign = 1
};

/* Read a line of input.
   Prompt with prompt. An NULL prompt means none.
   A return value of NULL means that EOF was encountered. */
char	*ft_readline(const char *prompt)
{
	char	*value;

	/* 1. Check if EOF and clear input and settings */


	/* 2. Set prompt */
	set_prompt(prompt);
	initialize();
}
