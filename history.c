#include "ft_readline.h"

struct s_hist	*g_hist = NULL;
char		*g_vline = NULL;

void	add_hentry(const char *str)
{
	if (g_vline)
	{
		free(g_vline);
		g_vline = NULL;
	}
	while (g_hist && g_hist->next)
		g_hist = g_hist->next;
	if (g_hist == NULL)
	{
		g_hist = (struct s_hist*)malloc(sizeof(struct s_hist));
		rl_bzero(g_hist, sizeof(struct s_hist));
		g_hist->n = 0;
		g_hist->str = savestring(str);
	}
	else
	{
		g_hist->next = (struct s_hist*)malloc(sizeof(struct s_hist));
		rl_bzero(g_hist->next, sizeof(struct s_hist));
		g_hist->next->prev = g_hist;
		g_hist->next->n = g_hist->n + 1;
		g_hist->next->str = savestring(str);
		g_hist = g_hist->next;
	}
}

char	*prev_hist(void)
{
	if (g_vline == NULL)
		g_vline = savestring(g_line_state_invisible.line);
	if (g_hist)
	{
		if (g_hist->prev)
		{
			g_hist = g_hist->prev;
			return (g_hist->next->str);
		}
		return (g_hist->str);
	}
}

char	*next_hist(void)
{
	if (g_hist)
	{
		if (g_hist->next)
		{
			g_hist = g_hist->next;
			return (g_hist->prev->str);
		}
		else
		{
			if (g_vline)
			{
				free(g_vline);
				g_vline = NULL;
			}
			return (g_vline);
		}
	}
}

void	free_hist(void)
{
	struct s_hist	*prev;

	while (g_hist && g_hist->next) /* In case */
		g_hist = g_hist->next;
	while (g_hist)
	{
		free(g_hist->str);
		prev = g_hist->prev;
		free(g_hist);
		g_hist = prev;
	}
}
