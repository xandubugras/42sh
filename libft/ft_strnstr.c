/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:51:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/24 00:32:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			found;

	i = 0;
	found = 1;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == *needle)
		{
			k = i;
			found = 1;
			while (haystack[k] && needle[j] && j < len && k < len)
				if (haystack[k++] != needle[j++])
					found = 0;
			if (found && !needle[j])
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
