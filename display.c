#include "ft_readline.h"

/* Display variables */
struct s_display	g_display =
{
	.prompt = NULL,
	.display_prompt = NULL,
	.visible_prompt_length = 0,
	.vis_botlin = 0,
	.cpos_buffer_position = 0,
	.line_size = 1024,
	.visible_first_line_len = 0
};

/* Cursor position */
struct s_cursor		g_cursor =
{ .last_c_pos = 0, .last_v_pos = 0 };

/* Line buffers */
struct s_line_state	g_line_state_visible = {0};
struct s_line_state	g_line_state_invisible = {0};

extern struct s_termcaps g_termcaps;

void		display_prompt(void)
{
	write(STDOUT_FILENO, g_display.display_prompt, g_display.visible_prompt_length);
}

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
	g_display.visible_first_line_len = g_screen.width - g_display.visible_prompt_length;
}

void	display_lines(void)
{
	int	chr_l;
	int	index;

	chr_l = g_line_state_invisible.len;
	index = 0;
	display_prompt();
	g_display.visible_first_line_len = g_screen.width - g_display.visible_prompt_length;
	write(STDOUT_FILENO, g_line_state_invisible.line, g_display.visible_first_line_len);
	if (g_line_state_invisible.len >= g_display.visible_first_line_len)
		write(STDOUT_FILENO, "\n", 1);
	chr_l -= g_display.visible_first_line_len;
	index += g_display.visible_first_line_len;
	while (chr_l > 0)
	{
		if (g_screen.width <= chr_l)
		{
			write(STDOUT_FILENO, &(g_line_state_invisible.line[index]), g_screen.width);
			chr_l -= g_screen.width;
			index += g_screen.width;
			write(STDOUT_FILENO, "\n", 1);
		}
		else if (chr_l > 0)
		{
			write(STDOUT_FILENO, &(g_line_state_invisible.line[index]), chr_l);
			chr_l = 0;
		}
	}
}

void	update_line(void)
{


	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, output);
	if (g_cursor.last_v_pos > 0)
		tputs(tgoto(tgetstr("UP", NULL), 0, g_cursor.last_v_pos), 1, output);
	tputs(tgetstr("cd", NULL), 1, output);

	g_cursor.last_c_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) % g_screen.width;
	g_cursor.last_v_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) / g_screen.width;
	g_display.vis_botlin = (g_display.visible_prompt_length + g_line_state_invisible.len) / g_screen.width;

	display_lines();

	tputs(tgoto(tgetstr("ch", NULL), 0, g_cursor.last_c_pos), 1, output);
	if (g_display.vis_botlin - g_cursor.last_v_pos)
		tputs(tgoto(tgetstr("UP", NULL), 0, g_display.vis_botlin - g_cursor.last_v_pos), 1, output);
}
