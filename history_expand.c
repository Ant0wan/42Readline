/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:26:29 by snunes            #+#    #+#             */
/*   Updated: 2020/03/02 19:40:57 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static char	g_hist_word_delim[] = " \t\n;&()|<>";
static int	g_hist_expand_start = 0;
static int	g_hist_expand_end = 0;

char	*hist_expanse(char *value)
{
	int i;

	i = 0;
	while (value && value[i])
	{
		g_hist_expand_start = 0;
		g_hist_expand_end = 0;
		if (value[i] == '!')
		{
			g_hist_expand_start = i;
			g_hist_expand_end = i;
			while (value[g_hist_expand_end] \
					&& !ft_strchr(g_hist_word_delim, value[g_hist_expand_end]))
				g_hist_expand_end++;
			if (g_hist_expand_end > g_hist_expand_start + 1)
				value = get_expanded_value(value);
			ft_printf("i bef: %d\n", i);
			if (value && !ft_strchr(g_hist_word_delim, value[i + 1]))
				i += ft_strlen(g_hist->history_content + g_hist->offset + 1);
			if (g_hist->nb_line == 0)
				i++;
		}
		else
			i++;
		ft_printf("i: %d\n", i);
	}
	if (!value)
	{
		g_hist->nb_line = g_hist->total_lines;
		g_hist->offset = g_hist->used -1;
	}
	else if (g_hist_expand_end)
		ft_printf("\n%s\n", value);
	return (value);
}

char	*get_expanded_value(char *value)
{
	int	start;
	int	sign;

	start = g_hist_expand_start;
	start++;
	if (!value[start])
		return (value);
	if (value[start] == '!')
		return (hist_expand_nbr(value, start, -1));
	if (value[start] == '-')
	{
		start++;
		sign = -1;
	}
	else
		sign = 1;
	if (ft_isdigit(value[start]))
		return (hist_expand_nbr(value, start, sign));
	else if (ft_isalpha(value[start]))
		return (hist_expand_word(value, start));
	return (value);
}

char	*hist_expand_nbr(char *value, int start, int sign)
{
	char	*hist_entry;
	int		save;
	int		entry;

	if (value[start] == '!' && g_hist->total_lines > 1)
	{
		prev_hist();
		return (insert_hist_exp(value, g_hist->history_content + g_hist->offset + 1));
	}
	save = value[g_hist_expand_end];
	value[g_hist_expand_end] = '\0';
	entry = ft_atoi(value + start);
	if (sign < 0)
		entry = g_hist->nb_line - entry;
	if (entry > g_hist->total_lines || entry <= 0 || g_hist->total_lines <= 1)
	{
		ft_dprintf(STDERR_FILENO, "\n./21sh: %s: event not found\n", value + \
				g_hist_expand_start);
		free(value);
		return (NULL);
	}
	value[g_hist_expand_end] = save;
	while (entry > g_hist->nb_line)
		hist_entry = next_hist();
	while (entry < g_hist->nb_line)
		hist_entry = prev_hist();
	return (insert_hist_exp(value, hist_entry));
}

char	*hist_expand_word(char *value, int start)
{
	char	*word;
	int		entry;
	int		save;
	int		len;

	save = value[g_hist_expand_end];
	value[g_hist_expand_end] = '\0';
	word = value + start;
	len = ft_strlen(word);
	while (g_hist->nb_line && ft_strncmp(word, g_hist->history_content + \
				g_hist->offset + 1, len))
		prev_hist();
	if (ft_strncmp(word, g_hist->history_content + g_hist->offset + 1, len))
	{
		ft_dprintf(STDERR_FILENO, "\n./21sh: %s: event not found\n", value \
				+ g_hist_expand_start);
		free(value);
		return (NULL);
	}
	value[g_hist_expand_end] = save;
	return (insert_hist_exp(value, g_hist->history_content + g_hist->offset + 1));
}

char	*insert_hist_exp(char *value, char *hist_entry)
{
	char	*new_value;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(value) + (g_hist_expand_start - g_hist_expand_end) + \
		   ft_strlen(hist_entry) + 1;
	if (!(new_value = (char *)ft_memalloc(sizeof(char) * (size))))
	{
		ft_printf("\n./21sh: cannot allocate memory\n");
		return (NULL);
	}
	while (value[i] && i < g_hist_expand_start)
	{
		new_value[i] = value[i];
		i++;
	}
	while (value[i] && hist_entry[j])
	{
		new_value[i + j] = hist_entry[j];
		j++;
	}
	i = 0;
	while (value[g_hist_expand_end + i])
	{
		new_value[i + j] = value[g_hist_expand_end + i];
		i++;
	}
	free(value);
	return (new_value);
}
