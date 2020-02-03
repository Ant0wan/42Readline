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

SOURCES	:=	42Libc/src/ds_btree/btree_apply_infix.c \
		42Libc/src/ds_btree/btree_apply_postfix.c \
		42Libc/src/ds_btree/btree_apply_prefix.c \
		42Libc/src/ds_btree/btree_apply_by_level.c \
		42Libc/src/ds_btree/btree_create_node.c \
		42Libc/src/ds_btree/btree_insert_data.c \
		42Libc/src/ds_btree/btree_level_count.c \
		42Libc/src/ds_btree/btree_search_data.c \
		42Libc/src/ds_btree/btree_delete.c \
		42Libc/src/ds_bstree/bstree_remove_data.c \
		42Libc/src/ds_queue/queue_create_node.c \
		42Libc/src/ds_queue/queue_enqueue.c \
		42Libc/src/ds_queue/queue_dequeue.c \
		42Libc/src/ds_queue/queue_front.c \
		42Libc/src/ds_queue/queue_reverse.c \
		42Libc/src/ds_queue/queue_reverse_recursion.c \
		42Libc/src/ds_queue/queue_delete.c \
		42Libc/src/ds_queue/queue_sort.c \
		42Libc/src/ds_queue/queue_isempty.c \
		42Libc/src/ds_queue/queue_size.c \
		42Libc/src/ds_queue/queue_apply_to_each.c \
		42Libc/src/ds_singly_linked_list/ft_lstadd.c \
		42Libc/src/ds_singly_linked_list/ft_lstdel.c \
		42Libc/src/ds_singly_linked_list/ft_lstdelone.c \
		42Libc/src/ds_singly_linked_list/ft_lstiter.c \
		42Libc/src/ds_singly_linked_list/ft_lstmap.c \
		42Libc/src/ds_singly_linked_list/ft_lstnew.c \
		42Libc/src/ds_stack/stack_apply_to_each.c \
		42Libc/src/ds_stack/stack_create_element.c \
		42Libc/src/ds_stack/stack_delete.c \
		42Libc/src/ds_stack/stack_duplicate.c \
		42Libc/src/ds_stack/stack_initialize.c \
		42Libc/src/ds_stack/stack_isempty.c \
		42Libc/src/ds_stack/stack_peek.c \
		42Libc/src/ds_stack/stack_pop.c \
		42Libc/src/ds_stack/stack_pop_get_data.c \
		42Libc/src/ds_stack/stack_push.c \
		42Libc/src/ds_stack/stack_reverse.c \
		42Libc/src/ds_stack/stack_reverse_recursion.c \
		42Libc/src/ds_stack/stack_sort.c \
		42Libc/src/ds_stack/stack_swap.c \
		42Libc/src/f_ctype/ft_isalnum.c \
		42Libc/src/f_ctype/ft_isalpha.c \
		42Libc/src/f_ctype/ft_isascii.c \
		42Libc/src/f_ctype/ft_isdigit.c \
		42Libc/src/f_ctype/ft_tolower.c \
		42Libc/src/f_ctype/ft_toupper.c \
		42Libc/src/f_errno/error_msg.c \
		42Libc/src/f_misc/ft_chrsearch.c \
		42Libc/src/f_misc/ft_ewcsnwidth.c \
		42Libc/src/f_misc/ft_ewcswidth.c \
		42Libc/src/f_misc/ft_ewcwidth.c \
		42Libc/src/f_misc/ft_fgetline.c \
		42Libc/src/f_misc/ft_fprintbits.c \
		42Libc/src/f_misc/ft_fputwcbits.c \
		42Libc/src/f_misc/ft_fputwsbits.c \
		42Libc/src/f_misc/ft_isempty.c \
		42Libc/src/f_misc/ft_isprime.c \
		42Libc/src/f_misc/ft_isprint.c \
		42Libc/src/f_misc/ft_itoa.c \
		42Libc/src/f_misc/ft_memalloc.c \
		42Libc/src/f_misc/ft_memdel.c \
		42Libc/src/f_misc/ft_nmemdel.c \
		42Libc/src/f_misc/ft_numlen.c \
		42Libc/src/f_misc/ft_print_tables.c \
		42Libc/src/f_misc/ft_printbits.c \
		42Libc/src/f_misc/ft_putaddr.c \
		42Libc/src/f_misc/ft_putchar_fd.c \
		42Libc/src/f_misc/ft_putendl.c \
		42Libc/src/f_misc/ft_putendl_fd.c \
		42Libc/src/f_misc/ft_putllnb.c \
		42Libc/src/f_misc/ft_putnbr.c \
		42Libc/src/f_misc/ft_putnbr_base.c \
		42Libc/src/f_misc/ft_putnbr_fd.c \
		42Libc/src/f_misc/ft_putnbr_lowhexa.c \
		42Libc/src/f_misc/ft_putnbr_octal.c \
		42Libc/src/f_misc/ft_putnbr_upphexa.c \
		42Libc/src/f_misc/ft_putstr.c \
		42Libc/src/f_misc/ft_putstr_fd.c \
		42Libc/src/f_misc/ft_putuint.c \
		42Libc/src/f_misc/ft_putuint_octal.c \
		42Libc/src/f_misc/ft_putwcbits.c \
		42Libc/src/f_misc/ft_putwstr.c \
		42Libc/src/f_misc/ft_resolvepath.c \
		42Libc/src/f_misc/ft_sortopt.c \
		42Libc/src/f_misc/ft_str_is_alpha.c \
		42Libc/src/f_misc/ft_str_is_lowercase.c \
		42Libc/src/f_misc/ft_str_is_numeric.c \
		42Libc/src/f_misc/ft_str_is_printable.c \
		42Libc/src/f_misc/ft_str_is_uppercase.c \
		42Libc/src/f_misc/ft_strclen.c \
		42Libc/src/f_misc/ft_strclr.c \
		42Libc/src/f_misc/ft_strdel.c \
		42Libc/src/f_misc/ft_strendcpy.c \
		42Libc/src/f_misc/ft_strequ.c \
		42Libc/src/f_misc/ft_striter.c \
		42Libc/src/f_misc/ft_striteri.c \
		42Libc/src/f_misc/ft_strjoin.c \
		42Libc/src/f_misc/ft_strmap.c \
		42Libc/src/f_misc/ft_strmapi.c \
		42Libc/src/f_misc/ft_strnequ.c \
		42Libc/src/f_misc/ft_strnew.c \
		42Libc/src/f_misc/ft_strnjoin.c \
		42Libc/src/f_misc/ft_strrep.c \
		42Libc/src/f_misc/ft_strsplit.c \
		42Libc/src/f_misc/ft_strsplit_whitespaces.c \
		42Libc/src/f_misc/ft_strsub.c \
		42Libc/src/f_misc/ft_strtrim.c \
		42Libc/src/f_misc/ft_swap.c \
		42Libc/src/f_misc/ft_tabcpy.c \
		42Libc/src/f_misc/ft_tabdel.c \
		42Libc/src/f_misc/ft_tablen.c \
		42Libc/src/f_misc/ft_tabmalloc.c \
		42Libc/src/f_misc/get_next_line.c \
		42Libc/src/f_misc/utf8.c \
		42Libc/src/f_ncurses/ft_getch.c \
		42Libc/src/f_stdio/ft_perror.c \
		42Libc/src/f_stdio/ft_putchar.c \
		42Libc/src/f_stdio/ft_strerror.c \
		42Libc/src/f_stdio/printf/cast.c \
		42Libc/src/f_stdio/printf/dispatcher.c \
		42Libc/src/f_stdio/printf/format.c \
		42Libc/src/f_stdio/printf/ft_asprintf.c \
		42Libc/src/f_stdio/printf/ft_b.c \
		42Libc/src/f_stdio/printf/ft_chr.c \
		42Libc/src/f_stdio/printf/ft_double.c \
		42Libc/src/f_stdio/printf/ft_dprintf.c \
		42Libc/src/f_stdio/printf/ft_expand_ret.c \
		42Libc/src/f_stdio/printf/ft_hexa.c \
		42Libc/src/f_stdio/printf/ft_n.c \
		42Libc/src/f_stdio/printf/ft_nbr.c \
		42Libc/src/f_stdio/printf/ft_octal.c \
		42Libc/src/f_stdio/printf/ft_p.c \
		42Libc/src/f_stdio/printf/ft_printf.c \
		42Libc/src/f_stdio/printf/ft_printf_prs.c \
		42Libc/src/f_stdio/printf/ft_str.c \
		42Libc/src/f_stdio/printf/ft_unbr.c \
		42Libc/src/f_stdio/printf/ft_vasprintf.c \
		42Libc/src/f_stdio/printf/ft_vdprintf.c \
		42Libc/src/f_stdio/printf/ft_y.c \
		42Libc/src/f_stdio/printf/prefix.c \
		42Libc/src/f_stdio/printf/prs_get.c \
		42Libc/src/f_stdio/printf/str_format.c \
		42Libc/src/f_stdio/printf/wrapper.c \
		42Libc/src/f_stdlib/ft_atoi.c \
		42Libc/src/f_stdlib/ft_getenv.c \
		42Libc/src/f_stdlib/ft_realpath.c \
		42Libc/src/f_stdlib/ft_setenv.c \
		42Libc/src/f_stdlib/ft_unsetenv.c \
		42Libc/src/f_string/ft_memccpy.c \
		42Libc/src/f_string/ft_memchr.c \
		42Libc/src/f_string/ft_memcmp.c \
		42Libc/src/f_string/ft_memcpy.c \
		42Libc/src/f_string/ft_memmove.c \
		42Libc/src/f_string/ft_memset.c \
		42Libc/src/f_string/ft_strcat.c \
		42Libc/src/f_string/ft_strchr.c \
		42Libc/src/f_string/ft_strcmp.c \
		42Libc/src/f_string/ft_strcpy.c \
		42Libc/src/f_string/ft_strdup.c \
		42Libc/src/f_string/ft_strlcat.c \
		42Libc/src/f_string/ft_strlen.c \
		42Libc/src/f_string/ft_strncat.c \
		42Libc/src/f_string/ft_strncmp.c \
		42Libc/src/f_string/ft_strncpy.c \
		42Libc/src/f_string/ft_strndup.c \
		42Libc/src/f_string/ft_strnstr.c \
		42Libc/src/f_string/ft_strrchr.c \
		42Libc/src/f_string/ft_strsep.c \
		42Libc/src/f_string/ft_strstr.c \
		42Libc/src/f_string/ft_strtok.c \
		42Libc/src/f_strings/ft_bzero.c \
		42Libc/src/f_strings/ft_strcasecmp.c \
		42Libc/src/f_unistd/ft_getopt_gnu.c \
		42Libc/src/f_unistd/ft_getopt_osx.c \
		42Libc/src/f_wchar/ft_fputwc.c \
		42Libc/src/f_wchar/ft_fputws.c \
		42Libc/src/f_wchar/ft_wcscmp.c \
		42Libc/src/f_wchar/ft_wcscpy.c \
		42Libc/src/f_wchar/ft_wcslen.c

SOURCES	+=	bind.c \
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
		quotes.c \
		completion.c \
		readdir.c \
		history.c

OBJECTS := $(patsubst %.c,%.o,$(addprefix $(SOURCES_PATH), $(SOURCES)))

DEPENDS := $(patsubst %.c,%.d,$(addprefix $(SOURCES_PATH), $(SOURCES)))

ARFLAGS := rc

INCLUDES := -I ./42Libc/include

#CFLAGS += -Wall -Werror -Wextra -ansi -std=c99 -D_POSIX_C_SOURCE -fno-builtin -O2
CFLAGS += -std=c99 -D_POSIX_C_SOURCE

CDEBUG := -g3 -fsanitize=address
