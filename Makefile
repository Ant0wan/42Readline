# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 07:30:51 by abarthel          #+#    #+#              #
#    Updated: 2020/10/22 07:34:40 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include readline.mk

.PHONY: all clean fclean re objects lib

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "\n\e[38;5;221m%4s [\e[1m$(NAME) built]\n\n\e[0m"
	@printf "\e[38;5;222mTo compile with the $(NAME), use the command-line: \e[0m\e[4m%s main.c -L. -lft\n\e[0m" $(CC)

clean:
	@$(RM) $(OBJECTS) $(DEPENDS)
	@printf "\e[0m$(basename $(NAME)) .o \e[38;5;52mfiles%1sdeleted\n\e[0m"

fclean:
	@$(RM) $(OBJECTS) $(DEPENDS) $(NAME)
	@printf "\e[0m$(NAME)\e[38;5;52m%2sdeleted\n\e[0m"
	@$(RM) test
	@make -j -C 42Libc/ fclean

re: fclean $(NAME)

objects: $(OBJECTS)

lib: $(OBJECTS)
	@make -j -C 42Libc/
	@$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
	@ranlib $(NAME)

test: lib
	$(CC) $(CFLAGS) $(CDEBUG) $(INCLUDES) main.c $(NAME) -ltermcap ./42Libc/libft.a -o test

-include $(DEPENDS)

%.o: %.c Makefile $(addsuffix .mk, $(basename $(NAME)))
	@$(CC) $(CFLAGS) $(CDEBUG) $(INCLUDES) -MMD -MP -c $< -o $@
	@printf "\e[38;5;115m%-24s \e[38;5;191mobject built\n\e[0m" $(notdir $(basename $@))
