
S = src/
O = obj/
L = libft/

SOURCES = $Sphilo_main.c $Sphilo.c $Sactions.c $Stime.c $Sfree_death.c

OBJS = $(SOURCES:$S%=$O%.o)

LIB = libft/libft.a
CC = gcc
RM = rm -rf
CFLAGS = -pthread -Wall -Wextra -Werror -g

NAME = philosopher

all: $(NAME)

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(L) --silent
	@$(CC) $(CFLAGS) $(LIB) $^ -o $@
	@echo "\033[0;32m Compilation complétée"

clean: 
		@$(RM) $(OBJS)
		@$(RM) $O
		@make clean -C $(L) --silent
		@echo "\033[0;31m Fichiers .o supprimés"

fclean:	clean

	@$(RM) $(NAME)
	@echo "\033[0;31m executable supprimé "


re:	fclean $(NAME)