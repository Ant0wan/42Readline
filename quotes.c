#include "ft_readline.h"

struct s_quote	g_quote =
{
	.c = 0,
	.no_quote_prompt = "> ",
	.no_quote_prompt_len = 2,
	.handle = 1,
};

int	is_quote_open(const char *s)
{
	int	on;

	if (g_quote.handle != 1) /* For heredoc case */
		return (0);
	while (*s)
	{
		if (g_quote.c == 0 && (*s == '\"' || *s == '\'' || *s == '`'))
			g_quote.c = *s;
		else if (*s && *s == g_quote.c)
			g_quote.c = 0;
		++s;
	}
	if (g_quote.c)
	{
		g_quote.c = 0;
		return (1);
	}
	else
		return (0);
}
