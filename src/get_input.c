#include "../include/42sh.h"

char	*insert_char2(char **input, char *buf , t_tracker *tr)
{
	if (*input == 0)
	{
		*input = ft_strnew(tr->r);
		ft_strncpy(*input, buf, tr->r);
		return (*input);
	}
	ft_strinsert(input, buf, tr->pos);
	return (*input);
}

int		delete_char2(char **input, t_tracker *tr)
{
	if (!tr->pos)
		return (1);
	ft_strremove_char(input, tr->pos - 1);
	move_cursor_left(tr);
	ft_putstr_fd(tgetstr("dc", 0), 1);
	tr->len -= 1;
	return (1);
}

int		execute_shift_commands(char **input, t_tracker *tr, int code)
{
	input += 1 - 1;
	tr += 1 - 1;
	if (code == 1)
		ft_printf("SHIFtTAB");
	else if (code == 2)
		ft_printf("SHIFtup");
	else if (code == 3)
		ft_printf("SHIFtdown");
	else if (code == 4)
		ft_printf("SHIFtleft");
	else if (code == 5)
		ft_printf("SHIFtright");
	return (0);
}


int		handle_key(char **input, char *buf, t_tracker *tr, t_terminal *t)
{
	int		shift_code;

	t += 1 - 1;
	*input += 1 - 1;
	if (tr->r == 1 && buf[0] == ESC_KEY)
	{
		*input = 0;
		return (2);
	}
	else if (tr->r == 1 && buf[0] == ENTER_KEY)
	{
		if (!(*input))
			*input = ft_strdup("");
		return (2);
	}
	else if (tr->r == 1 && buf[0] == DELETE_KEY)
		return (delete_char2(input, tr));
	else if (!(ft_strncmp(t->left, buf, tr->r)))
		return (move_cursor_left(tr));
	else if (!(ft_strncmp(t->right, buf, tr->r)))
		return (move_cursor_right(tr));
	else if (!(ft_strncmp(t->up, buf, tr->r)))
		return (get_history(t, input, tr, 1));
	else if (!(ft_strncmp(t->down, buf, tr->r)))
		return (get_history(t, input, tr, 2));
	else if ((shift_code = handle_shift(buf, tr)))
		execute_shift_commands(input, tr, shift_code);
	return (0);
}

char	*get_input(t_terminal *t)
{
	char		*input;
	char		*buf;
	t_tracker	tr;
	int		ret;

	buf = ft_strnew(sizeof(char) * BUFF_SIZE);
	input = 0;
	init_tracker(&tr);
	while ((tr.r = read(0, buf, BUFF_SIZE - 1)) > 0)
	{
		buf[tr.r] = 0;
		if ((ret = handle_key(&input, buf, &tr, t)) == 2)
			return (input);
		else if (!ret)
		{
			insert_char2(&input, buf, &tr);
			print_properly(buf, &tr);
		}
	}
	return (0);
}

