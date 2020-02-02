#include "ft_readline.h"

static char	*suggest_bin(const char *beg_s)
{
	char	*bin;

	bin = savestring("command");
	return (bin);
}

static char	*suggest_file(const char *beg_s)
{
//	DIR	dir;
	char	*file;

//	dir = opendir("."); should open dir each time change with cd, and close at cd or shutting the shell
//	At cd, dir should be stored in a sorted list (it is like doing a "ls" at each cd or running bash)
	file = savestring("file.c");
	return (file);
}

static int	count_word(int i)
{
	int	c;
	int	b;

	c = 0;
	while (g_line_state_invisible.line[i] && i < g_display.cpos_buffer_position)
	{
		b = 0;
		while (g_line_state_invisible.line[i] == ' ')
			++i;
		while (g_line_state_invisible.line[i] && g_line_state_invisible.line[i] != ' ')
		{
			if (g_line_state_invisible.line[i] == '|'
				|| g_line_state_invisible.line[i] == ';'
				|| g_line_state_invisible.line[i] == '&')
				c = 0;
			b |= 1;
			++i;
		}
		if (b)
			++c;
	}
//	printf("\n\n|%c|%d\n\n", g_line_state_invisible.line[g_display.cpos_buffer_position - 1], c);
	if (g_line_state_invisible.line[g_display.cpos_buffer_position - 1] != ' ')
		return (c - 1);
	else
		return (c);
}

char	*suggest(void)
{
	int	i;
	int	count;

	i = g_display.cpos_buffer_position;
	if (i == 0)
		return (suggest_bin(""));
	while (i > 0)
	{
		if (g_line_state_invisible.line[i] == ';'
			|| g_line_state_invisible.line[i] == '&'
			|| g_line_state_invisible.line[i] == '|')
		{
			++i;
			break;
		}
		--i;
	}
	count = count_word(i);
	if (count > 0)
		return (suggest_file(""));
	return (suggest_bin(""));
}
