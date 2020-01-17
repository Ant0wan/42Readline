#ifndef DISPLAY_H
# define DISPLAY_H

struct s_display
{
	char	*prompt;
	char	*display_prompt;
	int	visible_prompt_length;
};

/* State of visible and invisible lines. */
struct s_line_state
{
	char	*line;
	int	*lbreaks;
	int	lbsize;
	int	wbsize;
	int	*wrapped_line;
};

/* The visible cursor position. Adjuted when text is printed. */
struct s_cursor
{
	int	last_c_pos;
	int	last_v_pos;
};

/* The line display buffers.
   One is the line currently displayed on the screen.
   The other is the line about to be displayed. */
extern struct s_line_state	g_line_state_visible;
extern struct s_line_state	g_line_state_invisible;

extern struct s_display		g_display;
extern struct s_cursor		g_cursor;

void	set_prompt(const char *prompt);

#endif
