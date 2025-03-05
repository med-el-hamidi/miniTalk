NAME := client
SERVER := server
LIBFTPRINTF := ft_printf/libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

PATH_LIBFTPRINTF := ./ft_printf/

CLIENT_SRCS := client.c \
				input_utils.c \
				client_utils.c
SERVER_SRCS := server.c \
				server_utils.c

CLIENT_OBJCS := $(CLIENT_SRCS:.c=.o)
SERVER_OBJCS := $(SERVER_SRCS:.c=.o)

all: $(NAME) $(SERVER)

$(NAME): $(CLIENT_OBJCS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(CLIENT_OBJCS) -L$(PATH_LIBFTPRINTF) -lftprintf -o $@

$(CLIENT_OBJCS): %.o: %.c client.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(SERVER_OBJCS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJCS) -L$(PATH_LIBFTPRINTF) -lftprintf -o $@

$(SERVER_OBJCS): %.o: %.c server.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	make -C $(PATH_LIBFTPRINTF)

clean:
	make -C $(PATH_LIBFTPRINTF) clean
	rm -f $(CLIENT_OBJCS) $(SERVER_OBJCS)

fclean: clean
	make -C $(PATH_LIBFTPRINTF) fclean
	rm -f $(NAME) $(SERVER)

.PHONY: clean
