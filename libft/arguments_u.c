/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:51:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/25 14:46:21 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define F_C final_content
#define BASE descriptor->base

static char	*uset_num_final_2(t_descriptor *descriptor, va_list arptr)
{
	uintmax_t				uint_case;
	size_t					sizet_case;
	unsigned long long		ll_case;

	if (descriptor->length == J)
	{
		uint_case = va_arg(arptr, uintmax_t);
		descriptor->F_C = (ft_ultoa_base((unsigned long long)uint_case, BASE));
	}
	else if (descriptor->length == Z)
	{
		sizet_case = va_arg(arptr, size_t);
		descriptor->F_C = (ft_ultoa_base((unsigned long long)sizet_case, BASE));
	}
	else if (descriptor->length == LL)
	{
		ll_case = va_arg(arptr, unsigned long long);
		descriptor->F_C = (ft_ultoa_base(ll_case, BASE));
	}
	else
		descriptor->F_C = (ft_ultoa_base(va_arg(arptr, unsigned int), BASE));
	return (descriptor->F_C);
}

char		*uset_num_final(t_descriptor *descriptor, va_list arptr)
{
	unsigned char		char_case;
	unsigned short		short_case;
	unsigned long		long_case;

	if (descriptor->length == H && !N_TYPE_X(descriptor->type))
	{
		short_case = va_arg(arptr, unsigned int);
		descriptor->F_C = (ft_ultoa_base((unsigned long long)short_case, BASE));
	}
	else if (descriptor->length == L || descriptor->length == H ||
			descriptor->type == 'U' || descriptor->type == 'O')
	{
		long_case = va_arg(arptr, unsigned long);
		descriptor->F_C = (ft_ultoa_base((unsigned long long)long_case, BASE));
	}
	else if (descriptor->length == HH)
	{
		char_case = (unsigned char)va_arg(arptr, unsigned int);
		descriptor->F_C = (ft_itoa_base((unsigned int)char_case, BASE));
	}
	else
		return (uset_num_final_2(descriptor, arptr));
	return (descriptor->F_C);
}
