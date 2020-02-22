#include "ft_readline.h"

struct sigaction	g_sigact_winch = {0};
struct sigaction	g_dummy_winch = {0};

/* Block terminal generated signals, save old mask and set shell one */
void	rl_set_signals(void)
{
	/* SIGWINCH set */
	if (g_sigact_winch.sa_handler == NULL)
	{
		sigemptyset(&g_sigact_winch.sa_mask);
		sigaddset(&g_sigact_winch.sa_mask, SIGWINCH);
		g_sigact_winch.sa_flags = SA_RESTART;
		g_sigact_winch.sa_handler = resize_terminal; /* Update sigwinch handler */
	}
	sigaction(SIGWINCH, &g_sigact_winch, &g_dummy_winch);
}

/* Restore proc mask inheritated from the launching proc*/
void	rl_clear_signals(void)
{
	sigaction(SIGWINCH, &g_dummy_winch, NULL);
}
