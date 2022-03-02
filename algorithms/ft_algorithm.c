/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:30:30 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 10:12:16 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_algorithm(int **stack_a, int **stack_b)
{
	if (ft_check_order(stack_a) == 0)
	{
		if (stack_a[0][0] <= 3)
			ft_three_less(stack_a, stack_b);
		if (stack_a[0][0] > 3 && stack_a[0][0] <= 5)
			ft_five_less(stack_a, stack_b);
		if (stack_a[0][0] > 5 && stack_a[0][0] <= 100)
			ft_hundred(stack_a, stack_b);
		if (stack_a[0][0] > 100)
			ft_radix(stack_a, stack_b);
	}
}
