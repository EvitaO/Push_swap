# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/23 13:34:12 by eovertoo      #+#    #+#                  #
#    Updated: 2020/02/22 15:21:12 by eovertoo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_C = checker

SRC = check_input.c print.c free.c make_list.c str_argument.c sorted.c 

SRC_P = lst_size_rev.c max_five.c max_three.c merge.c push.c pushswap.c\
		put_position.c rev_rotate.c rotate.c sort.c sort2.c swap.c do_option.c

SRC_C = check_push.c checker.c checker_rev_rotate.c checker_rotate.c\
		checker_swap.c

OBJ = check_input.o print.o free.o make_list.o str_argument.o sorted.o

OBJ_P = lst_size_rev.o max_five.o max_three.o merge.o push.o pushswap.o\
		put_position.o rev_rotate.o rotate.o sort.o sort2.o swap.o do_option.o

OBJ_C = check_push.o checker.o checker_rev_rotate.o checker_rotate.o\
		checker_swap.o

PATH_SRC = src/

PATH_P = pushswap_src/

PATH_C = checker_src/

FILE_P = $(addprefix $(PATH_P), $(SRC_P))

FILE_C = $(addprefix $(PATH_C), $(SRC_C))

FILEC = $(addprefix $(PATH_SRC), $(SRC))

INC = pushswap.h

NORM = norminette $(FILEC) $(FILE_P) $(FILE_C) $(INC) | grep --color -e "Error" -e "Warning" -B 1

all: $(NAME) $(NAME_C)

$(NAME):
		@echo "\033[33m----------------------Compiling-----------------------\033[0m"
		@Make -C ./libft
		@mv libft/libft.a .
		@gcc -Wall -Wextra -Werror -c -I.$(INC) $(FILE_P) $(FILEC)
		@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ_P) $(OBJ) -I.$(INC) libft.a

$(NAME_C):
		@Make -C ./libft
		@mv libft/libft.a .
		@gcc -Wall -Wextra -Werror -c -I.$(INC) $(FILE_C) $(FILEC)
		@gcc -Wall -Wextra -Werror -o $(NAME_C) $(OBJ_C) $(OBJ) -I.$(INC) libft.a
		@echo "\033[32m-------------------------DONE-------------------------\033[0m"

clean:
		@echo "\033[35m---------------Objects has been removed---------------\033[0m"
		@Make clean -C ./libft
		@/bin/rm -f $(OBJ) $(OBJ_P) $(OBJ_C)

fclean: clean
		@echo "\033[36m-------Liberary and binary file has been removed------\033[0m"
		@Make fclean -C ./libft
		@/bin/rm -f $(NAME) $(NAME_C) libft.a
		
re: fclean all

norm:
	@echo "\033[34;1m-----------------------Norminette------------------------\033[0m"
	@$(NORM) || echo "no norminette errors"
	@echo "\033[34;1m---------------------------------------------------------\033[0m"

