NAME = push_swap
BONUS = checker
LIBFT = libft.a
SRCC_FILES =	push_swap.c index_funcs.c lists.c \
				check_args.c swap.c push.c stacks.c \
				rotate.c reverse_rotate.c sort_big.c sort_small.c utils.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRC:.c=.o}

BONUS_FILES =	checker_utils.c checker.c validations.c 
BONUS_UTILS = 	src/index_funcs.c src/lists.c \
				src/check_args.c src/swap.c src/push.c \
				src/stacks.c src/rotate.c src/reverse_rotate.c \
				src/sort_big.c src/sort_small.c src/utils.c
BONUS_DIR = bonus/
BONUS_SRC = $(addprefix $(BONUS_DIR), $(BONUS_FILES))
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_UTILS_OBJ = $(BONUS_UTILS:.c=.o)

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME)

$(NAME) : $(OBJ)
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) libft/$(LIBFT) -o $(NAME)
		@echo Compilation Finish

bonus:	$(BONUS_OBJ) $(BONUS_UTILS_OBJ)
		@make -C libft
		@$(CC) $(CFLAGS) $(BONUS_OBJ) $(BONUS_UTILS_OBJ) $(INCLUDE) libft/$(LIBFT) -o $(BONUS)
		@echo Bonus Compiled

clean : 
		@make clean -C libft
		${RM} ${OBJ}
		${RM} ${BONUS_OBJ}

fclean : clean
		@make fclean -C libft
		${RM} $(NAME)
		$(RM) $(BONUS)
		@${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re
