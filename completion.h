/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:20:37 by abarthel          #+#    #+#             */
/*   Updated: 2020/03/03 17:20:38 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include <sys/types.h>
# include <dirent.h>

extern t_list	*g_flst;

extern int	g_full_completion;

char	*suggest(void);
void	feed_list(const char *str);
void	free_completion(void);

#endif
