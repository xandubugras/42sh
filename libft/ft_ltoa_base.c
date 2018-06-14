/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:26:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/22 14:46:38 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#define MIN_INT -2147483648

static char	equiv(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	else if (n >= 10 && n <= 15)
		return (n + 87);
	else
		return (40);
}

static int	usize(unsigned long long n, int base)
{
	int counter;

	counter = 0;
	while (n != 0)
	{
		n /= base;
		counter++;
	}
	return (counter);
}

static int	size(long long n, int base)
{
	int counter;

	counter = 0;
	while (n != 0)
	{
		n /= base;
		counter++;
	}
	return (counter);
}

char		*ft_ltoa_base(long long value, int base)
{
	char	*itoa;
	int		len;
	int		i;

	if (value == LLONG_MIN)
		return (ft_strdup(minint(base)));
	if (value == LLONG_MAX)
		return (ft_strdup(maxint(base)));
	len = value <= 0 ? size(value, base) + 1 : size(value, base);
	itoa = ft_strnew(len);
	if (value < 0)
	{
		itoa[0] = '-';
		value *= -1;
	}
	i = 1;
	if (value == 0)
		itoa[0] = '0';
	while (value > 0)
	{
		itoa[len - i] = equiv(value % base);
		value /= base;
		i++;
	}
	return (itoa);
}

char		*ft_ultoa_base(unsigned long long value, int base)
{
	char	*itoa;
	int		len;
	int		i;

	len = usize(value, base);
	if (len == 0)
		len++;
	itoa = ft_strnew(len);
	itoa[len] = '\0';
	i = 1;
	if (value != 0)
	{
		while (value > 0)
		{
			itoa[len - i] = equiv(value % base);
			value /= base;
			i++;
		}
	}
	else
		itoa[0] = '0';
	return (itoa);
}
