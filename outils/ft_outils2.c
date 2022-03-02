/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:14:13 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 11:25:10 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_pos(int **stack, int search)
{
	int	iter_1;
	int	iter_2;
	int	temp;
	int	pos;

	temp = 0;
	pos = -1;
	iter_1 = 0;
	iter_2 = 0;
	while (pos != search)
	{
		while (iter_2 < stack[0][0])
		{
			if (stack[1][iter_1] > stack[1][iter_2])
				temp++;
			iter_2++;
		}
		if (temp == search)
			pos = temp;
		else
			iter_1++;
		temp = 0;
		iter_2 = 0;
	}
	return (iter_1);
}

void	ft_top(int **stack_a, int **stack_b, int pos, int element)
{
	while (stack_b[1][0] != element)
	{
		if (pos < stack_b[0][0] / 2)
			ft_rx(stack_a, stack_b, 'b');
		else
			ft_rrx(stack_a, stack_b, 'b');
	}
}
