# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 21:33:17 by amurcia-          #+#    #+#              #
#    Updated: 2022/07/09 20:21:03 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

NAME_C = client

NAME_S = server

SRC_S = server.c utils/ft_atoi.c utils/ft_is_numeric.c utils/ft_putstr.c utils/ft_itoa.c

SRC_C = client.c utils/ft_atoi.c utils/ft_is_numeric.c utils/ft_putstr.c utils/ft_itoa.c

SRC_S_BONUS = server_bonus.c utils_bonus/ft_atoi_bonus.c utils_bonus/ft_is_numeric_bonus.c utils_bonus/ft_putstr_bonus.c utils_bonus/ft_itoa_bonus.c

SRC_C_BONUS = client_bonus.c utils_bonus/ft_atoi_bonus.c utils_bonus/ft_is_numeric_bonus.c utils_bonus/ft_putstr_bonus.c utils_bonus/ft_itoa_bonus.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)

DEPS_C = $(SRC_C:.c=.d)
DEPS_S = $(SRC_S:.c=.d)
DEPS_C_BONUS = $(SRC_C_BONUS:.c=.d)
DEPS_S_BONUS = $(SRC_S_BONUS:.c=.d)

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -MMD

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

-include $(DEPS)

$(NAME) : $(OBJ_C) $(OBJ_S)
	$(CC) $(FLAGS) $(OBJ_C) -o $(NAME_C)
	$(CC) $(FLAGS) $(OBJ_S) -o $(NAME_S)

bonus: $(OBJ_C_BONUS) $(OBJ_S_BONUS)
	$(CC) $(FLAGS) $(OBJ_C_BONUS) -o $(NAME_C)
	$(CC) $(FLAGS) $(OBJ_S_BONUS) -o $(NAME_S)
	touch $@

clean :
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_S)
	$(RM) $(DEPS_C)
	$(RM) $(DEPS_S)
	$(RM) $(OBJ_C_BONUS)
	$(RM) $(OBJ_S_BONUS)
	$(RM) $(DEPS_C_BONUS)
	$(RM) $(DEPS_S_BONUS)

fclean : clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)

re : fclean all

.PHONY : all clean fclean re
