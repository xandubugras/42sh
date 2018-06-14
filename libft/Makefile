# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 20:33:37 by adubugra          #+#    #+#              #
#    Updated: 2018/03/27 11:11:29 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

FLAG =	-c -I. -Wall -Wextra -Werror

NAME =	libft.a

LIB =	ar rc

RLIB =	ranlib

SRCS=ft_memset.c \
				ft_bzero.c \
				ft_find_number.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_strlen.c \
				ft_memmove.c \
				ft_toa_hardcoded.c \
				ft_memchr.c \
				ft_swap.c \
				ft_get_last_char.c \
				ft_mod.c \
				ft_itoa_base.c \
				ft_ltoa_base.c \
				ft_wput.c \
				ft_strupper.c \
				ft_return_mod.c \
				ft_memcmp.c \
				ft_strinsert.c \
				ft_strinsert_sub.c \
				ft_strcpy.c \
				ft_strdup.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isdigit_sign.c \
				ft_strmerge.c \
				get_next_line.c \
				ft_isalnum.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strncpy.c \
				ft_isascii.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_strndup.c \
				get_word_len.c \
				ft_countwords.c \
				ft_printf.c \
				set_descriptor.c \
				set_descriptor2.c \
				handling.c \
				handling2.c \
				arguments.c \
				arguments_u.c \
				unknown_chars.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

comp: 
		$(CC) -Wall -Wextra -I. -o libft_exec $(SRCS) main.c && ./libft_exec

$(NAME):
		@$(CC) $(FLAG) $(SRCS)
		@$(LIB) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)

clean:
		@/bin/rm -f $(OBJS)
		@/bin/rm -f libft_exec

fclean:	clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
