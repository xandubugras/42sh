#include "../include/42sh.h"
#define QUOTE_CODE -2
#define SPACE_CODE -1


char	*find_quote(char *str)
{
	char	*buf;

	if ((buf = ft_strchr(str, 34)) && *(buf - 1) != 92)
		return (buf);
	return (0);
}

char	*remove_tmps(char *str, char tmp_num)
{
	int		i;
	char	*tmp;
	if (!str)
		return (0);
	i = 0;
	tmp = str;
	while (str[i])
	{
		if (str[i] == tmp_num)
			str[i] = ' ';
		i++;
	}
	if (tmp_num == QUOTE_CODE)
	{
		tmp = ft_strtrim(str);
		free(str);
	}
	if (tmp_num == QUOTE_CODE)
		return (remove_tmps(tmp, SPACE_CODE));
	return (tmp);
}

int		handle_quotes(char *str)
{
	int		i;
	char	*quote_one;
	char	*quote_two;

	if (!str)
		return (1);
	if (!(quote_one = find_quote(str)))
		return (1);
	i = 0;
	if ((quote_two = find_quote(quote_one + 1)))
		while (&quote_one[i] != quote_two)
		{
			if (quote_one[i] == ' ')
				quote_one[i] = SPACE_CODE;
			i++;
		}
	else
		return (1);
	*quote_one = QUOTE_CODE;
	*quote_two = QUOTE_CODE;
	return (0);
}

char	**split_and_rejoin(char *input)
{
	int		i;
	char	**splt;

	if (!input)
		return (0);
	while (!handle_quotes(input))
		;
	//ft_printf("handled: %s\n", input);
	splt = ft_strsplit(input, ' ');
	i = 0;
	while (splt[i])
	{
		splt[i] = remove_tmps(splt[i], QUOTE_CODE);
	//	ft_printf("%d: %s.\n", i, splt[i]);
		i++;
	}
	return (splt);
}
