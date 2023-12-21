NAME = push_swap
LIBFT = libft.a
SRCC_FILES =	 utils.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
OBJ = ${SRCC:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAME) 

$(NAME) : $(OBJ)
		@make -C libft
		$(CC) $(CFLAGS) src/push_swap.c $(OBJ) $(INCLUDE) libft/$(LIBFT) -o $(NAME)

clean : 
		@make clean -C libft
		${RM} ${OBJ}


fclean : clean
		@make fclean -C libft
		${RM} $(NAME)
		${RM} $(LIBFT)

re: fclean all

.PHONY:		all clean fclean re