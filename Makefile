# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tishj <tishj@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 12:48:38 by tishj         #+#    #+#                  #
#    Updated: 2021/03/10 23:12:22 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libreins.a
SRC_DIR = ./src
OBJ_DIR = ./obj

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifeq ($(DEBUG),1)
	CFLAGS += -g -fsanitize=address
else ifeq ($(DEBUG),2)
	CFLAGS += -g
endif

HEADER	=	./incl/reins.h \
			./lib/vector/incl/vector.h

LIBRARY	=	./lib/vector/libvector.a

TAIL	=	$(foreach lib,$(LIBRARY),-L $(dir $(lib)) $(patsubst lib%.a,-l%,$(notdir $(lib))))

SRC 	=	reins_init.c \
			init_keys.c \
			init_cursor.c \
			reins_destroy.c \
			reins_get_input.c \
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
			util/util_strncpy.c \
			print_keycode_formatted.c \
			util/termcmd.c \
			util/update_cursor.c \
			util/refresh_cursor.c \
			create_keycode.c \
			perform_action.c \
			find_key.c \
			new_key.c \
			get_key.c \
			reins_hook.c \
			reins_key.c \
			reins_enable.c \
			reins_disable.c



OBJ 	:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

INCL	:=	$(addprefix -I ,$(dir $(HEADER)))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $(notdir $@)"
	@$(CC) $(CFLAGS) -c $^ $(INCL) $(TAIL) -o $@

$(NAME) : $(OBJ) $(LIBRARY)
	@echo "Compiling $(notdir $@)"
	@ar -rcs $@ $^

./lib/vector/libvector.a:
	@$(MAKE) -sC $(dir $@) DEBUG=$(DEBUG)

all : $(NAME) 

test: all
	$(CC) $(CFLAGS) main.c $(INCL) -L. -lreins $(TAIL) -ltermcap -o $@ 

clean:
	@echo "Cleaning reins.."
	@$(MAKE) -sC ./lib/vector/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning reins.."
	@$(MAKE) -sC ./lib/vector/ fclean
	@rm -f $(NAME) test

re: fclean all

.PHONY: all test clean fclean re
