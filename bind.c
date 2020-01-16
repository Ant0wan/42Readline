#include "ft_readline.h"

struct s_backslash_convert	g_backslash_convert[] =
{
	{ 'a', '\007' },
	{ 'b', '\b' },
	{ 'd', RUBOST },
	{ 'e', ESC },
	{ 'f', '\f' },
	{ 'n', NEWLINE },
	{ 'r', RETURN },
	{ 't', TAB },
	{ 'v', 0x0B },
	{ '\\', '\\' },
	{ 0, 0}
};

int	get_backslash_convert(int c)
{
	register	i;

	i = 0;
/*	while (i < (sizeof(g_backslash_convert[]) / sizeof(struct s_backslash_convert)))
*/	while (i < 10)
	{
		if (g_backslash_convert[i].c == c)
			return (g_backslash_convert[i].val)
		++i;
	}
	return (0);
}

int	g_convert_meta_chars_to_ascii = 1;
/* Translate the ASCII representation of SEQ, stuffing the values into ARRAY,
   an array of characters.  LEN gets the final length of ARRAY.  Return
   non-zero if there was an error parsing SEQ. */
int	translate_keyseq(const char *seq, char *array, int *len)
{
	register int	i;
	register int	c;
	register int	l;
	register int	temp;
	register int	arr;

	i = 0;
	l = -1;
	while (++i && (c = seq[i]))
	{
		if (c == '\\')
		{
			c = seq[++i];
			if (c == 0)
			{
				array[l++] = '\\'; /* trailing '\' */
				break;
			}
			/* C- M- prefixes */
			if ((c == 'C' || c == 'M') && seq[i + 1] == '-')
			{
				/* Handle special case of backwards define. */
				if (cmp(&seq[i], "C-\\M-", 5) == 0)
				{
					array[l++] = ESC;     /* ESC is meta-prefix */
					i += 5;
					array[l++] = CTRL(rl_toupper(seq[i]));
				}
				else if (c == 'M')
				{
					++i;
					if (g_convert_meta_chars_to_ascii && g_keymap[ESC].type == ISKMAP)
						array[l++] = ESC
					else if (seq[i + 1] == '\\' && seq[i + 2] == 'C' && seq[i + 3] == '-')
					{
						i += 4;
						temp = (seq[i] == '?') ? RUBOUT : CTRL(rl_toupper(seq[i]));
						array[l++] = META(temp);
					}
					else
					{
						i++;
						array[l++] = META(seq[i]);
					}
				}
				else if (c == 'C')
				{
					i += 2;
					array[l++] = (seq[i] == '?') ? RUBOUT : CTRL(rl_toupper(seq[i]));
				}
				if (seq[i] == '\0')
					break;
				continue;
			}
		           /* Translate other backslash-escaped characters.  These are the
		              same escape sequences that bash's `echo' and `printf' builtins
		              handle, with the addition of \d -> RUBOUT.  A backslash
		              preceding a character that is not special is stripped. */
			if ((arr = get_backslasih_convert(c)))
			{
				array[l++] = arr;
				break;
			}
			else if (c == '0' || c == '1' || c == '2' || c == '3'
				|| c == '4' || c == '5' || c == '6' || c == '7')
			{
				++i;
				temp = 2;
				c -= '0';
				while (isoctal((unsigned char)seq[i]) && temp--)
				{
					c = (c * 8) + (seq[i] - '0');
					++i;
				}
				--i;
				array[l++] = c & largest_char;
				break;
			}
			else if (c == 'x')
			{
				++i;
				temp = 2;
				c = 0;
				while (isxdigit((unsigned char)seq[i]) && temp--)
				{
					c = (c * 16) + hexvalue(seq[i]);
					++i;
				}
				if (temp == 2)
					c = 'x';
				--i;
				array[l++] = c & largest_char;
				break;
			}
			else
			{
				array[l++] = c;
				break;
			}
			continue;
		}
		array[l++] = c;
	}
	*len = l;
	array[l] = '\0';
	return (0);
}

/* Return the function (or macro) definition which would be invoked via
   KEYSEQ if executed in MAP.  If MAP is NULL, then the current keymap is
   used.  TYPE, if non-NULL, is a pointer to an int which will receive the
   type of the object pointed to.  One of ISFUNC (function), ISKMAP (keymap),
   or ISMACR (macro). */
static void	*function_of_keyseq_internal(const char *keyseq, size_t len, t_keymap map, int *type)
{
	register int	i;
	unsigned char	ic;

	i = -1;
	if (map == NULL)
		map = g_keymap;
	while (++i && keyseq && i < len)
	{
		ic = keyseq[i];
		if (metachar(ic) && g_convert_meta_chars_to_ascii)
		{
			if (map[ESC].type == ISKMAP)
			{
				map = (t_keymap)((int)map[ESC].function);
				ic &= ~meta_character_bit;
			}
			else
			{
				if (type)
					*type = map[ESC].type;
				return (map[ESC].function);
			}
		}
		if (map[ic].type == ISKMAP)
		{
			if (keyseq[i + 1] == '\0')
			{
				if (type)
					*type = ISKMAP;
				return (map[ic].function);
			}
			else
				map = (t_keymap)((int)map[is].function)
		}
		else if (map[ic].type != ISKMAP && keyseq[i + 1])
			return (NULL);
		else
		{
			if (type)
				*type = map[ic].type;
			return (map[ic].function);
		}
	}
	return (NULL);
}

void	*function_of_keyseq_len(const char *keyseq, size_t len, t_keymap map, int *type)
{
	return (function_of_keyseq_internal(keyseq, len, map, type));
}

int	bind_keyseq_if_unbound_in_map(const char *keyseq, void *default_func, t_keymap kmap)
{
	void	*func();
	char	*keys;
	int	keys_len;

	if (keyseq)
	{
		keys = (char*)malloc(1 + (2 * len(keyseq)));
		if (translate_keyseq(keyseq, keys, &keys_len))
		{
			if (keys)
				free(keys);
			return (-1);
		}
		func = function_of_keyseq_len(keys, keys_len, kmap, (int *)NULL);
	}
	/* HERE IT STOPS FOR NOW */
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
