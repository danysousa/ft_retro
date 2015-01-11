# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:52:30 by rbenjami          #+#    #+#              #
#    Updated: 2015/01/11 13:44:09 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	g++

CFLAGS			=	-Wall -Werror -Wextra -ansi

NAME			=	ft_retro

SRCS			=	$(NAME).cpp							\
					FtRetroGame.cpp						\
					\
					GameEngine/CoreEngine.cpp			\
					GameEngine/RenderEngine.cpp			\
					GameEngine/GameObject.cpp			\
					GameEngine/Vector2f.cpp				\
					GameEngine/GameComponent.cpp		\
					GameEngine/Input.cpp				\
					GameEngine/Game.cpp					\
					\
					GameObjects/Player.cpp				\
					GameObjects/Bullet.cpp				\
					\
					GameComponents/DisplayComponent.cpp	\
					GameComponents/MoveComponent.cpp	\
					GameComponents/MoveKeyComponent.cpp

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
