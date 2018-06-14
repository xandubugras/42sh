/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:11:46 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/22 21:59:17 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	while (*sc)
	{
		if (*sc == (char)c)
		{
			return (sc);
		}
		sc++;
	}
	if (*sc == c)
		return (sc);
	return (NULL);
}
