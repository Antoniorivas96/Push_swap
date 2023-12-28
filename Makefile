NAME				= push_swap

LIBFT				= ./libft/libft.a

INC					= include/
SRC_DIR				= source/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/error.c \
						$(SRC_DIR)push_swap/init_a.c \
						$(SRC_DIR)push_swap/init_b.c \
						$(SRC_DIR)push_swap/order_stacks.c \
						$(SRC_DIR)push_swap/order_three.c \
						$(SRC_DIR)push_swap/push_swap_utils.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/push.c \
						$(SRC_DIR)push_swap/rev_rotate.c \
						$(SRC_DIR)push_swap/rotate.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/swap.c \


SRCS 				=  $(PUSH_SWAP_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re