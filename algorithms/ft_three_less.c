/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_less.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:49:10 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/11 12:08:43 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_three_less(int **stack_a, int **stack_b)
{
	if (stack_a[0][0] == 2)
		ft_sx(stack_a, stack_b, 'a');
	else
	{
		while (ft_check_order(stack_a) == 0)
		{
			if (stack_a[1][0] < stack_a[1][2])
				ft_sx(stack_a, stack_b, 'a');
			if (stack_a[1][0] > stack_a[1][2] &&
			stack_a[1][0] > stack_a[1][1])
				ft_rx(stack_a, stack_b, 'a');
			if (stack_a[1][0] > stack_a[1][2] &&
			stack_a[1][0] < stack_a[1][1])
				ft_rrx(stack_a, stack_b, 'a');
		}
	}
}
