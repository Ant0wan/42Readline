/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:22:13 by abarthel          #+#    #+#             */
/*   Updated: 2020/03/03 17:22:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/* For test purpose uniquely */

int	main(int argc, char **argv)
{
	char		*input;
	char		*compl;
	char		*tmp;
	char		*new;

	(void)argc;
	(void)argv;
	//input = ft_readline((char *)NULL);
	while ((input = ft_readline("$> ")))
	{
		printf("\nre:%s\n\n", tmp);
		if (!ft_strcmp(input, "exit"))
		{
			free(input);
			break;
		}
		free(input);
		free_completion();
		free(g_original_cmd);
		g_original_cmd = NULL;
	}
	if (g_clip.str != NULL)
		free(g_clip.str);
	free_hist();
	return (0);
}
