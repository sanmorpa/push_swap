/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:43:49 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/31 12:52:29 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix(int **stack_a, int **stack_b)
{
	int	iter;
	int	bit;
	int	number;

	bit = 0;
	number = stack_a[0][0];
	while (ft_check_order(stack_a) == 0 || stack_a[0][0] != number)
	{
		iter = 0;
		while (iter < number)
		{
			if (stack_a[1][0] & (1 << bit))
				ft_rx(stack_a, stack_b, 'a');
			else
				ft_px(stack_a, stack_b, 'b');
			iter++;
		}
		while (stack_b[0][0] != 0)
			ft_px(stack_a, stack_b, 'a');
		bit++;
	}
}
