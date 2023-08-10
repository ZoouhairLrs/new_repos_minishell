#ifndef ZORO_H
# define ZORO_H

# include <stdio.h> 
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <stdbool.h>
# include <fcntl.h> 
# include "../libft/libft.h"
# include "parse.h"

# define SQ 39
# define DQ 34

# define FALSE 0
# define TRUE 1

# define INPUT 0
# define OUTPUT 1

# define OFF -1

# define INTERRUPT 128

# define BLUE "\001\033[1;94m\002"
# define WA "\033[0;37m"

void ft_data(t_env **head);

#endif