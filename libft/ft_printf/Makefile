# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 15:40:42 by eovertoo      #+#    #+#                  #
#    Updated: 2020/07/27 12:24:12 by anonymous     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = floats2 nan_inf print_binary clean input_octal print_diouxx print_floats print_ints \
check_flags check_input count_num floats itoa_base print_char print_pointers \
print_strings printf putnbr_base putstr_check read width

FILEC =	$(SRC:%=ft_%.c)

FILEO = $(SRC:%=ft_%.o)

INC = printf.h

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FILEC) -I$(INC)
	@ar rc $(NAME) $(FILEO)

clean:
	@/bin/rm -f $(FILEO)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
