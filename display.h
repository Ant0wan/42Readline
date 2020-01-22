#ifndef DISPLAY_H
# define DISPLAY_H

/* Display variables */
struct s_display
{
	char	*prompt;                /* Pointer to passed prompt */
	char	*display_prompt;        /* String containing prompt to display */
	int	visible_prompt_length;  /* Length of visible prompt */
	int	vis_botlin;             /* Number of physical lines consumed by the current line buffer currently */
	int	cpos_buffer_position;   /* The index into the line buffer corresponding to the cursor position */
	int	line_size;              /* Default and initial buffer size. Can grow. */
	int	visible_first_line_len; /* The length (buffer offset) of the first line of the last (possibly multi-line) buffer displayed on the screen. */

};

/* State of visible and invisible lines. */
struct s_line_state
{
	char	*line;
	int	size_buf;
	int	len;
//	int	*lbreaks;
//	int	lbsize;
//	int	wbsize;
//	int	*wrapped_line;
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
void	update_line(void);

#endif
