# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 12:48:48 by tjorge-l          #+#    #+#              #
#    Updated: 2024/04/29 10:15:23 by tjorge-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC := ft_strlen.c is_specifier.c get_nbr_specifiers.c\
out_length.c putnbr_fd_count.c  putpointer_fd_count.c putunint_fd_count.c format_traversal.c  \
ft_printf.c get_length_ofspe.c get_specifier.c percent_spe_q.c \
putbase_fd_count.c putstr_fd_count.c specifier_switch.c ft_isdigit.c \
get_nbr_digits.c get_unint_digits.c power.c putchar_fd_count.c 

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
#	$(CC) -c $(CFLAGS) $(OBJ) -o ##$(NAME)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
# https://www.baeldung.com/linux/a-so-extension-files
# https://medium.com/@ayogun/makefile-basics-beginner-intermediate-c92377542c2c