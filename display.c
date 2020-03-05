/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:20:42 by abarthel          #+#    #+#             */
/*   Updated: 2020/03/05 12:42:40 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/* Display variables */
struct s_display	g_display =
{
	.prompt = NULL,
	.display_prompt = NULL,
	.visible_prompt_length = 0,
	.vis_botlin = 0,
	.cpos_buffer_position = 0,
	.line_size = 1024,
	.visible_first_line_len = 0
};

/* Cursor position */
struct s_cursor		g_cursor =
{ .last_c_pos = 0, .last_v_pos = 0 };

/* Line buffers */
struct s_line_state	g_line_state_visible = {0};
struct s_line_state	g_line_state_invisible = {0};

void		display_prompt(void)
{
	ft_printf("|b%.3dc%.3dv%.3d|> ", g_display.vis_botlin, g_cursor.last_c_pos ,g_cursor.last_v_pos);
//	write(STDOUT_FILENO, g_display.display_prompt, g_display.visible_prompt_length);
}

void		set_prompt(const char *prompt)
{
	if (g_display.prompt != NULL)
		free(g_display.prompt);
	if (prompt)
		g_display.prompt = ft_strdup(prompt);
	else
		g_display.prompt = NULL;
	if (g_display.prompt == NULL)
		g_display.display_prompt = "";
	else
		g_display.display_prompt = g_display.prompt;
	g_display.visible_prompt_length = 16;
//	g_display.visible_prompt_length = ft_strlen(g_display.display_prompt); /* Assume single line prompt and does not handle '\' all chr */
	g_display.visible_first_line_len = g_screen.width - g_display.visible_prompt_length;
}

void	display_lines(void)
{
	int	chr_l;
	int	index;

	chr_l = g_line_state_invisible.len;
	index = 0;
	display_prompt();
	g_display.visible_first_line_len = g_screen.width - g_display.visible_prompt_length;
	/*why writing g_display.visible_first_line_len and not g_line_state_invisible.len ?*/
	write(STDOUT_FILENO, g_line_state_invisible.line, g_display.visible_first_line_len);
	/* Leave newline to autowrap... */
	if (!g_term.autowrap)
	{
		if (g_line_state_invisible.len >= g_display.visible_first_line_len)
			ft_putstr(tgoto(g_termcaps.do1, 0, 0));
	}
	chr_l -= g_display.visible_first_line_len;
	index += g_display.visible_first_line_len;
	while (chr_l > 0)
	{
		if (g_screen.width <= chr_l)
		{
			write(STDOUT_FILENO, &(g_line_state_invisible.line[index]), g_screen.width);
			chr_l -= g_screen.width;
			index += g_screen.width;
	 		if (!g_term.autowrap) /* autowrap */
				ft_putstr(tgoto(g_termcaps.do1, 0, 0));
		}
		else if (chr_l > 0)
		{
			write(STDOUT_FILENO, &(g_line_state_invisible.line[index]), chr_l);
			chr_l = 0;
		}
	}
	if ((g_display.visible_prompt_length + g_line_state_invisible.len) % g_screen.width == 0)
	 	ft_putstr(tgoto(g_termcaps.do1, 0, 0));
}

void	update_line(void)
{
	ft_putstr(tgoto(g_termcaps.ch, 0, 0));
	if (g_cursor.last_v_pos > 0)
		ft_putstr(tgoto(g_termcaps.UP, 0, g_cursor.last_v_pos));
	ft_putstr(g_termcaps.cd);

	g_display.vis_botlin = (g_display.visible_prompt_length + g_line_state_invisible.len) / g_screen.width;
	g_cursor.last_c_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) % g_screen.width;
	g_cursor.last_v_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) / g_screen.width;

	display_lines();


	ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
	if (g_display.vis_botlin - g_cursor.last_v_pos)
		ft_putstr(tgoto(g_termcaps.UP, 0, g_display.vis_botlin - g_cursor.last_v_pos));
}

int		redisplay_after_sigwinch(void)
{
	/* Clear the last line (assuming that the screen size change will result in
           either more or fewer characters on that line only) and put the cursor at
           column 0.  Make sure the right thing happens if we have wrapped to a new
           screen line. */
	/* TO DO */
	g_display.visible_first_line_len = g_screen.width - g_display.visible_prompt_length;

	g_cursor.last_c_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) % g_screen.width;
	g_cursor.last_v_pos = (g_display.visible_prompt_length + g_display.cpos_buffer_position) / g_screen.width;
	g_display.vis_botlin = (g_display.visible_prompt_length + g_line_state_invisible.len) / g_screen.width;

	ft_putstr(tgoto(g_termcaps.ch, 0, 0));
	if (g_cursor.last_v_pos > 0)
		ft_putstr(tgoto(g_termcaps.UP, 0, g_cursor.last_v_pos));
	ft_putstr(g_termcaps.cd);

	display_lines();

	ft_putstr(tgoto(g_termcaps.ch, 0, g_cursor.last_c_pos));
	if (g_display.vis_botlin - g_cursor.last_v_pos)
		ft_putstr(tgoto(g_termcaps.UP, 0, g_display.vis_botlin - g_cursor.last_v_pos));
	return (0);
}
