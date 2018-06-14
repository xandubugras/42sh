/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:25:04 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/27 16:27:07 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define F_C final_content

int			set_descriptor(char **format, va_list arg_pointer, t_descriptor *d)
{
	if ((d->description = separate_descriptor(format)) == NULL)
		return (1);
	handle_star(&(d->description), arg_pointer);
	d->type = d->description[ft_strlen(d->description) - 1];
	set_base(d);
	set_format_flags(d);
	set_precision(d);
	set_width(d);
	set_length(d);
	set_final(d, arg_pointer);
	if (!d->F_C)
		return (0);
	if (d->F_C[0] == '-' && !N_TYPE_D(d->type))
	{
		d->negative = 1;
		ft_strremove_char(&(d->F_C), 0);
	}
	else
		d->negative = 0;
	return (check_input_errors(d));
}

void		set_format_flags(t_descriptor *d)
{
	char	*dsc;
	char	*zero;

	dsc = d->description;
	if (ft_strchr(dsc, '+'))
		d->plus = 1;
	else
		d->plus = 0;
	if (ft_strchr(dsc, '-'))
		d->minus = 1;
	else
		d->minus = 0;
	if (ft_strchr(dsc, '#'))
		d->hash = 1;
	else
		d->hash = 0;
	if ((zero = ft_strchr(dsc, '0')) &&
			!ft_isdigit(*(zero - 1)) && *(zero - 1) != '.' && !d->minus)
		d->zero = 1;
	else
		d->zero = 0;
	if (ft_strchr(dsc, ' ') && !d->plus)
		d->space = 1;
	else
		d->space = 0;
}

char		*separate_descriptor(char **format)
{
	int		i;
	char	*str;

	i = 0;
	if (*(*format + 1) != '\0')
		(*format)++;
	else
		return (NULL);
	str = *format;
	while (!is_format_letter(str[i]))
	{
		if (!str[i] || is_unknown_char(str[i]))
		{
			if (i == 0)
				(*format)--;
			else
				(*format) += i - 1;
			return (NULL);
		}
		i++;
	}
	*format += i;
	return (ft_strsub(str, 0, i + 1));
}

int			is_format_letter(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D')
		return (c);
	if (c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return (c);
	if (c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (c);
	if (c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G')
		return (c);
	if (c == 'a' || c == 'A' || c == 'n' || c == '%')
		return (c);
	return (0);
}

int			check_input_errors(t_descriptor *d)
{
	char	*dsc;
	int		type;

	dsc = d->description;
	type = d->type;
	if (ft_strchr(dsc, '.') && !d->precision && type != '%')
	{
		if (!N_TYPE_D(type) && d->F_C[0] != '0')
			return (0);
		if (type == 'p' && d->F_C[2] == '0')
		{
			d->F_C[2] = '\0';
			return (0);
		}
		d->F_C[0] = '\0';
		if (!N_TYPE_X(type))
			d->precision = -1;
	}
	return (0);
}
