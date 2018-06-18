#include "../include/42sh.h"

int	remove_backslash(char **input)
{
	int	i;

	if (!input || !(*input) || !**input)
		return (0);
	if (*input[0] == 92 && *input[1] != 92)
		*input[0] = -1;
	i = 1;
	while ((*input)[i])
	{
		if ((*input)[i] == 92 && (*input)[i - 1] != 92)
			(*input)[i] = -1;
		i++;
	}
	*input = ft_remove_chars(input, -1);
	return (1);
}
