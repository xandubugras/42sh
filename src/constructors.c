#include "../include/42sh.h"

t_tracker	*init_tracker(t_tracker *t, char *str)
{
	t->msg_size = ft_strlen(str);
	t->pos = 0;
	t->col = t->msg_size;
	t->len = t->msg_size;
	t->str = 0;
	t->r = 0;
	t->curr = 0;
	t->line = 0;
	return (t);
}
