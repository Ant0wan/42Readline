#include "ft_readline.h"

static char	*suggest_bin(const char *beg_s)
{
	char	*bin;

	bin = savestring("command");
	return (bin);
}

static char	*suggest_file(const char *beg_s)
{
	char *file;

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

	i = g_display.cpos_buffer_position;
	if (i == 0)
		return (suggest_bin(""));
	while (i > 0)
	{
		if (g_line_state_invisible.line[i] == ';'
			|| g_line_state_invisible.line[i] == '&'
			|| g_line_state_invisible.line[i] == '|')
			break;
		--i;
	}
//	write(STDOUT_FILENO, &(g_line_state_invisible.line[i]), &(g_line_state_invisible.line[g_display.cpos_buffer_position]) - &(g_line_state_invisible.line[i]));
//	printf("\n\n%s\n\n", &(g_line_state_invisible.line[i]));
	printf("\n%d\n", count_word(i));
	return (suggest_bin(""));
}
