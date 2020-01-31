#include "ft_readline.h"

char	*suggest_bin(void)
{
	return (NULL);
}

char	*sugget_file(void)
{
	return (NULL);
}

char	*suggest(void)
{
	int	i;
	char	*word;

	i = g_line_state_invisible.len - 1;
	if (i >= 0 && g_line_state_invisible.line[i] == 'l')
		return (rl_strdup("s"));
	else
		return (NULL);
}
