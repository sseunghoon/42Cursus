/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/15 17:19:08 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <dirent.h>
# include <sys/wait.h>

# define LINE 1
# define PIPE 2
# define REDIR 3
# define WORD 4
# define BRACKET 5

# define VERTICAL 1
# define HORIZONTAL 0

typedef struct s_operation
{
	int	i;
	int	last_idx;
}		t_operation;

typedef struct s_ftool
{
	int		p_fd[2];
	int		status;
	pid_t	pid;
}			t_ftool;

typedef struct s_dlist
{
	struct s_dlist	*next;
	struct s_dlist	*prev;
	char			*token;
	int				type;
}					t_dlist;

typedef struct s_tree
{
	t_dlist				*dlist;
	struct s_tree		*right_child;
	struct s_tree		*left_child;
}						t_tree;

typedef struct s_info
{
	char					quote;
	int						redir_cnt;
	int						redir_out_flag;
	int						redir_in_flag;
	int						tmp_fd;
	int						in_fd;
	int						out_fd;
	int						hd_cnt;
	int						quote_flag;
	int						double_quote_flag;
	int						err_flag;
	int						path_flag;
	struct s_operation		fo;
	struct s_dlist			*env;
	struct s_dlist			*dlist;
	t_tree					*root;
}							t_info;

/* minishell.c */
int		before_cmd(char *str, t_info *info);
int		after_cmd(char *str, t_info *info);
int		init_main(t_info *info);
int		close_main(t_info *info, char *str);

/* signal.c */
void	set_signal_handler(int flag);
void	signal_handler(int signal);
void	set_terminal(void);
void	signal_handler2(int signal);
void	hd_sig(int signal);

/* init.c */
void	init_info(t_info *info);
int		init_env(t_info *info);

/*---parser---*/
	/* lexer.c */
int		lexer(char *str, t_info *info);

	/* input_check.c */
int		input_check(char *str);
int		space_check(char *str);

	/* tokenize.c */	
void	tokenize(t_info *info);

	/* syntax.c, syntax_table.c */
int		put_syntaxerr_msg(char *token);
int		check_syntax(t_info *info);
int		check_redir(t_dlist *curr);
int		check_pipe(t_dlist *curr);
int		check_word(t_dlist *curr);
int		check_line(t_dlist *curr);
int		check_bracket(t_dlist *curr);
/*---parser---*/

/*---minishell/utils---*/
	/* doubly_list.c */
t_dlist	*create_list(void);
void	add_list(t_dlist **list, char *str);
int		delete_node(t_dlist **list, t_dlist *node);
void	delete_dlist(t_dlist *list);
t_dlist	*get_first(t_dlist *curr);

	/* tree.c */
t_tree	*make_tree(t_tree *myself, t_dlist *dlist);
void	free_tree(t_tree *myself);

	/* utils.c */
char	**make_str_arr(t_dlist *curr);
int		puterr_exit_code(char *str, char *arg, int code);
int		put_str_err(t_dlist *list, char *str);
int		ft_free(char **split);
int		ft_isdigit_str(char *str);
void	cut_node(t_dlist *curr, int i);
char	*ft_strrep(char *token, char *value, int i);
/*---minishell/utils---*/

/*---minishell/expand---*/
	/* expand.c */
int		expand(t_info *info, t_tree *myself);
int		shell_var_expand(t_dlist *curr, t_info *info, int i);

	/* wildcard.c */
int		wildcard(t_dlist **now);
int		set_list(t_dlist *curr, t_dlist *new_list);
char	*ft_str_rep_wildcard(char *d_name, char *next_path);
char	*ft_strjoin_free(char *s1, char *s2);
int		filter_wildcard(char *wc, char *str, int i, int j);
/*---minishell/expand---*/

/* minishell/execute */
	/* excute.c */
int		execute(t_info *info, t_tree *myself);
int		execute_word(t_info *info, t_tree *myself);
int		here_doc(t_info *info, t_tree *myself);

	/* excute_redir.c */
int		execute_redir(t_info *info, t_tree *myself);
int		redir_output(t_info *info, t_tree *myself);
int		redir_input(t_info *info, t_tree *myself);
void	flag_on_redirin(t_info *info, t_tree *myself, int *r_fd);
void	first_redir(t_info *info);

	/* excute_pipe.c */
int		execute_pipe(t_info *info, t_tree *myself);

	/* built_in.c */
int		echo(t_dlist *list);
int		pwd(void);
int		mini_exit(t_dlist *list);
int		built_in(t_info *info, t_tree *myself);

	/* environ.c */
int		export(t_info *info, t_dlist *list);
int		unset(t_info *info, t_dlist *list, int i);
int		env(t_info *info, int flag);

	/* cd.c */
int		cd(t_info *info, t_dlist *list);
/* minishell/execute */

#endif
