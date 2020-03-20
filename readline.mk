# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rdle.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 14:45:47 by abarthel          #+#    #+#              #
#    Updated: 2020/03/02 16:27:35 by snunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = readline.a

SOURCES_PATH :=	./

SOURCES	:= 	main.c \
		autocomplete.c \
		avl_fill.c \
		avl_sort.c \
		avl_utils.c \
		bind.c \
		command_complete.c \
		display.c \
		emacs_keymap.c \
		fill_data.c \
		history.c \
		history_expand.c \
		history_lookup.c \
		history_utils.c \
		init.c \
		input.c \
		quotes.c \
		readline.c \
		signals.c \
		terminal.c \
		text2.c \
		text3.c \
		text4.c \
		text5.c \
		text6.c \
		text7.c \
		text8.c \
		text.c \
		text_hist.c \
		tty.c \
		utils.c \
		utils_suite2.c \
		utils_suite.c \
		vim.c \
		vim_keymap.c


OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

ARFLAGS := rc

INCLUDES := -I ./42Libc/include

#CFLAGS += -Wall -Werror -Wextra -ansi -std=c99 -D_POSIX_C_SOURCE=200809L -fno-builtin -O2
CFLAGS += -std=c99 -D_POSIX_C_SOURCE=200809L

CDEBUG := -g3 -fsanitize=address
