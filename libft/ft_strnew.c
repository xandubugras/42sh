/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:26:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/17 19:23:33 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	int		i;

	new = (char *)(ft_memalloc(sizeof(char) * (size + 1)));
	i = 0;
	while (i < (int)size)
	{
		new[i] = 0;
		i++;
	}
	new[size] = '\0';
	return (new);
}
