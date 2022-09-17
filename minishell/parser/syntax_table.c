/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/13 15:49:32 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_redir(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	if (curr->next->type == REDIR)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_pipe(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_word(t_dlist *curr)
{
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	return (1);
}

int	check_line(t_dlist *curr)
{
	if (curr->next->type == PIPE)
		return (put_syntaxerr_msg(curr->next->token));
	if (curr->next->type == LINE)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}

int	check_bracket(t_dlist *curr)
{
	if (curr->next->type == BRACKET)
		return (put_syntaxerr_msg("("));
	if (curr->next->type == WORD)
		return (put_syntaxerr_msg(curr->next->token));
	return (1);
}
