#include "ft_readline.h"

static int	braclose(char *str, char c, int i, int b)
{
	while (b && *(++str) && (i++))
		if (*str == c || *str == c + c % 2 + 1)
			*str == c ? ++b : --b;
	return (i);
}

static int	brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == '\"' || *str == '\'' || *str == '`')
		return (0);
	else if (*str == '(' || *str == '{' || *str == '\"' || *str == '\'' || *str == '`')
		return (brackets(str + 1, *str + *str % 2 + 1)
			* brackets(str + braclose(str, *str, 1, 1), c));
	else
		return (brackets(str + 1, c));
}

int	is_quote_open(char *av)
{
	return (brackets(av, 0));
}
