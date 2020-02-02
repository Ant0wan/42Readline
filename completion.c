#include "ft_readline.h"

char	*suggest_bin(const char *beg_s)
{
	char	*bin;

	bin = savestring("command");
	return (bin);
}

char	*sugget_file(const char *beg_s)
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
	while (i >= 0)
	{
		if (i == 0 || g_line_state_invisible.line[i] == ';'
			|| g_line_state_invisible.line[i] == '&'
			|| g_line_state_invisible.line[i] == '|')
		{
			return (suggest_bin(&(g_line_state_invisible.line[i])));
		}
		while (i >= 0 && g_line_state_invisible.line[i] == ' ')
			--i;
		while (i >= 0 && isalnum(g_line_state_invisible.line[i]))
		{
			if (flag == 1)
				return (suggest_file(&(g_line_state_invisible.line[i])));
			--i;
		}
		flag = 1;
	}
	return (NULL);
}
