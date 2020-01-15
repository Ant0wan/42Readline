#include "ft_readline.h"

int	output(int c)
{
	if (write(STDOUT_FILENO, &c, sizeof(int)) != sizeof(int))
		return (0);
	return (1);
}

size_t	len(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*savestring(const char *str)
{
	size_t	count;
	char	*save;

	save = (char*)malloc(sizeof(char) * (len(str) + 1));
	count = 0;
	while (str[count])
	{
		save[count] = str[count];
		++count;
	}
	save[count] = '\0';
	return (save);
}
