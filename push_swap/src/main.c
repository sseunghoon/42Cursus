/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:18:59 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/28 23:18:59 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	swap(t_deq *a)
{
	
}

// 1번, ./push_swap 1 4 9 -25 13 //  각 인자는 하나의 수를 나타냄
// 2번 ./push_swap "1 5 2 3"   // 공백으로 수가 구분된 하나의 문자열 인자
// 3번 ./push_swap "3 2" 42 11 "21 -2 7" "5"  // 1번과 2번의 혼합
// 1번까지만 하고 bash 와 zsh 에서의 $ARG의 차이를 설명하여 디펜스하거나
// split하고, ft_atoi를 조금 개조해서 
// (+/- 하나까지만 봐주고, 이후부터는 ft_isdigit으로 검사(false면 exit)하면서 변환)
int	main(int argc, char **argv)
{
	int	i;
	t_deq a;
	t_deq b;

	i = 0;
	while (++i < argc)
	{
		add(&a, ft_atoi(argv[i]));
	}
}