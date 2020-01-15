#include "ft_readline.h"

/* Translate the ASCII representation of SEQ, stuffing the values into ARRAY,
   an array of characters.  LEN gets the final length of ARRAY.  Return
   non-zero if there was an error parsing SEQ. */
int	translate_keyseq(const char *seq, char *array, int *len)
{
	
}

int	bind_keyseq_if_unbound_in_map(const char *keyseq, void *default_func, t_keymap kmap)
{
	void	*func();
	char	*keys;
	int	keys_len;

	if (keyseq)
	{
		keys = (char*)malloc(1 + (2 * len(keyseq)));
		if (rl_translate_keyseq(keyseq, keys, &keys_len))
		{
			if (keys)
				free(keys);
			return (-1);
		}
		func = rl_function_of_keyseq_len(keys, keys_len, kmap, (int *)NULL);
	}
}

int	bind_keyseq_if_unbound(const char *keyseq, void	*default_func)
{
	return (bind_keyseq_if_unbound_in_map(keyseq, default_func, g_keymap));
}

/* Bind the arrow key sequences from the termcap description in MAP. */
void	bind_termcap_arrow_keys(t_keymap map)
{
	t_keymap	xkeymap;

	xkeymap = g_keymap;
	g_keymap = map;
	bind_keyseq_if_unbound(g_term.ku, rl_get_previous_history);
	bind_keyseq_if_unbound(g_term.kd, rl_get_next_history);
	bind_keyseq_if_unbound(g_term.kr, rl_forward_char);
	bind_keyseq_if_unbound(g_term.kl, rl_backward_char);
	bind_keyseq_if_unbound(g_term.kh, rl_beg_of_line);      /* Home */
	bind_keyseq_if_unbound(g_term.at7, rl_end_of_line);     /* End */
	bind_keyseq_if_unbound(g_term.kD, rl_delete);
	bind_keyseq_if_unbound(g_term.kI, rl_overwrite_mode);   /* Insert */
	g_keymap = xkeymap;
}
