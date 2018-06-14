/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:44:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/23 23:57:52 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	int		found;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	found = 0;
	while (haystack[i] && !found)
	{
		if (haystack[i] == *needle)
		{
			j = 0;
			k = i;
			found = 1;
			while (needle[j])
				if (needle[j++] != haystack[k++])
					found = 0;
			if (found)
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
