#include "../include/42sh.h"

char	*insert_char(char *input, int *len, int *pos, int *i)
{
	int		j;
	int		k;

	if (*pos == *len)
		ft_putchar(input[*i]);
	else
	{
		j = 0;
		k = -1;
		while (input[++k] && j < *pos)
			if (input[k] != -1)
				j++;
		if (input[k] == -1)
			ft_swap((int *)&input[k], (int *)&input[*i]);
		else
			ft_strinsert_char(&input, input[*i], k);
		ft_putchar(input[k]);
	}
	*i += 1;
	*pos += 1;
	*len += 1;
	return (input);
}

char	*rm_char(char *input, int pos)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (input[k] && j < pos + 1)
	{
		if (input[k] != DIRTY_CHAR)
			j++;
		k++;
	}
	if (!input[k])
		ft_printf("caralhitos\n");
	input[k - 1] = DIRTY_CHAR;
	return (input);
}
