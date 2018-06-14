/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:29:27 by adubugra          #+#    #+#             */
/*   Updated: 2018/02/21 20:04:54 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (*s1 && *s1 == *s2 && i < (int)n - 1)
	{
		s1++;
		s2++;
		i++;
	}
	if (n)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
