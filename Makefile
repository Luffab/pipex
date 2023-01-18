NAME = pipex

SRCS =	srcs/main.c \
		srcs/parsing.c \
		srcs/utils.c \
		srcs/pipex.c

FLAGS = -Wall -Wextra -Werror

HEADER_FILE = ./include

HEADERS =	$(HEADER_FILE)/pipex.h \
			libft/libft.h

LIB_NAME = libft/libft.a

OBJS = ${SRCS:.c=.o}

.PHONY: all
.PHONY: clean
.PHONY: fclean
.PHONY: re

$(NAME): $(OBJS) $(LIB_NAME)
	clang $(OBJS) $(LIB_NAME) -o $(NAME)

$(OBJS): %.o: %.c $(HEADERS)
	clang $(FLAGS) -I$(HEADER_FILE) -c $< -o $@

$(LIB_NAME):
	$(MAKE) -C libft


all: $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all