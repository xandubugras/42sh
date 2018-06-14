/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 10:57:53 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/29 17:09:14 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_get_last_char(char *target, char last)
{
	char *buf;

	if (!target)
		return (0);
	buf = target;
	while (*buf != 0)
		buf++;
	while (*buf != last && buf != target)
		buf--;
	if (buf == target)
		return (target);
	return (buf);
}
