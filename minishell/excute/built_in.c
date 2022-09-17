/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/14 09:16:25 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_echo_option(char *arg)
{
	int	i;

	if (arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo(t_dlist *list)
{
	int		i;
	int		print_i;
	int		opt;
	char	**argv;

	i = 0;
	opt = 0;
	argv = make_str_arr(list->next);
	while (argv[i] && is_echo_option(argv[i]))
		i++;
	if (i > 0)
		opt = 1;
	print_i = i;
	while (argv[i])
	{
		if (i == print_i)
			write(1, argv[i], ft_strlen(argv[i]));
		else if (write(1, " ", 1))
			write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (!opt)
		printf("\n");
	free(argv);
	return (0);
}

int	pwd(void)
{
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (!tmp)
		return (0);
	else
	{
		printf("%s\n", tmp);
		free(tmp);
	}
	return (0);
}

int	mini_exit(t_dlist *list)
{
	unsigned char	exit_code;

	if (list->next && !ft_isdigit_str(list->next->token))
	{
		ft_putstr_fd("exit\nmorningshell: exit: ", 2);
		ft_putstr_fd(list->next->token, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	if (list->next && list->next->next)
		return (put_str_err(list, "too many arguments"));
	if (list->next)
		exit_code = ft_atoi(list->next->token);
	else
		exit_code = 0;
	printf("exit\n");
	exit(exit_code);
}

int	built_in(t_info *info, t_tree *myself)
{
	char	*token;

	token = myself->dlist->token;
	if (!ft_strncmp(token, "echo", 5))
		return (echo(myself->dlist));
	else if (!ft_strncmp(token, "cd", 3))
		return (cd(info, myself->dlist));
	else if (!ft_strncmp(token, "unset", 6))
		return (unset(info, myself->dlist, 0));
	else if (!ft_strncmp(token, "env", 4))
		return (env(info, 0));
	else if (!ft_strncmp(token, "pwd", 4))
		return (pwd());
	else if (!ft_strncmp(token, "export", 7))
		return (export(info, myself->dlist));
	else if (!ft_strncmp(token, "exit", 5))
		return (mini_exit(myself->dlist));
	return (-1);
}
