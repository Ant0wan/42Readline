#include "ft_readline.h"

static int	g_prop_len = 0;

static char	*suggest_bin(const char *beg_s)
{
	char	*bin;

	bin = ft_strdup("command");
	return (bin);
}

static int	common_len(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return (i);
}

static char	*get_filename(const char *str, int len)
{
	struct s_file_lst	*ptr;
	struct s_file_lst	*nptr;

	ptr = g_flst;
	while (ptr)
	{
		if (!ft_strncmp(str, ptr->str, len))
		{
			g_prop_len = 0;
			nptr = ptr->next;
			while (nptr)
			{
				if (!ft_strncmp(str, nptr->str, len))
				{
					g_prop_len = common_len(ptr->str, nptr->str) /*common len btw ptr->str & nptr->str*/;
					break;
				}
				nptr = nptr->next;
			}
			return (&(ptr->str[len]));
		}
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
//	printf("\n%d\n", g_prop_len - 1);
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
