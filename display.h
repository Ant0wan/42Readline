#ifndef DISPLAY_H
# define DISPLAY_H

struct s_display
{
	char	*prompt;
	char	*display_prompt;
	int	visible_prompt_length;
};

extern struct s_display	g_display;

void	set_prompt(const char *prompt);

#endif
