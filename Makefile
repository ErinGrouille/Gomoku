##
## EPITECH PROJECT, 2021
## gomoku
## File description:
## gomoku Makefile
##

CC			=	g++

SRC			:=
ifeq ($(OS),Windows_NT)
	SRC	+=	.\src\main.cpp	\
			.\src\com_protocol.cpp	\
			.\src\martineReborn.cpp	\
			.\src\masks.cpp
else
	SRC	+=	./src/main.cpp	\
			./src/com_protocol.cpp	\
			./src/martineReborn.cpp	\
			./src/masks.cpp
endif

CXXFLAGS	=	-Iinclude -g3 -Wall -Wextra

OBJ			=	$(SRC:.cpp=.o)

NAME		:=
ifeq ($(OS),Windows_NT)
	NAME +=	pbrain-gomoku-ai.exe
else
	NAME +=	pbrain-gomoku-ai
endif

gomo:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

all:	gomo

clean_gomo:
ifeq ($(OS),Windows_NT)
	del $(OBJ)
else
	rm -rf $(OBJ)
endif

clean:	clean_gomo

fclean_gomo:	clean_gomo
ifeq ($(OS),Windows_NT)
	del $(NAME)
else
	rm -rf $(NAME)
endif

fclean: fclean_gomo

re_gomo:	fclean_gomo gomo

re: re_gomo