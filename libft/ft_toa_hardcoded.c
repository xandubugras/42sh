/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toa_harcoded.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:45:17 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/22 14:45:34 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*minint(int base)
{
	if (base == 8)
		return ("777777777777777777777");
	if (base == 16)
		return ("7fffffffffffffff");
	else
		return ("-9223372036854775808");
}

char	*maxint(int base)
{
	if (base == 8)
		return ("777777777777777777777");
	if (base == 16)
		return ("7fffffffffffffff");
	else
		return ("9223372036854775807");
}
