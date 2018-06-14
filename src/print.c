/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:26:56 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/15 13:27:27 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

static int	get_dims(t_elem *root, int *size, int *max_len)
{
	t_elem	*start;
	int		tmp;
	int		mlen;

	if (!root)
		return (0);
	start = root;
	*size = 0;
	mlen = 0;
	while (1)
	{
		(*size)++;
		if ((tmp = ft_strlen(root->str)) > mlen)
			mlen = tmp;
		root = root->next;
		if (root == start)
			break ;
	}
	*max_len = mlen;
	return (*size);
}

static void	print_properly(t_elem *root, int longest)
{
	if (root->current)
		ft_putstr(UNDERLINED);
	if (root->selected)
		ft_putstr(REVERSE_VIDEO_COLOR);
	ft_printf("%-*s", longest + 2, root->str);
	ft_putstr(DEFAULT_COLOR);
}

static void	print_columns(t_elem *root, int size, int longest)
{
	int		cols;
	int		i;
	int		tmp;
	t_elem	*start;

	tgetent(NULL, getenv("TERM"));
	cols = 1 + size / tgetnum("li");
	i = 0;
	start = root;
	while (i < size)
	{
		tmp = cols;
		while (root && tmp)
		{
			print_properly(root, longest);
			root = root->prev;
			tmp--;
			i++;
			if (root == start)
				break ;
		}
		if (root == start)
			break ;
		ft_putchar('\n');
	}
}

void		print_list(t_elem *root)
{
	int		size;
	int		longest;

	if (!root)
		return ;
	get_dims(root, &size, &longest);
	print_columns(root, size, longest);
}

void		print_selected(t_elem *root)
{
	t_elem *start;

	if (!root)
		return ;
	start = root;
	while (1)
	{
		ft_putstr(DEFAULT_COLOR);
		if (root->selected)
		{
			ft_printf("%s", root->str);
			ft_putchar(' ');
		}
		root = root->prev;
		if (root == start)
			break ;
	}
	ft_putchar('\n');
}
