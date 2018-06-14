#include "../include/42sh.h"
#define QUOTE_MSG "\ndquote> "

int		handle_key(char *input, int *pos, int *len, t_terminal *t)
{
	int		r;

	r = ft_strlen(input);
	if (input[0] == ESC_KEY && !input[1])
		return (4);
	else if (input[0] == ENTER_KEY)
	{
		input[0] = 0;
		return (3);
	}
	else if (input[0] == DELETE_KEY)
		return (delete_char(pos, len));
	else if (!(ft_strncmp(t->left, input, 3)))
		move_cursor_left(pos);
	else if (!(ft_strncmp(t->right, input, 3)))
		move_cursor_right(pos, *len);
	else if (r == 6 || r == 3)
		return (handle_shift(input, r));
	return (0);
	*input = DIRTY_CHAR;
	return (r - 1);
}

char	*get_input(t_terminal *t)
{
	char	*input;
	int		i;
	int		pos;
	int		len;
	int		r;

	input = malloc(sizeof(char) * BUFF_SIZE);
	input[BUFF_SIZE - 1] = 0;
	i = 0;
	len = 0;
	pos = 0;
	while ((r = read(0, &input[i], BUFF_SIZE/2)) > 0 && i < BUFF_SIZE - 4)
	{
		clear_mem(&input[i], r);
		//ft_printf("\nr: %d\n%d %d %d %d %d %d\n",r, input[i], input[i + 1], input[i + 2], input[i + 3], input[i + 4], input[i + 5]);
		if ((r = handle_key(&input[i], &pos, &len, t) + 1) == 1 && ft_isprint(input[i]))
			input = insert_char(input, &len, &pos, &i);
		else if (r == 6)
		{
			input[i] = '\n';
			input = insert_char(input, &len, &pos, &i);
		}
		else if (r == 3)
			rm_char(input, pos);
		else if (r == 4)
			return (input);
		else if (r == 5)
			return (0);
	}
	return (0);
}

char	*clean_input(char *input)
{
	char	*new;
	int		i;
	int		clean_chars;

	clean_chars = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] != DIRTY_CHAR)
			clean_chars++;
		i++;
	}
	new = ft_strnew(clean_chars);
	while (--i >= 0)
		if (input[i] != DIRTY_CHAR)
		{
			new[clean_chars - 1] = input[i];
			clean_chars--;
		}
	free(input);
	return (new);
}

char	*check_quotes(char *input, t_terminal *t, int start)
{
	int		i;
	int		quote_count;
	char	*tmp;
	static char	*joined;

	joined = joined == 0 ? input : ft_strjoin(joined, input);
	joined = !start ? joined : input;
	i = 0;
	quote_count = 0;
	while (joined[i])
	{
		if (joined[i] == 34)
			if (i == 0 || (i > 0 && joined[i - 1] != 92))
				quote_count++;
		i++;
	}
	if (quote_count % 2)
	{
		tmp = joined;
		joined = ft_strjoin(joined, "\n");
		free(tmp);
		prompt_command(t, 0, QUOTE_MSG);
	}
	return (joined);
}
//shift Up 27 91 49 59 50 65
//shift Down 27 91 49 59 50 66
//shift left 27 91 49 59 50 68
//shift right 27 91 49 59 50 67

char	*prompt_command(t_terminal *t, t_stack *cmds, char *msg)
{
	char	*input;
	int		tmp;

	ft_printf("%s", msg);
	tmp = ft_strcmp(msg, QUOTE_MSG) ? 1 : 0;
	ft_putstr_fd(DEFAULT_COLOR, 1);
	ft_putstr_fd(tgetstr("im", 0), 1);
	set_can_terminal(t);
	input = get_input(t);
	if (input)
	{
		input = clean_input(input);
		input = check_quotes(input, t, tmp);
		ft_printf("\ninput: %s\n", input);
	}
	ft_putstr_fd(tgetstr("ei", 0), 1);
	push(cmds, 0, input);
	cmds = cmds + 1 - 1;
	return (input);
}
