/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:30:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/22 17:23:54 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tmp;

	if (s1 == NULL)
		return (NULL);
	tmp = malloc(sizeof(char) * (n + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strncpy(tmp, s1, n);
	tmp[n] = '\0';
	return (tmp);
}

wchar_t	*ft_wstrndup(const wchar_t *s1, size_t n)
{
	wchar_t	*tmp;

	if (s1 == NULL)
		return (NULL);
	tmp = malloc(sizeof(wchar_t) * (ft_wstrlen(s1) + 1));
	if (tmp == NULL)
		return (NULL);
	ft_wstrncpy(tmp, s1, n);
	tmp[ft_wstrlen(s1)] = '\0';
	return (tmp);
}
