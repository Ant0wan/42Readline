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
}

/* 1460 update_line in display.c here is the heart of the thing */

//	!!!!!!!!   LAST WORK TO DO !!!!!!!!!

/* PWP: update_line() is based on finding the middle difference of each
   line on the screen; vis:

                             /old first difference
        /beginning of line   |        /old last same       /old EOL
        v                    v        v             v
old:    eddie> Oh, my little gruntle-buggy is to me, as lurgid as
new:    eddie> Oh, my little buggy says to me, as lurgid as
        ^                    ^  ^                          ^
        \beginning of line   |  \new last same     \new end of line
                             \new first difference

   All are character pointers for the sake of speed.  Special cases for
   no differences, as well as for end of line additions must be handled.

   Could be made even smarter, but this works well enough */

void	update_line(int len)
{
	tputs(tgoto(g_termcaps.IC, 0, len), 1, output); /* insertion mode */
//	tputs(tgoto(*(g_tc_strings[30].value), g_line_state_invisible.len, 0), 1, output);
	write(STDOUT_FILENO, &(g_line_state_invisible.line[g_cursor.last_c_pos]), len); //g_line_state_invisible.len);

//	tputs(tgoto(*(g_tc_strings[30].value), g_line_state_visible.len, 0), 1, output);
//	write(STDOUT_FILENO, &(g_line_state_invisible.line[g_cursor.last_c_pos]), g_line_state_invisible.len);
	g_line_state_visible = g_line_state_invisible;
}
