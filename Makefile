NAME := client
SERVER := server
BNAME := client_bonus
BSERVER := server_bonus
LIBFT := libft/libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
PATH_LIBFT := ./libft/
PATH_FT_PRINTF = ft_printf/
PATH_SRCS = $(PATH_FT_PRINTF)srcs/
PATH_UTILS = $(PATH_FT_PRINTF)utils/
SRCS_LIBFT = ft_atoi.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_nbrlen_base.c \
			ft_putchar_fd.c \
			ft_putnbr_base_fd.c \
			ft_putptr_fd.c \
			ft_putstr_fd.c \
			ft_ptrlen.c \
			ft_strncmp.c \
			ft_strlen.c \
			$(PATH_FT_PRINTF)ft_printf.c

SRCS_SRCS = $(PATH_SRCS)ft_handle_flags_and_digits.c \
			$(PATH_SRCS)ft_print_char.c \
			$(PATH_SRCS)ft_print_decimal.c \
			$(PATH_SRCS)ft_print_hex.c \
			$(PATH_SRCS)ft_print_ptr.c \
			$(PATH_SRCS)ft_print_string.c \
			$(PATH_SRCS)ft_output_length_cntl.c

SRCS_UTILS = $(PATH_UTILS)ft_printf_utils.c \
			$(PATH_UTILS)print_decimal_utils.c \
			$(PATH_UTILS)print_hex_utils.c \
			$(PATH_UTILS)print_ptr_utils.c

SRCS_LIBFT := $(addprefix $(PATH_LIBFT), $(SRCS_LIBFT))
SRCS_SRCS := $(addprefix $(PATH_LIBFT), $(SRCS_SRCS))
SRCS_UTILS := $(addprefix $(PATH_LIBFT), $(SRCS_UTILS))

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


$(LIBFT):	$(SRCS_LIBFT) $(SRCS_SRCS) $(SRCS_UTILS) \
			$(PATH_LIBFT)libft.h $(PATH_LIBFT)$(PATH_FT_PRINTF)ft_printf.h \
			$(PATH_LIBFT)$(PATH_SRCS)srcs.h $(PATH_LIBFT)$(PATH_UTILS)utils.h
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

.PHONY: clean
