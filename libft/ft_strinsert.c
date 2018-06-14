/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:27:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/21 15:03:20 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strinsert(char **src, char *str, int loc)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = ft_strnew(len + ft_strlen(*src));
	ft_strncpy(new, *src, loc);
	ft_strncpy((new + loc), str, len);
	ft_strncpy((new + loc + len), (*src) + loc, ft_strlen(*src) - loc);
	free(*src);
	*src = new;
	return (new);
}

char	*ft_strinsert_char(char **src, char str, int loc)
{
	char	*new;

	new = ft_strnew(1 + ft_strlen(*src));
	ft_strncpy(new, *src, loc);
	ft_strncpy((new + loc), &str, 1);
	ft_strncpy((new + loc + 1), (*src) + loc, ft_strlen(*src) - loc);
	free(*src);
	*src = new;
	return (new);
}

char	*ft_strremove_char(char **src, int loc)
{
	char	*new;

	new = ft_strnew(ft_strlen(*src) - 1);
	ft_strncpy(new, *src, loc);
	ft_strncpy((new + loc), (*src) + loc + 1, ft_strlen(*src) - loc);
	free(*src);
	*src = new;
	return (new);
}
