/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptor2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 08:16:57 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/27 15:55:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			set_length(t_descriptor *descriptor)
{
	if (ft_strstr(descriptor->description, "ll"))
		descriptor->length = LL;
	else if (ft_strchr(descriptor->description, 'l'))
		descriptor->length = L;
	else if (ft_strstr(descriptor->description, "j"))
		descriptor->length = J;
	else if (ft_strchr(descriptor->description, 'z'))
		descriptor->length = Z;
	else if (ft_strstr(descriptor->description, "hh"))
		descriptor->length = HH;
	else if (ft_strchr(descriptor->description, 'h'))
		descriptor->length = H;
	else
		descriptor->length = 0;
}

void			set_width(t_descriptor *descriptor)
{
	char *dsc;

	dsc = descriptor->description;
	while ((!ft_isdigit(*dsc) && *dsc) || *dsc == '0')
		dsc++;
	if (*(dsc - 1) != '.')
		descriptor->width = ft_return_mod(ft_atoi(dsc));
	else
		descriptor->width = 0;
}

void			set_precision(t_descriptor *descriptor)
{
	char *dsc;

	if ((dsc = ft_strchr(descriptor->description, '.')) != 0)
	{
		dsc++;
		descriptor->precision = ft_atoi(dsc);
		descriptor->zero = 0;
	}
	else
		descriptor->precision = 0;
}

void			set_base(t_descriptor *descriptor)
{
	if (descriptor->type == 'x' || descriptor->type == 'X')
		descriptor->base = 16;
	else if (descriptor->type == 'o' || descriptor->type == 'O')
		descriptor->base = 8;
	else if (!N_TYPE_D(descriptor->type) || !N_TYPE_U(descriptor->type))
		descriptor->base = 10;
	else
		descriptor->base = 0;
}

t_descriptor	*new_descriptor(void)
{
	t_descriptor *new;

	new = malloc(sizeof(t_descriptor));
	new->description = 0;
	new->printed_characters = 0;
	new->plus = 0;
	new->minus = 0;
	new->zero = 0;
	new->hash = 0;
	new->space = 0;
	new->width = 0;
	new->length = 0;
	new->precision = 0;
	new->type = 0;
	new->arg = 0;
	new->base = 0;
	new->negative = 0;
	new->final_content = 0;
	new->w_final_content = 0;
	return (new);
}
