#include "ft_readline.h"

char	*suggest_bin(void)
{
	return (NULL);
}

char	*sugget_file()
{
	return (NULL);
}

char	*suggest(void)
{
	int	i;
	char	*word;

	i = g_line_state_invisible.len - 1;
	while (i >= 0)
	{
		if (g_line_state_invisible.line[i] == ' ')
			--i;
		else if (isalnum(g_line_state_invisible.line[i]) == ';'
				|| isalnum(g_line_state_invisible.line[i]) == '&'
				|| isalnum(g_line_state_invisible.line[i]) == '|')
		{
			suggest_bin();
		}
		else if (isalnum(g_line_state_invisible.line[i]))
		{
			while (i > 0
				&& isalnum(g_line_state_invisible.line[i])
				&& isalnum(g_line_state_invisible.line[i]) != ';'
				&& isalnum(g_line_state_invisible.line[i]) != '&'
				&& isalnum(g_line_state_invisible.line[i]) != '|')
				--i;
			if (i != 0 || !isalnum(g_line_state_invisible.line[i])
					|| isalnum(g_line_state_invisible.line[i]) == ';'
					|| isalnum(g_line_state_invisible.line[i]) == '&'
					|| isalnum(g_line_state_invisible.line[i]) == '|')
				++i;
			return (suggest_file(&(g_line_state_invisible.line[i])));
		}
	}
	return (NULL);
}
