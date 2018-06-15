#include "../include/42sh.h"

void	go_prev_line(t_tracker *tr, char *input)
{
	int		i;

	if (tr->col == 0 && tr->line > 0)
	{
		tr->line -= 1;
		tr->pos -= 1;
		tr->col = find_eol(input, tr->line);
		if (tr->line == 0)
			tr->col += tr->msg_size;
		ft_putstr_fd(tgetstr("up", 0), 1);
		i = -1;
		while (++i < tr->col)
			ft_putstr_fd(tgetstr("nd", 0), 1);
	}
}

void	go_next_line(t_tracker *tr, char *input)
{
	if (tr->line + 1 < tr->num_of_lines)
	{
		while (input[tr->pos] && input[tr->pos] != '\n')
			tr->pos += 1;
		tr->line += 1;
		ft_putstr_fd(tgetstr("do", 0), 1);
		while (--tr->col > 0)
			ft_putstr_fd(tgetstr("le", 0), 1);
	}
}

void	move_cursor_beginning(t_tracker *tr, char *input)
{
	int		lim;

	if (!input || !*input)
		return ;
	lim = tr->line == 0 ? tr->msg_size : 0;
	while (tr->col > lim)
		move_cursor_left(tr, input);
}

void	move_cursor_end(t_tracker *tr, char *input)
{
	if (!input || !*input)
		return ;
	while (input[tr->pos] && input[tr->pos + 1] != '\n')
		move_cursor_right(tr, input);
}
