#include "ft_readline.h"

/* Display variables */
struct s_display	g_display =
{ .prompt = NULL };

static int	redisplay_after_sigwinch(void)
{
	/* Clear the last line (assuming that the screen size change will result in
           either more or fewer characters on that line only) and put the cursor at
           column 0.  Make sure the right thing happens if we have wrapped to a new
           screen line. */

	/* TO DO */
	return (0);
}

int		set_prompt(const char *prompt)
{
	if (g_display.prompt != NULL)
	{
		free(g_display.prompt);
		g_display.prompt = NULL;
	}
}
