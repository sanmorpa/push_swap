/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:37:00 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 10:11:49 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rab(int **stack);

void	ft_rx(int **stack_a, int **stack_b, int flag)
{
	if (flag == 'a')
	{
		ft_rab(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	if (flag == 'b')
	{
		ft_rab(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (flag == 'r')
	{
		ft_rab(stack_a);
		ft_rab(stack_b);
		ft_putstr_fd("rr\n", 1);
	}
}

void	ft_rab(int **stack)
{
	int	temporal;
	int	iter_1;
	int	iter_2;

	temporal = stack[1][0];
	iter_1 = 0;
	iter_2 = 1;
	if (stack[0][0] >= 2)
	{
		while (iter_2 < stack[0][0])
		{
			stack[1][iter_1] = stack[1][iter_2];
			iter_1++;
			iter_2++;
		}
		stack[1][iter_2 - 1] = temporal;
	}
}
