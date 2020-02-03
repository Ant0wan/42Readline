#include "ft_readline.h"

t_list	*g_flst = NULL;

void	free_completion(void)
{
	t_list	*ptr;

	while (g_flst)
	{
		ptr = g_flst->next;
		free(g_flst->content);
		free(g_flst);
		g_flst = ptr;
	}
}

void	store_dirl(const char *e)
{
	t_list	*ptr;

	ptr = g_flst;
	if (ptr == NULL)
	{
		g_flst = (t_list*)malloc(sizeof(t_list));
		ft_bzero(g_flst, sizeof(t_list));
		g_flst->content = (void*)ft_strdup(e);
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_list*)malloc(sizeof(t_list));
		ft_bzero(ptr->next, sizeof(t_list));
		ptr->next->content = (void*)ft_strdup(e);
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
		if (ft_strcmp(ret->d_name, ".") && ft_strcmp(ret->d_name, ".."))
			store_dirl(ret->d_name);
	}
	ft_lstquicksort(&g_flst, (int (*)(void*, void*))ft_strcmp);
	closedir(dir);
}
