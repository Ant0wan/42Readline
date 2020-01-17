#include "ft_readline.h"

/* Display variables */
struct s_display	g_display =
{ .prompt = NULL, .display_prompt = NULL, .visible_prompt_length = 0 };

static int	redisplay_after_sigwinch(void)
{
	/* Clear the last line (assuming that the screen size change will result in
           either more or fewer characters on that line only) and put the cursor at
           column 0.  Make sure the right thing happens if we have wrapped to a new
           screen line. */

	/* TO DO */
	return (0);
}

void		set_prompt(const char *prompt)
{
	if (g_display.prompt != NULL)
		free(g_display.prompt);
	if (prompt)
		g_display.prompt = savestring(prompt);
	else
		g_display.prompt = NULL;
	if (g_display.prompt == NULL)
		g_display.display_prompt = "";
	else
		g_display.display_prompt = g_display.prompt;
	g_display.visible_prompt_length = len(g_display.display_prompt); /* Assume single line prompt and does not handle '\' all chr */
}

/* 1460 update_line in display.c here is the heart of the thing */
