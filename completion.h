#ifndef COMPLETION_H
# define COMPLETION_H

# include <sys/types.h>
# include <dirent.h>

extern t_list	*g_flst;

char	*suggest(void);
void	feed_list(const char *str);
void	free_completion(void);

#endif
