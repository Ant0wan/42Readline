# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rdle.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2019/12/18 12:15:30 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = readline.a

SOURCES_PATH :=	./

SOURCES	:=	bind.c \
		display.c \
		emacs_keymap.c \
		init.c \
		input.c \
		main.c \
		readline.c \
		terminal.c \
		text.c \
		tty.c \
		utils.c \
		history.c

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

ARFLAGS := rc

#CFLAGS += -Wall -Werror -Wextra -ansi -std=c99 -D_POSIX_C_SOURCE -fno-builtin -O2
CFLAGS += -std=c99 -D_POSIX_C_SOURCE

CDEBUG := -g3 -fsanitize=address
