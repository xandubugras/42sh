#include "../include/42sh.h"

void	clear_mem(char *str, size_t size)
{
	size_t	i;

	i = size;
	while (str[i])
		str[i++] = 0;
}
