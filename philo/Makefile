# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:54:56 by abait-ta          #+#    #+#              #
#    Updated: 2023/06/06 16:09:35 by abait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = global_main.c ./Analyse/input_analyse.c 

CC = cc

RM = rm -rf

NAME = philo

OBJ = ${SRC:.c=.o}

CFLAGS =  -Wall -Wextra -Werror

HEADER = philo.h

all : $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@$(CC)  -o $@ $(OBJ) && $(RM) $(OBJ)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@		

clean :
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean all re NAME

