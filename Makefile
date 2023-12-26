NAME = push_swap
LIBFT = libft.a
SRCC_FILES =	push_swap.c utils.c lists.c \
				check_args.c swap.c push.c  \
				rotate.c reverse_rotate.c 
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRC:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME) 

$(NAME) : $(OBJ)
		@make -C libft
		$(CC) $(CFLAGS)  $(OBJ) $(INCLUDE) libft/$(LIBFT) -o $(NAME)

clean : 
		@make clean -C libft
		${RM} ${OBJ}


fclean : clean
		@make fclean -C libft
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
