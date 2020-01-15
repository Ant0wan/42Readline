#include "ft_readline.h"

/* Flags encapsulating the current readline state. */
static unsigned long	g_flags_readline_state = 0;
struct s_line		g_line = { .buffer = NULL, .len = 0 };

static void readline_initializer(void)
{
	/* Allocate data structures. */
	if (g_line.buffer == NULL)
	{
		g_line.len = READLINE_DEFAULT_BUFFER_SIZE;
		g_line.buffer = (char*)malloc(g_line.len);
	}
	/* Initialize the terminal interface. */
	if (g_term.terminal_name == NULL)
		g_term.terminal_name = get_env_value("TERM");
	init_terminal_io(g_term.terminal_name); /* HERE IT WAS WORK PROGRESS !!!! readline->readline_init_everything->init_terminal_io*/
}

/* Initialize readline and terminal if not already. */
int		initialize(void)
{
	static int	initialized;

	/* If never been called, init terminal and data structures. */
	if (initialized == 0)
	{
		setstate(STATE_INITIALIZING);
		readline_initializer();
		unsetstate(STATE_INITIALIZING);
		++initialized;
		setstate(STATE_INITIALIZED);
	}
}
