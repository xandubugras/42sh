#include "../include/42sh.h"

void	clear_mem(char *str, size_t size)
{
	size_t	i;

	i = size;
	while (str[i])
		str[i++] = 0;
}

int		find_eol(char *input, int line)
{
	int		l_count;
	int		i;
	int		len;

	if (!input)
		return (0);
	l_count = 0;
	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '\n')
		{
			l_count++;
			if (l_count == line + 1)
				break ;
			len = 0;
		}
		i++;
		len++;
	}
	return (len);
}

char	**set_arguments(char **input, int *i)
{
	int		j;
	int		tmp;
	char	**args;

	ft_printf("input1: %s i:%d\n", input[*i], *i);
	if (!input || !*input)
		return (0);
	j = 0;
	while (!set_todo(input[j + *i]))
		j++;
	ft_printf("j= %d\n", j);
	tmp = j + *i;
	args = malloc(sizeof(char *) * (j + 1));
	args[j] = 0;
	while (--j >= 0)
		args[j] = ft_strdup(input[*i + j]);
	*i = tmp;
	ft_printf("input2: %s i:%d\n", input[*i], *i);
	return (args);
}

void	print_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}
