/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:42:33 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/27 16:24:07 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define F_C final_content
#define DS_TYPE descriptor->type
#define ULL unsigned long long
#define W_F_C w_final_content

static char		*set_num_final_3(t_descriptor *descriptor, va_list arptr)
{
	long long		ll_case;
	int				base;

	base = descriptor->base;
	if (descriptor->length == LL)
	{
		ll_case = va_arg(arptr, long long);
		if (ll_case == LLONG_MIN)
			descriptor->F_C = ft_strdup("-9223372036854775808");
		else
			descriptor->F_C = ft_ltoa_base(ll_case, base);
	}
	else
		descriptor->F_C = ft_itoa_base(va_arg(arptr, int), base);
	return (descriptor->F_C);
}

static char		*set_num_final_2(t_descriptor *descriptor, va_list arptr)
{
	intmax_t		intmax_case;
	size_t			sizet_case;
	int				base;

	base = descriptor->base;
	if (descriptor->length == J)
	{
		intmax_case = va_arg(arptr, intmax_t);
		if (intmax_case == LLONG_MIN)
			descriptor->F_C = ft_strdup("-9223372036854775808");
		else
			descriptor->F_C = ft_ltoa_base((long long)intmax_case, base);
	}
	else if (descriptor->length == Z)
	{
		sizet_case = va_arg(arptr, size_t);
		descriptor->F_C = ft_ultoa_base((long long)sizet_case, base);
	}
	else
		return (set_num_final_3(descriptor, arptr));
	return (descriptor->F_C);
}

static int		set_str_final(t_descriptor *descriptor, va_list arptr)
{
	if (!N_TYPE_S(descriptor->type))
	{
		descriptor->F_C = ft_strdup(va_arg(arptr, char *));
		if (descriptor->F_C == NULL)
			descriptor->F_C = ft_strdup("(null)");
		return (1);
	}
	else if (!N_TYPE_C(DS_TYPE) || DS_TYPE == '%')
	{
		descriptor->F_C = ft_strnew(1);
		*(descriptor->F_C) = DS_TYPE == '%' ? '%' : (char)va_arg(arptr, int);
		descriptor->precision = 0;
		descriptor->space = 0;
		if (*descriptor->F_C == 0)
			descriptor->width--;
		return (1);
	}
	return (0);
}

void			set_final(t_descriptor *descriptor, va_list arptr)
{
	char				*c;

	if (set_str_final(descriptor, arptr))
		return ;
	else if (DS_TYPE == 'p')
	{
		descriptor->arg = (ULL)va_arg(arptr, ULL *);
		descriptor->F_C = ft_ltoa_base(descriptor->arg, 16);
		c = descriptor->F_C;
		descriptor->F_C = ft_strjoin("0x", c);
		free(c);
	}
	else if (DS_TYPE == 'u' || DS_TYPE == 'U' || DS_TYPE == 'x' ||
			DS_TYPE == 'o')
	{
		uset_num_final(descriptor, arptr);
		descriptor->space = 0;
		descriptor->plus = 0;
	}
	else if (DS_TYPE == 'X' || DS_TYPE == 'O')
		descriptor->F_C = ft_strupper(uset_num_final(descriptor, arptr));
	else
		set_num_final(descriptor, arptr);
}

char			*set_num_final(t_descriptor *descriptor, va_list arptr)
{
	char		char_case;
	short		short_case;
	long		long_case;

	if (descriptor->length == L || descriptor->type == 'D')
	{
		long_case = va_arg(arptr, long);
		if (long_case == LONG_MIN)
			descriptor->F_C = ft_strdup("-9223372036854775808");
		else
			descriptor->F_C = ft_ltoa_base(long_case, descriptor->base);
	}
	else if (descriptor->length == HH)
	{
		char_case = (char)va_arg(arptr, int);
		descriptor->F_C = ft_itoa_base((int)char_case, descriptor->base);
	}
	else if (descriptor->length == H)
	{
		short_case = (short)va_arg(arptr, int);
		descriptor->F_C = ft_itoa_base((int)short_case, descriptor->base);
	}
	else
		return (set_num_final_2(descriptor, arptr));
	return (descriptor->F_C);
}
