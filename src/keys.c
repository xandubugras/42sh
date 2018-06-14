/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:39:32 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/14 17:57:02 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		set_current(t_elem **curr, t_elem *dest)
{
	if (!dest)
		return ;
	if (*curr)
		(*curr)->current = 0;
	if (dest)
		dest->current = 1;
	*curr = dest;
}

static void		handle_arrows(t_elem **curr, long long key)
{
	if (!curr || !(*curr))
		return ;
	if (key == UP_KEY)
		set_current(curr, (*curr)->next);
	if (key == DOWN_KEY)
		set_current(curr, (*curr)->prev);
}

static t_elem	*handle_remove(t_elem **root, t_elem **curr)
{
	if (*root && *curr == *root)
	{
		if (*root == (*root)->prev)
		{
			*root = 0;
			return (0);
		}
		else
			*root = (*root)->prev;
	}
	set_current(curr, remove_list(*curr));
	return (*curr);
}

static t_elem	*handle_commands(long long key, t_elem **curr, t_elem **root)
{
	if (key == SPC_KEY)
	{
		(*curr)->selected = !((*curr)->selected);
		set_current(curr, (*curr)->prev);
	}
	if (key == BSP_KEY || key == DEL_KEY)
		if (!handle_remove(root, curr))
			return (*root);
	if (key == ESC_KEY)
		while (handle_remove(root, curr))
			;
	return (0);
}

t_elem			*handle_keys(t_elem *root, t_terminal *t)
{
	t_elem			*curr;
	long long		key;

	if (!root || !t)
		return (0);
	curr = root;
	while (1)
	{
		if (!curr || !root)
			return (0);
		print_list(root);
		key = 0;
		read(0, &key, 8);
		clear_scrn(*t);
		handle_arrows(&curr, key);
		if (key == ENTER_KEY)
			break ;
		if (handle_commands(key, &curr, &root))
			return (root);
	}
	return (root);
	t++;
}
