# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tishj <tishj@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 13:36:40 by tishj         #+#    #+#                  #
#    Updated: 2021/03/06 12:40:00 by tishj         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj
INCL_DIR = ./incl

HEADER	=	vector.h
HEADER	:=	$(addprefix $(INCL_DIR)/, $(HEADER))

ifeq ($(DEBUG),1)
	CFLAGS += -g -fsanitize=address
endif

SRC 	=	vec_add.c \
			vec_destroy.c \
			vec_getref.c \
			vec_new.c \
			vec_del.c

OBJ 	:=	$(SRC:%.c=$(OBJ_DIR)/%.o)
SRC		=	$(SRC:%.c=$(SRC_DIR)/%.c)
INCL	:=	$(addprefix -I ,$(INCL_DIR))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Compiling $@"
	@ar -rcs $@ $^

clean:
	@echo "Cleaning vector.."
	@rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning vector.."
	@rm -f $(NAME)

re: fclean all
