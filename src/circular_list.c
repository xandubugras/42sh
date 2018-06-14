/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:05:59 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/10 20:14:55 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_elem	*create_list(int argc, char **argv)
{
	int		i;
	t_queue *q;
	t_elem	*ret;

	q = create_queue();
	i = 1;
	while (i < argc)
	{
		enqueue(q, 0, argv[i]);
		i++;
	}
	q->front->current = 1;
	q->rear->prev = q->front;
	q->front->next = q->rear;
	ret = q->front;
	free(q);
	return (q->front);
}

t_elem	*remove_list(t_elem *elem)
{
	t_elem *ret;

	if (!elem)
		return (0);
	if (elem == elem->next)
	{
		free(elem->str);
		free(elem);
		return (0);
	}
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		elem->prev = 0;
	if (elem->next)
		elem->next->prev = elem->prev;
	else
		elem->next = 0;
	ret = elem->prev;
	if (elem)
	{
		free(elem->str);
		free(elem);
	}
	return (ret);
}
