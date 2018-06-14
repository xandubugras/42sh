#include "../include/42sh.h"
#define UP 1
#define DOWN 2

int		clear_line(t_tracker *tr)
{
	int		i;

	i = 0;
	while (tr->pos)
		move_cursor_left(tr);
	while (i < tr->len)
	{
		ft_putstr_fd(tgetstr("dc", 0), 1);
		i++;
	}
	return (1);
}

void	clear_and_replace(t_tracker *tr, char **input, t_elem *new)
{
	tr->curr = new;
	clear_line(tr);
	*input = new ? new->str : tr->str;
	print_properly(*input, tr);
}

int		get_history(t_terminal *t, char **input, t_tracker *tr, int order)
{
	if (!t->cmds->top)
		return (1);
	if (tr->curr == 0)
	{
		tr->str = *input;
		if (order == UP)
			clear_and_replace(tr, input, t->cmds->top);
	}
	else if (tr->curr != t->cmds->bot && tr->curr != t->cmds->top)
	{
		if (tr->curr->next && order == UP)
			clear_and_replace(tr, input, tr->curr->next);
		else if (tr->curr->prev && order == DOWN)
			clear_and_replace(tr, input, tr->curr->prev);
	}
	else if (tr->curr == t->cmds->top)
	{
		if (order == DOWN)
			clear_and_replace(tr, input, 0);
		else if (order == UP && tr->curr->next)
			clear_and_replace(tr, input, tr->curr->next);
	}
	else if (tr->curr == t->cmds->bot)
		if (order == DOWN && tr->curr->prev)
			clear_and_replace(tr, input, tr->curr->prev);
	return (1);
}
