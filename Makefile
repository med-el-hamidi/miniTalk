NAME := client
SERVER := server
BNAME := client_bonus
BSERVER := server_bonus
LIBFT := libft/libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
PATH_LIBFT := ./libft/

CLIENT_SRCS := client.c \
				input_utils.c \
				client_utils.c
SERVER_SRCS := server.c

BCLIENT_SRCS := client_bonus.c \
				input_utils_bonus.c \
				client_utils_bonus.c
BSERVER_SRCS := server_bonus.c

CLIENT_OBJCS := $(CLIENT_SRCS:.c=.o)
SERVER_OBJCS := $(SERVER_SRCS:.c=.o)

BCLIENT_OBJCS := $(BCLIENT_SRCS:.c=.o)
BSERVER_OBJCS := $(BSERVER_SRCS:.c=.o)

all: $(NAME) $(SERVER)

$(NAME): $(LIBFT) $(CLIENT_OBJCS)
	$(CC) $(CFLAGS) $(CLIENT_OBJCS) -L$(PATH_LIBFT) -lft -o $@

$(CLIENT_OBJCS): %.o: %.c client.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(LIBFT) $(SERVER_OBJCS)
	$(CC) $(CFLAGS) $(SERVER_OBJCS) -L$(PATH_LIBFT) -lft -o $@

$(SERVER_OBJCS): %.o: %.c server.h
	$(CC) $(CFLAGS) -c $< -o $@

dep_libft_objcs:
	make -C $(PATH_LIBFT)

$(LIBFT): dep_libft_objcs
	make -C $(PATH_LIBFT)

bonus: $(BNAME) $(BSERVER)

$(BNAME): $(LIBFT) $(BCLIENT_OBJCS)
	$(CC) $(CFLAGS) $(BCLIENT_OBJCS) -L$(PATH_LIBFT) -lft -o $@

$(BCLIENT_OBJCS): %.o: %.c client_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BSERVER): $(LIBFT) $(BSERVER_OBJCS)
	$(CC) $(CFLAGS) $(BSERVER_OBJCS) -L$(PATH_LIBFT) -lft -o $@

$(BSERVER_OBJCS): %.o: %.c server_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(PATH_LIBFT) clean
	rm -f $(CLIENT_OBJCS) $(SERVER_OBJCS)
	rm -f $(BCLIENT_OBJCS) $(BSERVER_OBJCS)

fclean: clean
	make -C $(PATH_LIBFT) fclean
	rm -f $(NAME) $(SERVER)
	rm -f $(BNAME) $(BSERVER)

re: fclean all

.PHONY: clean dep_libft_objcs
