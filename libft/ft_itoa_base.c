/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:26:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/22 14:51:57 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
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

static int	size(int n, int base)
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

static char	*handlemin(int base)
{
	char	*str;
	int		len;

	if (base == 4)
		return ("2000000000000000");
	if (base == 8)
		return ("20000000000");
	if (base == 16)
		return ("80000000");
	else
	{
		str = ft_itoa_base(MIN_INT + 1, base);
		len = size(MIN_INT + 1, base) + 1;
		str[len] = '\0';
		if (str[len - 1] != '9')
			str[len - 1] = (str[len - 1]) + 1;
		else
			str[len - 1] = 'A';
		return (str);
	}
	return ("0");
}

char		*ft_itoa_base(int value, int base)
{
	char	*itoa;
	int		len;
	int		i;

	if (value == MIN_INT)
		return (ft_strdup(handlemin(base)));
	len = size(value, base);
	if (value <= 0)
		len++;
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

char		*ft_uitoa_base(unsigned int value, int base)
{
	char	*itoa;
	int		len;
	int		i;

	len = size(value, base);
	if (value == 0)
		len++;
	itoa = ft_strnew(len);
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
