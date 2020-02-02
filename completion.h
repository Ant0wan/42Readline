#ifndef COMPLETION_H
# define COMPLETION_H

# include <sys/types.h>
# include <dirent.h>

struct s_file_lst
{
	char			*str;
	struct s_file_lst	*next;
};

extern struct s_file_lst	*g_flst;

char	*suggest(void);
void	feed_list(const char *str);

#endif
