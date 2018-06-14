/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:15:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/25 11:26:09 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# define HH 1
# define H 2
# define L 3
# define LL 4
# define J 5
# define Z 6
# define N_TYPE_O(x) (x != 'o' && x != 'O')
# define N_TYPE_X(x) (x != 'x' && x != 'X')
# define N_TYPE_D(x) (x != 'd' && x != 'D' && x != 'i')
# define N_TYPE_C(x) (x != 'c' && x != 'C')
# define N_TYPE_S(x) (x != 's' && x != 'S')
# define N_TYPE_U(x) (x != 'u' && x != 'U')

typedef	struct	s_descriptor
{
	char		*description;
	int			printed_characters;
	int			plus;
	int			minus;
	int			zero;
	int			hash;
	int			space;
	int			width;
	int			length;
	int			precision;
	int			type;
	long long	arg;
	int			base;
	int			negative;
	int			wchar;
	char		*final_content;
	wchar_t		*w_final_content;
}				t_descriptor;

int				ft_printf(char *format, ...);

int				is_format_letter(char c);

char			*separate_descriptor(char **format);

int				set_descriptor(char **frmt, va_list argptr, t_descriptor *dsc);

void			set_format_flags(t_descriptor *descriptor);

void			set_length(t_descriptor *descriptor);

void			set_width(t_descriptor *descriptor);

void			set_precision(t_descriptor *descriptor);

void			set_base(t_descriptor *descriptor);

int				check_input_errors(t_descriptor *descriptor);

char			*handle_star(char **description, va_list arg_pointer);

void			format_content(t_descriptor *descriptor);

void			handle_plus_space(t_descriptor *descriptor);

void			handle_minus(t_descriptor *descriptor);

void			handle_hashtag_precision(t_descriptor *descriptor);

void			handle_hashtag_zero(t_descriptor *descriptor);

void			handle_padding(t_descriptor *descriptor);

void			handle_precision(t_descriptor *descriptor);

char			*set_num_final(t_descriptor *descriptor, va_list arg_pointer);

char			*uset_num_final(t_descriptor *descriptor, va_list arg_pointer);

void			set_final(t_descriptor *descriptor, va_list arg_pointer);

int				is_unknown_char(char c);

#endif
