# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tishj <tishj@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 12:48:38 by tishj         #+#    #+#                  #
#    Updated: 2021/03/08 23:39:32 by tishj         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libreigns.a
SRC_DIR = ./src
OBJ_DIR = ./obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),1)
	CFLAGS += -g -fsanitize=address
endif

HEADER	=	./incl/reigns.h \
			./lib/vector/incl/vector.h

LIBRARY	=	./lib/vector/libvector.a

TAIL	=	$(foreach lib,$(LIBRARY),-L $(dir $(lib)) $(patsubst lib%.a,-l%,$(notdir $(lib))))

SRC 	=	reigns_init.c \
			reigns_destroy.c \
			reigns_get_input.c \
			action/key_del.c \
			action/key_regular.c \
			action/key_eof.c \
			action/key_down.c \
			action/key_up.c \
			action/key_right.c \
			action/key_left.c \
			action/key_newline.c \
			util/util_atoi.c \
			util/util_strlen.c \
			util/util_bzero.c \
			util/util_strdup.c \
			util/util_memcpy.c \
			util/util_memcmp.c \
			util/util_strncmp.c \
			util/util_strnlen.c \
			util/termcmd.c \
			util/update_cursor.c \
			util/refresh_cursor.c \
			perform_action.c \
			find_hook.c \
			new_hook.c \
			get_hook.c \
			reigns_hook.c

OBJ 	:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

INCL	:=	$(addprefix -I ,$(dir $(HEADER)))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $^ $(INCL) -ltermcap -o $@

$(NAME) : $(LIBRARY) $(OBJ)
	@echo "Compiling $(notdir $@)"
	@ar -rcs $@ $^

./lib/vector/libvector.a:
	@$(MAKE) -sC $(dir $@) DEBUG=$(DEBUG)

all : $(NAME) 

test: all
	$(CC) $(CFLAGS) $(INCL) main.c -L. -lreigns $(TAIL)  -ltermcap -o $@

clean:
	@echo "Cleaning reigns.."
	@$(MAKE) -sC ./lib/vector/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning reigns.."
	@$(MAKE) -sC ./lib/vector/ fclean
	@rm -f $(NAME) test

re: fclean all
