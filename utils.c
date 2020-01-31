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

int	ismetachar(union u_buffer c)
{
	return (c.buf[0] == 27 && c.buf[1] != 0);
}

int	isprintchr(int c)
{
	return (c >= 32 && c <= 126);
}

int	isstdkey(int c)
{
	return (c > 0 && c <= 127);
}

int	isctrlkey(union u_buffer c)
{
	return (c.buf[0] == 27 && c.buf[1] == 91);
}

int	mvctrlkey(union u_buffer c)
{
	return (c.buf[2] == 49 && c.buf[3] == 59 && c.buf[4] == 53);
}

int	enter_rc(union u_buffer c)
{
	return (c.buf[0] == 13 && c.buf[1] == 0);
}

void	rl_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr++ = 0;
		--n;
	}
}

char	*rl_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < len)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}

void	*rl_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			--i;
			p_dst[i] = p_src[i];
		}
	}
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			++i;
		}
	}
	return (dst);
}

char	*rl_sjoin(char const *s1, char const *s2)
{
	char	*cpy;

	cpy = NULL;
	if (s1 && s2)
		cpy = (char*)malloc(sizeof(*cpy) * (len(s1) + len(s2)) + 1);
	if (!s1 || !s2 || !cpy)
		return (NULL);
	cpy = strcpy(cpy, s1);
	cpy = strcat(cpy, s2);
	return (cpy);
}

char	*rl_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char*)malloc(sizeof(*s2) * len(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}

