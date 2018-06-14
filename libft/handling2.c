/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:08:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/25 14:45:53 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define F_C final_content

void			handle_hashtag_precision(t_descriptor *dsc)
{
	char	*fill;
	int		i;

	fill = dsc->type == 'x' ? "0x" : "0X";
	i = 0;
	while (!ft_isdigit(dsc->F_C[i]) && dsc->F_C[i])
		i++;
	if (!N_TYPE_O(dsc->type) || (dsc->F_C[i] == '0' && !dsc->F_C[i + 1]))
	{
		if (dsc->F_C[i] == '0')
			return ;
		else if (i > 0 && dsc->F_C[i - 1] == ' ')
			dsc->F_C[i - 1] = '0';
		else
			ft_strinsert(&(dsc->F_C), "0", i);
	}
	else if (i == 0)
		ft_strinsert(&(dsc->F_C), fill, i);
	else if (i == 1 && fill[1] != '\0')
	{
		dsc->F_C[0] = fill[1];
		ft_strinsert_char(&(dsc->F_C), fill[0], 0);
	}
	else if (i >= 2)
		ft_strncpy(&(dsc->F_C[i - 2]), fill, 2);
}

void			handle_hashtag_zero(t_descriptor *descriptor)
{
	char	*fill;

	if (descriptor->hash)
	{
		fill = descriptor->type == 'x' ? "0x" : "0X";
		if (descriptor->type == 'o')
			fill = "0";
		if (descriptor->F_C[0] == '0')
		{
			if (descriptor->type == 'o' || !descriptor->F_C[1])
				return ;
			else if (descriptor->F_C[1] == '0')
				ft_strncpy(descriptor->F_C, fill, 2);
			else
				ft_strinsert_sub(&(descriptor->F_C), fill, 0);
		}
		else if (ft_isdigit(descriptor->F_C[0]))
			ft_strinsert(&(descriptor->F_C), fill, 0);
	}
}

void			handle_minus(t_descriptor *descriptor)
{
	int		i;
	char	*dsc;
	char	*new;
	int		len;

	if (descriptor->minus)
	{
		dsc = descriptor->F_C;
		new = ft_strnew(ft_strlen(dsc));
		i = 0;
		while (dsc[i] == ' ' && dsc[i])
			i++;
		if (i == 0)
			return ;
		len = ft_strlen(&(dsc[i]));
		ft_strncpy(new, &(dsc[i]), len);
		i = len;
		while (i < (int)ft_strlen(dsc))
			new[i++] = ' ';
		free(dsc);
		descriptor->F_C = new;
	}
}

char			*handle_star(char **description, va_list arg_pointer)
{
	int		i;
	char	*c;

	while ((ft_strchr(*description, '*')) != NULL)
	{
		i = 0;
		while ((*description)[i] != '*' && (*description)[i])
			i++;
		c = ft_itoa(va_arg(arg_pointer, int));
		ft_strinsert_sub(description, c, i);
		free(c);
	}
	return (*description);
}
