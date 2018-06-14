/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/25 14:45:37 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define F_C final_content

void		format_content(t_descriptor *descriptor)
{
	if (descriptor->type == '%' || descriptor->type == 'p')
	{
		handle_padding(descriptor);
		handle_minus(descriptor);
		return ;
	}
	if (descriptor->F_C[0] && descriptor->precision > 0)
		handle_precision(descriptor);
	handle_padding(descriptor);
	if (descriptor->type != 'c')
		handle_plus_space(descriptor);
	if (descriptor->hash && descriptor->type != 'd')
	{
		if (descriptor->zero)
			handle_hashtag_zero(descriptor);
		else if (descriptor->precision != -1)
			handle_hashtag_precision(descriptor);
	}
	handle_minus(descriptor);
}

void		handle_precision(t_descriptor *descriptor)
{
	char	*new_str;
	int		i;
	int		len;

	if (descriptor->precision)
	{
		len = ft_strlen(descriptor->F_C);
		if (len < descriptor->precision && descriptor->type != 's')
		{
			new_str = ft_strnew(descriptor->precision);
			i = 0;
			while (i < (descriptor->precision - len))
				new_str[i++] = '0';
			ft_strncpy(&new_str[i], descriptor->F_C, len);
			free(descriptor->F_C);
			descriptor->F_C = new_str;
		}
		else if (!N_TYPE_S(descriptor->type) && len > descriptor->precision)
		{
			new_str = ft_strnew(descriptor->precision);
			ft_strncpy(new_str, descriptor->F_C, descriptor->precision);
			free(descriptor->F_C);
			descriptor->F_C = new_str;
		}
	}
}

void		handle_padding(t_descriptor *descriptor)
{
	char	fill;
	int		i;
	char	*new_str;
	int		len;

	if (descriptor->width)
	{
		len = ft_strlen(descriptor->F_C);
		fill = ' ';
		if (descriptor->zero)
			fill = '0';
		if (descriptor->width > len)
		{
			new_str = ft_strnew(descriptor->width);
			i = 0;
			while (i < (descriptor->width - len))
				new_str[i++] = fill;
			ft_strncpy(&new_str[i], descriptor->F_C, len);
			free(descriptor->F_C);
			descriptor->F_C = new_str;
		}
	}
}

void		handle_plus_space(t_descriptor *descriptor)
{
	char	*str;
	char	fill;
	int		i;

	fill = descriptor->negative ? '-' : '+';
	if (descriptor->space && fill == '+')
		fill = ' ';
	if ((descriptor->negative || descriptor->plus || descriptor->space))
	{
		str = descriptor->F_C;
		i = 0;
		while (!ft_isdigit(str[i]) && str[i])
			i++;
		if (str[i] == '0' && descriptor->zero)
			str[i] = fill;
		else if (i > 0 && str[i - 1] == ' ')
			str[i - 1] = fill;
		else if (str[i] == '0' && descriptor->precision)
			descriptor->F_C = ft_strinsert_char(&(descriptor->F_C), fill, i);
		else
		{
			descriptor->F_C = ft_strinsert_char(&(descriptor->F_C), fill, 0);
		}
	}
}
