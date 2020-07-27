# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: eovertoo <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 15:40:42 by eovertoo      #+#    #+#                  #
#    Updated: 2020/02/21 01:56:37 by eovertoo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = atoi bzero isalnum isalpha isascii isdigit isprint\
	itoa memalloc memccpy memchr memcmp memcpy memdel\
	memmove memset putchar putchar_fd putendl\
	putendl_fd putnbr putnbr_fd putstr putstr_fd strcat\
	strchr strclr strcmp strcpy strdel strdup strequ\
	striter striteri strjoin strlcat strlen strmap\
	strmapi strncat strncmp strncpy strnequ\
	strnew strnstr strrchr strsplit strstr strsub\
	strtrim tolower toupper lstnew lstdelone\
	lstdel lstadd lstiter swap isspace islower\
	isupper strrev isblank lstmap list_size\
	get_next_line isnum

FILEC =	$(SRC:%=ft_%.c)

OBJ = atoi bzero isalnum isalpha isascii isdigit isprint\
	itoa memalloc memccpy memchr memcmp memcpy memdel\
	memmove memset putchar putchar_fd putendl\
	putendl_fd putnbr putnbr_fd putstr putstr_fd strcat\
	strchr strclr strcmp strcpy strdel strdup strequ\
	striter striteri strjoin strlcat strlen strmap\
	strmapi strncat strncmp strncpy strnequ\
	strnew strnstr strrchr strsplit strstr strsub\
	strtrim tolower toupper lstnew lstdelone\
	lstdel lstadd lstiter swap isspace islower\
	isupper strrev isblank lstmap list_size\
	get_next_line isnum

FILEO = $(OBJ:%=ft_%.o)

INC = libft.h

all: $(NAME)

$(NAME):
	@Make -C ./ft_printf
	@gcc -Wall -Wextra -Werror -c $(FILEC) -I$(INC)
	@mv ft_printf/libftprintf.a $(NAME)
	@ar rc $(NAME) $(FILEO)
	@ranlib $(NAME)

clean:
	@Make clean -C ./ft_printf
	@/bin/rm -f $(FILEO)

fclean: clean
	@Make fclean -C ./ft_printf
	@/bin/rm -f $(NAME)

re: fclean all
