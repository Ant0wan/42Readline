#ifndef HISTORY_H
# define HISTORY_H

struct s_hist
{
	int		n;
	char		*str;
	struct s_hist	*next;
	struct s_hist	*prev;
};

extern struct s_hist	*g_hist;

void	add_hentry(const char *str);
char	*prev_hist(void);
char	*next_hist(void);
void	free_hist(void);

#endif
