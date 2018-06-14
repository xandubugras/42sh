/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:00:14 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/08 12:23:28 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/42sh.h"

t_stack	*create_stack(void)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (0);
	new->top = 0;
	return (new);
}

t_elem	*push(t_stack *stack, int x, char *str)
{
	t_elem	*new;

	if (!stack)
		return (0);
	if (!(new = create_elem(x, str)))
		return (0);
	if (!(stack->top))
	{
		stack->top = new;
		stack->bot = new;
	}
	else
	{
		new->next = stack->top;
		stack->top->prev = new;
		stack->top = new;
	}
	return (new);
}

t_elem	*pop(t_stack *stack)
{
	t_elem	*tmp;

	if (!stack)
		return (0);
	if (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		if (stack->top)
			stack->top->prev = 0;
		else
			stack->bot = 0;
		if (tmp && tmp->str)
			free(tmp->str);
		free(tmp);
		return (stack->top);
	}
	return (0);
}

int		stack_size(t_stack *stack)
{
	t_elem	*buf;
	int		i;

	if (!stack)
		return (0);
	buf = stack->top;
	i = 0;
	while (buf)
	{
		i++;
		buf = buf->next;
	}
	return (i);
}

void	print_stack(t_stack *stack)
{
	t_elem	*buf;

	if (!stack || !(stack->top))
	{
		ft_printf("empty stack\n");
		return ;
	}
	buf = stack->top;
	while (buf)
	{
		ft_printf("num: %d str: %s\n", buf->num, buf->str);
		buf = buf->next;
	}
}
