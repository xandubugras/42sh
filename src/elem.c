/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:58:51 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/10 15:57:03 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

t_elem	*create_elem(int num, char *str)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->num = num;
	new->str = ft_strdup(str);
	new->next = 0;
	new->prev = 0;
	new->selected = 0;
	new->current = 0;
	return (new);
}

t_queue	*create_queue(void)
{
	t_queue	*new;

	new = malloc(sizeof(t_queue));
	new->rear = 0;
	new->front = 0;
	return (new);
}

t_elem	*enqueue(t_queue *queue, int x, char *str)
{
	t_elem	*new;

	if (!queue)
		return (0);
	new = create_elem(x, str);
	if (!(queue->front))
		queue->front = new;
	if (!(queue->rear))
		queue->rear = new;
	else
	{
		queue->rear->prev = new;
		new->next = queue->rear;
		queue->rear = new;
	}
	return (new);
}

t_elem	*dequeue(t_queue *queue)
{
	t_elem	*tmp;

	if (!queue || !(queue->front))
		return (0);
	if (queue->front->prev)
	{
		queue->front->prev->next = 0;
		tmp = queue->front;
		queue->front = queue->front->prev;
		if (queue->front->prev == 0)
			queue->rear = queue->front;
		if (tmp->str)
			free(tmp->str);
		free(tmp);
	}
	else
	{
		if (queue->front->str)
			free(queue->front->str);
		free(queue->front);
		queue->front = 0;
		queue->rear = 0;
	}
	return (queue->front);
}

void	print_queue(t_queue *queue, char order)
{
	t_elem	*buf;
	int		i;

	if (!queue || !(queue->rear))
		return ;
	buf = order == 'R' ? queue->front : queue->rear;
	i = 0;
	while (buf)
	{
		ft_printf("%s\n", buf->str);
		buf = order == 'R' ? buf->prev : buf->next;
		i++;
	}
}
