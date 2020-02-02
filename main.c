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
	while (input = ft_readline("$> "))
	{
		tmp = rl_strdup(input);
		while (is_quote_open(tmp))
		{
			write(STDOUT_FILENO, "\n", 1);
			new = rl_sjoin(tmp, "\n");
			free(tmp);
			compl = ft_readline("> ");
			tmp = rl_sjoin(new, compl);
			free(new);
			free(compl);
		}
		printf("\nre:%s\n", tmp);
		if (!strcmp(tmp, "exit"))
		{
			free(tmp);
			break;
		}
		free(tmp);
		free(input);
		free_completion();
	}
	free_hist();
	return (0);
}
