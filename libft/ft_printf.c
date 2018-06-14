/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:02:03 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/27 16:27:24 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_argument(va_list arg_pointer, char **format, int *prntd)
{
	t_descriptor *descriptor;

	descriptor = new_descriptor();
	if (!set_descriptor(format, arg_pointer, descriptor))
	{
		if (descriptor->final_content)
		{
			format_content(descriptor);
			*prntd += ft_strlen(descriptor->final_content);
		}
		ft_putstr(descriptor->final_content);
		free(descriptor->final_content);
		free(descriptor->description);
	}
	free(descriptor);
}

int		ft_printf(char *format, ...)
{
	va_list			arg_pointer;
	int				printed_characters;

	va_start(arg_pointer, format);
	printed_characters = 0;
	while (*format)
	{
		if (*format == '%')
			ft_print_argument(arg_pointer, &format, &printed_characters);
		else
		{
			ft_putchar(*format);
			printed_characters++;
		}
		format++;
	}
	va_end(arg_pointer);
	return (printed_characters);
}

/*
** void	print_descriptor(t_descriptor *d)
** {
**	printf("description: %s\nprinted: %d\nplus: %d\nminus:
** %d\nhash:%d\nzero: %d\nspace: %d\nwidth:
** %d\nlength: %d\nprecision: %d\ntype: %d\nargument:
** %lld\nbase: %d\n%s\n",
** d->description, d->printed_characters, d->plus,
** d->minus, d->hash, d->zero, d->space, d->width,
** d->length, d->precision, d->type, d->arg, d->base,
** d->final_content);
** }
*/
