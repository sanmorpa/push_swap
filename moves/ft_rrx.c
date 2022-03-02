/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:37:37 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 10:11:28 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrab(int **stack);

void	ft_rrx(int **stack_a, int **stack_b, int flag)
{
	if (flag == 'a')
	{
		ft_rrab(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (flag == 'b')
	{
		ft_rrab(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (flag == 'r')
	{
		ft_rrab(stack_a);
		ft_rrab(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}

void	ft_rrab(int **stack)
{
	int	temporal;
	int	iter_1;
	int	iter_2;

	iter_1 = stack[0][0] - 1;
	if (stack[0][0] >= 2)
	{
		temporal = stack[1][iter_1];
		iter_2 = iter_1 - 1;
		while (iter_2 >= 0)
		{
			stack[1][iter_1] = stack[1][iter_2];
			iter_1--;
			iter_2--;
		}
		stack[1][0] = temporal;
	}
}
