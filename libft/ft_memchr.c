/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:46:44 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/21 16:46:45 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sc;
	size_t	i;

	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		if (sc[i] == (char)c)
			return ((void *)(&sc[i]));
		i++;
	}
	return (NULL);
}
