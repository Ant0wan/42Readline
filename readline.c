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

