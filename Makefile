# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <adubugra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/07 18:20:10 by adubugra          #+#    #+#              #
#    Updated: 2018/05/10 20:13:32 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 42sh

# src / obj files
SRC		=	main.c \
			set_term.c \
			elem.c \
			stack.c \
			signals.c \
			constructors.c \
			commands.c \
			commands2.c \
			cursor_jumps.c \
			replacements.c \
			remove_backslash.c \
			helper.c \
			split_input.c \
			display_prompt.c \
			get_input.c \
			command_list.c \
			execute_commands.c \
			run_shell.c
			

OBJ	= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -g -Werror 

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./include/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(FT_LNK) -lm -o $(NAME) -lncurses

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
