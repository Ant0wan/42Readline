#include "ft_readline.h"

static char	*suggest_bin(const char *beg_s)
{
	char	*bin;

	bin = ft_strdup("command");
	return (bin);
}

static char	*get_filename(const char *str, int len)
{
	t_list	*ptr;

	ptr = g_flst;
	while (ptr)
	{
		if (!ft_strncmp(str, ptr->content, len))
			return (&(((char*)(ptr->content))[len]));
		ptr = ptr->next;
	}
	return (NULL);
}

static char	*suggest_file(const char *beg_s)
{
	char	*file;
	int	i;

	i = g_display.cpos_buffer_position - 1;
	while (i > 0 && (g_line_state_invisible.line[i] != '|'
				&& g_line_state_invisible.line[i] != ';'
				&& g_line_state_invisible.line[i] != '&'
				&& g_line_state_invisible.line[i] != ' '))
		--i;
	if ((g_line_state_invisible.line[i] == '|'
				|| g_line_state_invisible.line[i] == ';'
				|| g_line_state_invisible.line[i] == '&'
				|| g_line_state_invisible.line[i] == ' '))
		++i;
	feed_list("."); // should be PWD
	/* INSERT here the function to get the filename using strncmp */
	file = get_filename(&(g_line_state_invisible.line[i]), g_display.cpos_buffer_position - i);
//	printf("\n%s\n", &(g_line_state_invisible.line[i]));
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
