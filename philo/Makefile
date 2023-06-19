# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:54:56 by abait-ta          #+#    #+#              #
#    Updated: 2023/06/19 16:14:47 by abait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ./GLOBAL_MAIN/global_main.c ./GLOBAL_MAIN/tools.c ./Analyse/input_analyse.c  ./set_up_infra/making_infra.c \
	  ./thread_manipulation/thread_creation_manipulation.c 
	  

CC = cc

RM = rm -rf

NAME = philo

OBJ = ${SRC:.c=.o}

CFLAGS =  -Wall -Wextra -Werror  -pthread 

HEADER = ./header/philo.h

all : $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@$(CC) -o $@  $(OBJ)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@		

clean :
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

norm :
		norminette

.PHONY: clean fclean all re NAME

