/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: littley <littley@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:29:36 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/01 11:27:19 by littley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchrr(char *s, int c);
char	*ft_strdupp(char *s);
char	*ft_str_nl_join(char *last, char *new, char c);
#endif
