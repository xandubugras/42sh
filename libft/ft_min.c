/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 00:53:42 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/17 17:26:37 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_min_three(int a, int b, int c)
{
	int min;

	min = a > b ? b : a;
	min = min < c ? min : c;
	return (min);
}
