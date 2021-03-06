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
