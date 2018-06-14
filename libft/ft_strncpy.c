/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:30:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/22 16:42:54 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while ((size_t)i < len)
	{
		if (src[i])
			dst[i] = src[i];
		else
			while ((size_t)i < len)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	return (dst);
}

int		ft_strncpy_safe(char *dst, char *src, size_t len)
{
	size_t	i;

	if (!dst || !src || !len)
		return (0);
	i = 0;
	while (dst[i] && src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}







wchar_t	*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (src[i])
			dst[i] = src[i];
		else
			while (i < len)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	return (dst);
}
