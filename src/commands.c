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

/*void	add_line(char *input, int *pos, int *len)
{
	
}*/

int		handle_shift(char *input, int r)
{
	if (r == 3 && input[0] == 27 && input[1] == 91 && input[2] == 90)
		return (5); //add new line
	if (r == 6 && input[0] == 27 && input[1] == 91 && input[2] == 49 &&
		input[3] == 59 && input[4] == 50)
	{
		if (input[5] == 65)
			ft_printf("shitftup\n"); //add new line
			//r += 1 - 1;//up
		else if (input[5] == 66)
			ft_printf("shiftdown\n"); //add new line
			//r += 1 - 1;//down
		else if (input[5] == 67)
			ft_printf("shiftright\n"); //add new line
			//r += 1 - 1;//right
		else if (input[5] == 68)
			ft_printf("shiftleft\n"); //add new line
			//r += 1 - 1;//left
		else
			return (ft_printf("NADA\n"));
		return (1);
	}
	return (0);
}
