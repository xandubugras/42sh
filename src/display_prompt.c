#include "../include/42sh.h"
#define QUOTE_MSG "\ndquote> "

char	*clean_input(char *input)
{
	char	*new;
	int		i;
	int		clean_chars;

	clean_chars = 0;
	i = 0;
	while (input[i])
	{
		if (ft_isprint(input[i]))
			clean_chars++;
		i++;
	}
	new = ft_strnew(clean_chars);
	while (--i >= 0)
		if (ft_isprint(input[i]))
		{
			new[clean_chars - 1] = input[i];
			clean_chars--;
		}
	free(input);
	return (new);
}

char	*check_quotes(char *input, t_terminal *t, int start)
{
	int		i;
	int		quote_count;
	char	*tmp;
	static char	*joined;

	joined = joined == 0 ? input : ft_strjoin(joined, input);
	joined = !start ? joined : input;
	i = 0;
	quote_count = 0;
	while (joined[i])
	{
		if (joined[i] == 34)
			if (i == 0 || (i > 0 && joined[i - 1] != 92))
				quote_count++;
		i++;
	}
	if (quote_count % 2)
	{
		tmp = joined;
		joined = ft_strjoin(joined, "\n");
		free(tmp);
		prompt_command(t, QUOTE_MSG);
	}
	return (joined);
}

char	*prompt_command(t_terminal *t, char *msg)
{
	char	*input;
	int		tmp;

	ft_printf("%s", msg);
	tmp = ft_strcmp(msg, QUOTE_MSG) ? 1 : 0;
	ft_putstr_fd(DEFAULT_COLOR, 1);
	ft_putstr_fd(tgetstr("im", 0), 1);
	set_can_terminal(t);
	input = get_input(t, msg);
	if (input)
	{
		input = clean_input(input);
		input = check_quotes(input, t, tmp);
		//ft_printf("\ninput: %s\n", input);
	}
	ft_putchar('\n');
	ft_putstr_fd(tgetstr("ei", 0), 1);
	return (input);
}
