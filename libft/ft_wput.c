/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:45:50 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/22 12:51:19 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

void	ft_putwstr(wchar_t *str, int n)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] && n > 0)
	{
		write(1, &str[i++], 1);
		n--;
	}
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
