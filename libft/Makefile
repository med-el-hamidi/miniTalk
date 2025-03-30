NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

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

HEADERS = libft.h $(PATH_UTILS)utils.h $(PATH_SRCS)srcs.h $(PATH_FT_PRINTF)ft_printf.h

SRCS = $(SRCS_LIBFT) $(SRCS_UTILS) $(SRCS_SRCS)
OBJS = $(SRCS:.c=.o)

RM = rm -f

$(NAME): $(OBJS)
	ar -rcs $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
