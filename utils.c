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

char	*get_env_value(const char *name)
{
	extern char **environ;
	int			i;
	int			j;

	if (name)
	{
		i = 0;
		while (environ[i])
		{
			j = 0;
			while (name[j] && environ[i][j] && name[j] == environ[i][j])
				++j;
			if (environ[i][j] != '=' || name[j])
				++i;
			else
			{
				++j;
				return (&environ[i][j]);
			}
		}
	}
	return (NULL);
}

int	cmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		rl_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c ^ (1 << 5));
	return (c);
}

int		rl_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c | (1 << 5));
	return (c);
}

int		isoctal(int c)
{
	return (c >= '0' && c <= '7');
}

int		isxdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int		hexvalue(int c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && (c) <= 'F')
		return (c - 'A' + 10);
	else
		return (c - '0');
}

int	metachar(int c)
{
	return (c > meta_character_threshold && c <= largest_char);
}
