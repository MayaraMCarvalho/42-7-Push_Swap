# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 00:40:38 by macarval          #+#    #+#              #
#    Updated: 2023/02/14 02:08:57 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

FILE_PATH		= ./src
OBJS_PATH		= ./obj
LIBFT_PATH		= ./libs/libft/
PRINTF_PATH		= ./libs/ft_printf/

HEADERS			= push_swap.h

PRINTF			= $(PRINTF_PATH)/libftprintf.a

FILE			= push_swap.c verify_args.c libft_custom.c \
				stack.c inserts.c moves.c sorting.c pre_sorting.c \
				print.c getters.c instructions.c remove.c utils.c

IFLAGS			= -I./libs/ft_printf
LFLAGS			= -L./libs/ft_printf -lftprintf
CFLAGS			= -g3 -Wall -Wextra -Werror

CC				= cc
RM				= rm -rf

OBJS			= $(addprefix $(OBJS_PATH)/, $(FILE:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJS_PATH) $(OBJS) 
				@make -C $(PRINTF_PATH)
				@$(CC) $(CFLAGS) -I . $(OBJS)  $(PRINTF) $(LFLAGS) -o $(NAME)
				@echo "Push_Swap created!!"
			
$(OBJS_PATH):
			@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o: $(FILE_PATH)/%.c $(HEADERS)
			@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			@echo "clean Done!"

fclean:		clean
			@make -C $(PRINTF_PATH) fclean
			@$(RM) $(NAME) $(OBJS_PATH)
			@echo "fclean Done!"

re:			fclean all

.PHONY: 	all clean fclean re