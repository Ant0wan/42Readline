#include "ft_readline.h"

struct s_file_lst	*g_flst = NULL;

void	store_dirl(const char *e)
{
	struct s_file_lst	*ptr;

	ptr = g_flst;
	if (ptr == NULL)
	{
		g_flst = (struct s_file_lst*)malloc(sizeof(struct s_file_lst));
		rl_bzero(g_flst, sizeof(struct s_file_lst));
		g_flst->str = savestring(e);
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (struct s_file_lst*)malloc(sizeof(struct s_file_lst));
		rl_bzero(ptr->next, sizeof(struct s_file_lst));
		ptr->next->str = savestring(e);
	}
	return;
}

void	feed_list(const char *str)
{
	DIR	*dir;
	struct dirent *ret;

	dir = opendir(str);
	while ((ret = readdir(dir)))
	{
		if (strcmp(ret->d_name, ".") && strcmp(ret->d_name, ".."))
			store_dirl(ret->d_name);
	}
}
