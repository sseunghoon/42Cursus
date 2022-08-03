/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:21 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/29 17:15:45 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define BUFF_SIZE 100

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

// send_signal.c
void	put_end(int pid);
void	send_message(char *str, int pid);

// process_signal.c
void	fill_buff(unsigned char *buff, int signum, int *idx, int *cnt_bit);
void	reset_buff(unsigned char *buff, siginfo_t *info, \
					int *idx, int *cnt_bit);
void	sig_handler(int signum, siginfo_t *info, void *context);

#endif
