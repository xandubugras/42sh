#include "../include/42sh.h"

int		move_cursor_left(t_tracker *tr, char *input)
{
	int		lim;

	lim = tr->line == 0 ? tr->msg_size : 0;
	if (tr->col > lim)
	{
		ft_putstr_fd(tgetstr("le", 0), 1);
		tr->col -= 1;
		if (tr->pos > 0)
			tr->pos -= 1;
	}
	else
		go_prev_line(tr, input);
	return (1);
}

int		move_cursor_right(t_tracker *tr, char *input)
{
	if (!input)
		return (1);
	if (input[tr->pos])
	{
		ft_putstr_fd(tgetstr("nd", 0), 1);
		tr->col += 1;
		if (tr->pos < tr->len)
			tr->pos += 1;
	}
	if (input[tr->pos] == '\n')
		go_next_line(tr, input);
	return (1);
}

int		print_properly(char *str, t_tracker *tr)
{
	int		ret;

	if (!str || !tr)
		return (0);
	ret = 0;
	while (str[ret])
	{
		ft_putchar(str[ret]);
		ret++;
	}
	tr->col += ret;
	tr->pos += ret;
	tr->len += ret;
	return (1);
}

int		handle_shift(char *buf, t_tracker *tr)
{
	if (tr->r == 3 && buf[0] == 27 && buf[1] == 91 && buf[2] == 90)
		return (1); //tab
	if (tr->r == 6 && buf[0] == 27 && buf[1] == 91 && buf[2] == 49 &&
		buf[3] == 59 && buf[4] == 50)
	{
		if (buf[5] == 65)
			return (2); // up
		else if (buf[5] == 66)
			return (3);// down
		else if (buf[5] == 67)
			return (4); // right
		else if (buf[5] == 68)
			return (5);// left
	}
	return (0);
}
