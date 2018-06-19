#include "../include/42sh.h"

int			set_todo(char *to_do)
{
	if (!to_do)
		return (1);
	if (!ft_strcmp(to_do, "&&"))
		return (2);
	if (!ft_strcmp(to_do, ";"))
		return (3);
	if (!ft_strcmp(to_do, "||"))
		return (4);
	if (!ft_strcmp(to_do, "|"))
		return (5);
	if (!ft_strcmp(to_do, ">>"))
		return (6);
	if (!ft_strcmp(to_do, "<"))
		return (7);
	if (!ft_strcmp(to_do, "<<"))
		return (8);
	if (!ft_strcmp(to_do, ">"))
		return (9);
	return (0);
}

t_command	*create_cmd_list(char **input)
{
	int		i;
	t_command	*root;
	t_command	*buf;

	i = 0;
	root = create_cmd(input, 0);
	buf = root;
	while (buf)
	{
		ft_printf("%s->", buf->command);
		buf = buf->next;
	}
	ft_putchar('\n');
	return (root);
}

t_command	*create_cmd(char **input, int i)
{
	t_command	*new;

	if (!input[i])
		return ((t_command *)ft_printf_err_zero("err: no command\n"));
	new = new_command();
	if ((new->command = ft_strdup(input[i])) == 0)
		return ((t_command *)ft_printf_err_zero("err: no commands\n"));
	new->arguments = set_arguments(input, &i);
	print_str_arr(new->arguments);
	if (input[i] == 0)
	{
		new->todo = 1;
		ft_printf("todo: %d\n\n", new->todo);
		return (new);
	}
	new->todo = set_todo(input[i]);
	ft_printf("todo: %d, i + 1: %d %s\n\n", new->todo, i + 1, input[i + 1]);
	new->next = create_cmd(input, i + 1);
	if (new->next)
	{
		new->next->is_file = new->todo > 5 ? 1 : 0;
		new->next->prev = new;
	}
	return (new);
}
