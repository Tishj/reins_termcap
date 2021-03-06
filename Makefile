# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tishj <tishj@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/03 12:48:38 by tishj         #+#    #+#                  #
#    Updated: 2021/03/06 13:49:26 by tishj         ########   odam.nl          #
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

TAIL	=	$(join $(addprefix -L, $(dir $(LIBRARY))),$(addprefix -l, $(patsubst lib%.a,%,$(notdir $(LIBRARY)))))

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
			util/termcmd.c \
			util/update_cursor.c \
			perform_action.c

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
	@echo $(TAIL)
	@$(MAKE) -sC $(dir $@) DEBUG=$(DEBUG)

all : $(NAME) 

test: all
	$(CC) $(CFLAGS) main.c $(INCL) $(TAIL) -L. -lreigns -L ./lib/vector -lvector -ltermcap -o $@

clean:
	@echo "Cleaning reigns.."
	@$(MAKE) -sC ./lib/vector/ clean
	@rm -f $(OBJ)

fclean: clean
	@echo "Full cleaning reigns.."
	@$(MAKE) -sC ./lib/vector/ fclean
	@rm -f $(NAME) test

re: fclean all
