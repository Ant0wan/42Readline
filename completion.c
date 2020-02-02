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

char	*suggest(void)
{
	int	i;
	int	flag;
	char	*word;

	flag = 0;
	i = g_line_state_invisible.len - 1;
	while (i >= 0 && g_line_state_invisible.line[i])
	{
		if (g_line_state_invisible.line[i] == ';'
			|| g_line_state_invisible.line[i] == '&'
			|| g_line_state_invisible.line[i] == '|')
			return (suggest_bin(&(g_line_state_invisible.line[i])));
		while (i >= 0 && g_line_state_invisible.line[i] == ' ')
			--i;
		while (i >= 0 && (g_line_state_invisible.line[i] != ' '
				|| g_line_state_invisible.line[i] != ';'
				|| g_line_state_invisible.line[i] != '&'
				|| g_line_state_invisible.line[i] != '|'))
		{
			if (flag == 1)
				return (suggest_file(&(g_line_state_invisible.line[i])));
			flag = 1;
			--i;
		}
	}
	return (suggest_bin(""));
}
