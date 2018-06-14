#include "../include/42sh.h"

void	move_cursor_left(int *pos)
{
	if (*pos > 0)
	{
		ft_putstr_fd(tgetstr("le", 0), 1);
		*pos -= 1;
	}
}

void	move_cursor_right(int *pos, int len)
{
	if (*pos < len)
	{
		ft_putstr_fd(tgetstr("nd", 0), 1);
		*pos += 1;
	}
}

int		delete_char(int *pos, int *len)
{
	if (*pos > 0)
	{
		move_cursor_left(pos);
		ft_putstr_fd(tgetstr("dc", 0), 1);
		*len -= 1;
		return (2);
	}
	return (1);
}
