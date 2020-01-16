#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <curses.h>
# include <term.h>
# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>

# include "keymaps.h"

# define NUM_TC_STRINGS (sizeof(g_tc_strings) / sizeof(struct termcaps_string))

struct s_termcaps
{
/* The key sequences output by the arrow keys, if this terminal has any. */
/*	char	*cl;
	char	*cm;
	char	*vi;
	char	*ab;
	char	*reset; */
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

struct termcaps_string
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
extern const struct termcaps_string	*g_tc_strings;

int		get_screensize(int tty);
int		is_interactive(void);
int		reset_terminal(void);

union	u_buffer
{
	unsigned int	value;
	char		buf[sizeof(unsigned int)];
};

int		get_input(void);
int		output(int c);
size_t		len(const char *str);
char		*savestring(const char *str);
char		*get_env_value(const char *name);
int		cmp(const char *s1, const char *s2);
int		rl_toupper(int c);
int		rl_tolower(int c);
int		isoctal(int c);
int		isxdigit(int c);
int		hexvalue(int c);
int		metachar(int c);

# define IM_READLINE (1 << 0)
# define IM_VIM (1 << 1)
# define IM_INSERT (1 << 2)

/* Could be tranformed to union for using mask optimization */
struct s_input
{
	int	mode;                  /* Readline and insert mode ON by default */
	int	last_command_was_kill; /* Non-zero if the previous command was a kill command. */
	int	numeric_arg;           /* The current value of the numeric argument specified by the user. */
	int	explicit_arg;          /* Non-zero if an argument was typed. */
	int	arg_sign;              /* Temporary value used while generating the argument. */
};

extern struct s_input	g_input;

struct s_display
{
	char	*prompt;
	char	*display_prompt;
	int	visible_prompt_length;
};

extern struct s_display	g_display;

# define STATE_INITIALIZING   0x0000001       /* initializing */
# define STATE_INITIALIZED    0x0000002       /* initialization done */
# define STATE_TERMPREPPED    0x0000004       /* terminal is prepped */
# define STATE_READCMD        0x0000008       /* reading a command key */
# define STATE_METANEXT       0x0000010       /* reading input after ESC */
# define STATE_DISPATCHING    0x0000020       /* dispatching to a command */
# define STATE_MOREINPUT      0x0000040       /* reading more input in a command function */
# define STATE_ISEARCH        0x0000080       /* doing incremental search */
# define STATE_NSEARCH        0x0000100       /* doing non-inc search */
# define STATE_SEARCH         0x0000200       /* doing a history search */
# define STATE_NUMERICARG     0x0000400       /* reading numeric argument */
# define STATE_MACROINPUT     0x0000800       /* getting input from a macro */
# define STATE_MACRODEF       0x0001000       /* defining keyboard macro */
# define STATE_OVERWRITE      0x0002000       /* overwrite mode */
# define STATE_COMPLETING     0x0004000       /* doing completion */
# define STATE_SIGHANDLER     0x0008000       /* in readline sighandler */
# define STATE_UNDOING        0x0010000       /* doing an undo */
# define STATE_INPUTPENDING   0x0020000       /* execute_next called */
# define STATE_TTYCSAVED      0x0040000       /* tty special chars saved */
# define STATE_CALLBACK       0x0080000       /* using the callback interface */
# define STATE_VIMOTION       0x0100000       /* reading vi motion arg */
# define STATE_MULTIKEY       0x0200000       /* reading multiple-key command */
# define STATE_VICMDONCE      0x0400000       /* entered vi command mode at least once */
# define STATE_CHARSEARCH     0x0800000       /* vi mode char search */
# define STATE_REDISPLAYING   0x1000000       /* updating terminal display */
# define STATE_DONE           0x2000000       /* done; accepted line */

extern unsigned long   g_flags_readline_state;

void		setstate(unsigned long x);
void		unsetstate(unsigned long x);
unsigned long	isstate(unsigned long x);

# define READLINE_DEFAULT_BUFFER_SIZE 256

struct s_line
{
	char	*buffer;
	size_t	len;
};

extern struct s_line	g_line;

# define control_character_threshold	0x020   /* Smaller than this is control. */
# define control_character_mask		0x1f    /* 0x20 - 1 */
# define meta_character_threshold	0x07f   /* Larger than this is Meta. */
# define control_character_bit		0x40    /* 0x000000, must be off. */
# define meta_character_bit		0x080   /* x0000000, must be on. */
# define largest_char			255     /* Largest character value. */

# define META(c)	((c) | meta_character_bit)
# define CTRL(c)	((c) & control_character_mask)
# define ESC		CTRL('[')
# define NEWLINE	'\n'
# define RETURN		CTRL('M')
# define RUBOUT		0x7f
# define TAB		'\t'

struct s_backslash_convert
{
	int	c;
	int	val;
};

#endif
