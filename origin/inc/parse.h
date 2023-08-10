#ifndef PARSE_H
# define PARSE_H

typedef struct s_lexer{

    void            *tokens;
    struct s_lexer   *next;

}t_lexer;

typedef struct s_env{

    char            *env;
    struct s_env   *next;

}t_env;

typedef struct s_base{
    
    char *first;
    char *middel;
    char *last;

}t_base;

t_env	*ft_addnew_env(char *str);
void	ft_addback_env(t_env *new, t_env **head);

char	*ft_set_prompt(char *user, char *cwd);
char    *ft_get_env_value(t_env *env, char *src);
int     ft_start_shell(t_env **head);

void    handler_int(int sig);
void    ft_set_signals(void);
void    ft_herdoc_quit(void);
void    ft_herdoc_interrupt(pid_t pid);

int     ft_read_input(char *input, int *exit);
int     ft_unclosed_quotes(char *string, char quote);
void    ft_message(int type);
bool    ft_is_quote(char c);
bool	ft_delimeters(char c);
int     ft_check_pipe(char *input, int *exit);
int     ft_find_pipe(char *input, char quote);
int     ft_next_redir(char *input, char quote);

int     ft_redirect_type(char c);
int     ft_not_valid(char *input, int *i);
int     ft_syntaxt_redirect(char *input, char quote, int *exit);

int     ft_herdoc(char *input, int *exit, t_env *current);
int     ft_start_exec(char *delimeter, int *exit_t, t_env *env);
int     ft_find_f_or_l(char *input, char quote, int f_or_l);
char    *ft_extract_token(char *str, int n);

int     ft_typeof_error(int type, int *exit, int value, int ret);
void    ft_free(char *str1, char *str2);
void    ft_start_herdoc(int file, char *delimiter, int *exit_t, t_env *env);
int     ft_fork_herdoc(char *delimiter, int *exit_t, t_env *env);
int     ft_handler(pid_t child, int *exit_t);

void    ft_search_var(char **str, t_env *env, int *stop);
void    ft_search_replace(t_env *env, t_base *data, char **str, int i[3]);
bool    ft_valid_var(char *var_str);
int     ft_find_var_env(char *str);
void    ft_free_count(char *str1, char *str2);
bool    ft_valid_after(char c);
void    ft_check_line(char **str, t_env *env);

void    ft_check_line2(char **str, int *exit_t);
void    ft_search_var2(char **str, int *exit_t, int *stop);
void    ft_search_replace2(int *exit_t, t_base *data, char **str, int i[3]);
void    ft_type_expand(char **str, int *exit_t, t_env *env);

void    ft_session(char *input, int *exit_t, t_env *env);

int     ft_dup_type(int file_desc[2], int type);
void    ft_one_command(char *input, int *exit_t, t_env *env);
void    ft_implement_redirec(char *input);

int     ft_locate_infile(char *input, char **file, int i[2]);
char    *ft_last_file(char *input);
char    *ft_input_file(char *locate);

#endif