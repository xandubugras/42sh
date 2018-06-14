#include "libft.h"

char	*remove_char(char **str, size_t pos)
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
