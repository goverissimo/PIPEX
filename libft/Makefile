NAME = libft.a
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/
all: $(NAME)
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

SRC = 	$(PATH_SRC)ft_atoi.c\
		$(PATH_SRC)ft_bzero.c\
		$(PATH_SRC)ft_calloc.c\
		$(PATH_SRC)ft_isalpha.c\
		$(PATH_SRC)ft_isascii.c\
		$(PATH_SRC)ft_isdigit.c\
		$(PATH_SRC)ft_isprint.c\
		$(PATH_SRC)ft_itoa.c\
		$(PATH_SRC)ft_memcpy.c\
		$(PATH_SRC)ft_memset.c\
		$(PATH_SRC)ft_putchar_fd.c\
		$(PATH_SRC)ft_putendl_fd.c\
		$(PATH_SRC)ft_putnbr_fd.c\
		$(PATH_SRC)ft_putstr_fd.c\
		$(PATH_SRC)ft_split.c\
		$(PATH_SRC)ft_strchr.c\
		$(PATH_SRC)ft_strdup.c\
		$(PATH_SRC)ft_striteri.c\
		$(PATH_SRC)ft_strjoin.c\
		$(PATH_SRC)ft_strlcat.c\
		$(PATH_SRC)ft_strlcpy.c\
		$(PATH_SRC)ft_strlen.c\
		$(PATH_SRC)ft_strmapi.c\
		$(PATH_SRC)ft_strncmp.c\
		$(PATH_SRC)ft_strnstr.c\
		$(PATH_SRC)ft_strrchr.c\
		$(PATH_SRC)ft_strtrim.c\
		$(PATH_SRC)ft_substr.c\
		$(PATH_SRC)ft_tolower.c\
		$(PATH_SRC)ft_toupper.c\
		$(PATH_SRC)ft_memmove.c\
		$(PATH_SRC)ft_memchr.c\
		$(PATH_SRC)ft_memcmp.c\
		$(PATH_SRC)ft_isalnum.c

OBJ = $(patsubst %.c,%.o,$(SRC))

BONUS = $(PATH_SRC)ft_lstadd_back.c\
		$(PATH_SRC)ft_lstadd_front.c\
		$(PATH_SRC)ft_lstclear.c\
		$(PATH_SRC)ft_lstdelone.c\
		$(PATH_SRC)ft_lstiter.c\
		$(PATH_SRC)ft_lstlast.c\
		$(PATH_SRC)ft_lstnew.c\
		$(PATH_SRC)ft_lstsize.c\
		$(PATH_SRC)ft_lstmap.c

BONUS_OBJS		= $(BONUS:.c=.o)

$(NAME): $(OBJ)
#	$(CC) -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all