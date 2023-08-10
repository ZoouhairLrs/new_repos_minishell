NAME = mini

EXTRA = -Wall -Wextra -Werror -g

LBFLGS	= -lreadline -lft

LIBFT = ./libft/libft.a

HEADERS = zoro.h parse.h

INCLUDE = -I ./inc

LDFLAG += -L./libft

PARSE = ./src/minishell.c ./src/ft_session.c ./src/ft_raport.c

OUTILS = ./outils/ft_linked.c ./outils/ft_signals.c \
		./outils/ft_input.c ./outils/ft_prompt.c	\
		./outils/ft_redirection.c ./outils/ft_herdoc.c \
		./outils/ft_exp_var.c ./outils/ft_exec_herd.c  \
		./outils/ft_exp_exit.c

EXEC = ./exec/ft_one_command.c  ./exec/ft_grap_redirect.c

SRC = $(PARSE) $(OUTILS) $(EXEC)

DIR_OBJ = obj

SRC_OBJ = $(SRC:%.c =$(DIR_OBJ)/%.o)

all: $(NAME)


$(LIBFT):
	make --directory=./libft

$(NAME): $(DIR_OBJ) $(SRC_OBJ) $(LIBFT)
	$(CC) $(EXTRA) $(SRC_OBJ) -o $(NAME) $(LBFLGS) $(LDFLAG)
	
$(DIR_OBJ)/.%o: %.c $(HEADERS)
	$(CC) $(EXTRA) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(DIR_OBJ):
	mkdir $@

