/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 12:02:28 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/14 17:56:18 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# define REVERSE_VIDEO_COLOR    "\033[7m"
# define UNDERLINED             "\033[4m"
# define DEFAULT_COLOR          "\033[0m"
# define COOL_RED				"\e[1;31m"
# define ENTER_KEY				10
# define ESC_KEY                27
# define DELETE_KEY                127
# define SPC_KEY                32
# define STAR_KEY               42
# define MINUS_KEY              45
# define O_KEY                  111
# define B_KEY                  98
# define BSP_KEY                127
# define LEFT_KEY               4479771
# define RIGHT_KEY              4414235
# define UP_KEY              	4283163
# define DOWN_KEY               4348699
# define DEL_KEY                2117294875L
# define DIRTY_CHAR				48

typedef struct	s_elem
{
	struct s_elem	*next;
	struct s_elem	*prev;
	int				num;
	char			*str;
	char			selected;
	char			current;
}				t_elem;

typedef struct	s_tracker
{
	int		i;
	int		pos;
	int		len;
	int		last_read;
}				t_tracker;

typedef struct	s_terminal
{
	struct termios	term;
	char			*up;
	char			*down;
	char			*left;
	char			*right;
	char			*clear;
}				t_terminal;

typedef struct	s_queue
{
	struct s_elem	*rear;
	struct s_elem	*front;
}				t_queue;

typedef struct	s_stack
{
	struct s_elem	*top;
	struct s_elem	*bot;
}				t_stack;

struct termios	prev_term;
struct termios	bg_term;
t_elem			*root;

void			init_signal_handlers(void);
/*
**-------------------------SET_TERM------------------------
*/
void			clear_scrn(t_terminal t);

int				set_terminal(t_terminal *t);

int				set_can_terminal(t_terminal *t);

void			retrieve_terminal(struct termios prev_term);

void			go_terminal(struct termios prev_term);
/*
**RUN_SHELL.c
*/
int				run_shell(t_terminal *t);
/*
**DISPLAY_PROMPT.c
*/
char			*prompt_command(t_terminal *t, t_stack *cmds, char *msg);
/*
**DISPLAY_PROMPT2.c
*/
char			*insert_char(char *input, int *len, int *pos, int *i);

char			*rm_char(char *input, int pos);
/*
**helper.c
*/
void	clear_mem(char *str, size_t size);
/*
**COMMANDS.c
*/
void			move_cursor_left(int *pos);

void			move_cursor_right(int *pos, int len);

int				delete_char(int *pos, int *len);

int				handle_shift(char *input, int r);
/*
**SPLIT_INPUT.c
*/
char			**split_and_rejoin(char *input);
/*
**replacements.c
*/
char			*replace_wc(char *input);
/*
**-------------------------CREATE_LIST------------------------
*/
t_elem			*create_list(int argc, char **argv);

void			print_list(t_elem *root);

void			print_selected(t_elem *root);

t_elem			*remove_list(t_elem *elem);

/*
**-------------------------KEYS----------------------------
*/
t_elem			*handle_keys(t_elem *root, t_terminal *t);
/*
**-------------------------QUEUES----------------------
*/
t_elem			*create_elem(int x, char *str);

t_queue			*create_queue(void);

void			print_queue(t_queue *queue, char order);

t_elem			*dequeue(t_queue *queue);

t_elem			*enqueue(t_queue *queue, int x, char *str);
/*
**-------------------------STACKS----------------------
*/
t_stack			*create_stack(void);

t_elem			*push(t_stack *stack, int x, char *str);

t_elem			*pop(t_stack *stack);

int				stack_size(t_stack *stack);

void			print_stack(t_stack *stack);
#endif
