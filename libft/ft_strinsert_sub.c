/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:00:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/21 15:00:55 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strinsert_sub(char **src, char *str, int loc)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = ft_strnew(len + ft_strlen(*src) - 1);
	ft_strncpy(new, *src, loc);
	ft_strncpy((new + loc), str, len);
	ft_strncpy((new + loc + len), (*src) + loc + 1, ft_strlen(*src) - loc - 1);
	free(*src);
	*src = new;
	return (new);
}
