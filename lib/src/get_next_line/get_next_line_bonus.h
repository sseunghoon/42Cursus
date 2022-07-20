/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 22:09:22 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/10 17:30:05 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

int		ft_malloc_buff(char **buffers, int fd);
int		ft_find_nl(char **buffers, int fd, char **result);
int		ft_realloc_buff(char **buffers, int fd, int n, int buff_len);
char	*ft_buffncat(char **result, char *buff, int n, int ft_buffncat);
char	*get_next_line(int fd);
void	ft_free_all(char **buffers, char **result);
int		ft_read_process(char **buffers, int fd, char **result);

#endif
