# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:52:30 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/08 19:13:36 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++

CFLAGS			=	-Wall -Werror -Wextra -ansi

NAME			=	ft_retro

SRCS			=	$(NAME).cpp				\
					CoreEngine.cpp			\
					RenderEngine.cpp		\
					GameObject.cpp			\
					Game.cpp

OBJS			=	$(SRCS:.cpp=.o)

INCLUDES		=	-lncurses


all:			$(NAME)

$(NAME):		$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INCLUDES)

%.o:			%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES)

clean:
	rm -rf $(OBJS)

fclean:			clean
	rm -rf $(NAME)

re:				fclean all


.PHONY: all, clean, fclean, re
