/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:52:42 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/21 17:10:48 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = dst;
	while (i < n)
	{
		ptr[i] = ((char *)src)[i];
		if ((((char *)src)[i]) == (char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
