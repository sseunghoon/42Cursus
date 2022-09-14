#include "../minishell.h"

extern int	g_exit_code;

char	*token2env(char *env)
{
	int		i;
	int		j;
	int		env_size;
	char	*new;

	i = 0;
	j = 0;
	env_size = ft_strlen(env);
	while (env[j] != '=')
		j++;
	j++;
	new = ft_strdup(&env[j]);
	return (new);
}

int	empty_env_in_quote(char *token, int i)
{
	int	a;

	a = 0;
	while (token[i + a] == ' ' || token[i + a] == '\''
		|| token[i + a] == '\"' || token[i + a] == '$' || token[i + a])
		a++;
	ft_strlcpy(&token[i], &token[i + a], ft_strlen(&token[i]));
	return (1);
}

char	*switch2env(char *token, t_info *info, int i)
{
	t_dlist	*env;
	int		j;

	env = info->env;
	while (env)
	{
		j = 0;
		while (env->token[j] != '=')
		{
			if (token[i + j + 1] != env->token[j])
				break ;
			j++;
		}
		if (env->token[j] == '='
			&& ((token[i + j + 1] == ' ' || token[i + j + 1] == '\''
					|| token[i + j + 1] == '\"' || token[i + j + 1] == '$'
					|| token[i + j + 1] == '\0')))
			return (token2env(env->token));
		env = env->next;
	}
	empty_env_in_quote(token, i);
	return (NULL);
}

void	normal_expand(t_dlist *curr, t_info *info, int i)
{
	char	*expand;
	char	*exit_code;

	while (curr->token[i] && (curr->token[i] != '\''
			|| curr->token[i] != '\"' || curr->token[i] != ' '))
	{
		if (curr->token[i] == '$')
		{
			if (curr->token[i + 1] == '?')
			{
				exit_code = ft_itoa(g_exit_code);
				curr->token = ft_strrep(curr->token, exit_code, i);
				free(exit_code);
				return ;
			}
			expand = switch2env(curr->token, info, i);
			if (expand)
			{
				curr->token = ft_strrep(curr->token, expand, i);
				free(expand);
			}
			return ;
		}
		i++;
	}
}

int	shell_var_expand(t_dlist *curr, t_info *info, int i)
{
	char	*token;
	char	quote;

	token = curr->token;
	quote = 0;
	while (token[i])
	{
		if (token[i] == '\'' && !quote)
			quote = '\'';
		else if (token[i] == '\'' && quote == '\'')
			quote = 0;
		else if (token[i] == '\"' && !quote)
			quote = '\"';
		else if (token[i] == '\"' && quote == '\"')
			quote = 0;
		else if (token[i] == '$' && quote != '\'')
		{
			normal_expand(curr, info, i);
			quote = 0;
			i = -1;
			token = curr->token;
		}
		i++;
	}
	return (1);
}
