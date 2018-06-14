#include "../include/42sh.h"

t_tracker	*init_tracker(t_tracker *t)
{
	t->i = 0;
	t->pos = 0;
	t->len = 0;
	t->str = 0;
	t->r = 0;
	t->curr = 0;
	return (t);
}
