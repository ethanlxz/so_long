NAME = libft.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

INCLUDE = libft.h
SRCS = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c	ft_memcpy.c	ft_memmove.c ft_strlcpy.c \
		ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c		\
		ft_strdup.c ft_substr.c	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		./printf/ft_basic.c ./printf/ft_convert.c ./printf/ft_print_hex.c ./printf/ft_print_ptr.c ./printf/ft_print_unsigned.c ./printf/ft_printf.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c

SRCSB =	ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		$(SRCS)

OBJSB_DIR = objs/

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

$(OBJSB_DIR)%.o : $(OBJSB)
	@mkdir -p $(OBJSB_DIR)
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): ${OBJSB} 
	ar rcs $(NAME) ${OBJECTS_BONUS_PREFIXED}

all: $(NAME)

clean:
	rm -rf *.o
	

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
	@ar rcs $(NAME) $(OBJECTS_BONUS_PREFIXED)

.PHONY: bonus all clean fclean re