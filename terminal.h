#ifndef TERMINAL_H
# define TERMINAL_H

# define NUM_TC_STRINGS (sizeof(g_tc_strings) / sizeof(struct s_termcaps_string))

struct s_termcaps
{
/* The key sequences output by the arrow keys, if this terminal has any. */
	char	*at7;
	char	*DC;
	char	*clrscroll;
	char	*IC;
	char	*clreol;
	char	*clrpag;
	char	*cr;
	char	*dc;
	char	*ei;
	char	*ic;
	char	*im;
	char	*kD;	/* delete */
	char	*kH;	/* home down ?? */
	char	*kI;	/* insert */
	char	*kd;
	char	*ke;	/* end keypad mode */
	char	*kh;	/* home */
	char	*kl;
	char	*kr;
	char	*ks;	/* start keypad mode */
	char	*ku;
	char	*backspace;
	char	*mm;
	char	*mo;
	char	*forward_char;
	char	*pc;
	char	*up;
	char	*visible_bell;
	char	*vs;
	char	*ve;

};

struct s_termcaps_string
{
	const char *const	var;
	char			**value;
};

/* Variables that hold the screen dimensions, used by the display code. */
struct s_screen
{
	int	width;
	int	height;
	int	chars;
};

struct s_term
{
	char	*terminal_name;
	char	*term_string_buffer;
	char	*term_buffer;
	int	autowrap;
	int	terminal_can_insert;
	int	has_meta;
};

extern struct s_termcaps		g_tc;
extern struct termios			g_termios;
extern struct termios			g_termios_backup;
extern struct s_screen			g_screen;
extern struct s_term			g_term;
extern const struct s_termcaps_string	g_tc_strings[];

#endif
