#include "libft.h"

char	*remove_char(char **str, int pos)
{
	char	*new;
	char	*buf;
	int		i;
	int		j;
	int		size;

	if (!str || !*str)
		return (0);
	buf = *str;
	size = ft_strlen(buf) - 1;
	new = ft_strnew(size);
	i = 0;
	j = 0;
	while (j < size)
	{
		if (i != pos)
		{
			new[j] = buf[i];
			j++;
		}
		i++;
	}
	*str = new;
	return (new);
}

char	*ft_remove_chars(char **input, char remove)
{
	char	*new;
	int	i;
	int	count;

	if (!input || !(*input) || !(**input))
		return (0);
	i = -1;
	count = 0;
	while ((*input)[++i])
		if ((*input)[i] != remove)
			count++;
	new = ft_strnew(count);
	i = -1;
	count = 0;
	while ((*input)[++i])
		if ((*input)[i] != remove)
		{
			new[count] = (*input)[i];
			count++;
		}
	free((*input));
	(*input) = new;
	return (new);
}










