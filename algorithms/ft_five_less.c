/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:50:59 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/14 10:15:05 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_together(int **stack_a, int **stack_b, int first, int second);
static void	ft_separated(int **stack_a, int **stack_b, int first, int second);
static void	ft_four(int **stack_a, int **stack_b, int first);

void	ft_five_less(int **stack_a, int **stack_b)
{
	int	iter;
	int	first;
	int	second;

	iter = 0;
	while (stack_a[0][0] != 3)
	{
		first = ft_find_pos(stack_a, 0);
		second = ft_find_pos(stack_a, 1);
		if (stack_a[0][0] == 4)
			ft_four(stack_a, stack_b, first);
		else
		{
			if (second == (first - 1) || second == (first + 1))
				ft_together(stack_a, stack_b, first, second);
			if (second != (first - 1) && second != (first + 1))
				ft_separated(stack_a, stack_b, first, second);
		}
	}
	ft_three_less(stack_a, stack_b);
	if (stack_b[1][0] < stack_b[1][1])
		ft_sx(stack_a, stack_b, 'b');
	while (stack_b[0][0] != 0)
		ft_px(stack_a, stack_b, 'a');
}

static void	ft_together(int **stack_a, int **stack_b, int first, int second)
{
	int	num_first;
	int	num_sec;

	num_first = stack_a[1][first];
	num_sec = stack_a[1][second];
	if (first == 0 || second == 0)
		ft_px(stack_a, stack_b, 'b');
	else if (first > (stack_a[0][0] / 2) && second > (stack_a[0][0] / 2))
	{
		ft_rrx(stack_a, stack_b, 'a');
		ft_rrx(stack_a, stack_b, 'a');
	}
	else if (first <= (stack_a[0][0] / 2) || second <= (stack_a[0][0] / 2))
	{
		while (stack_a[1][0] != num_first && stack_a[1][0] != num_sec)
			ft_rx(stack_a, stack_b, 'a');
	}
}

static void	ft_separated(int **stack_a, int **stack_b, int first, int sec)
{
	int	num_first;
	int	num_sec;

	num_first = stack_a[1][first];
	num_sec = stack_a[1][sec];
	if (stack_a[0][0] > 4)
	{
		if (first == 0 || sec == 0)
			ft_px(stack_a, stack_b, 'b');
		else if (first == (stack_a[0][0] - 1) || sec == (stack_a[0][0] - 1))
			ft_rrx(stack_a, stack_b, 'a');
		else if ((first > 0 && first < (stack_a[0][0] - 1)) &&
				(sec > 0 && sec < (stack_a[0][0] - 1)))
		{
			while (stack_a[1][0] != num_first && stack_a[1][0] != num_sec)
				ft_rx(stack_a, stack_b, 'a');
		}
	}
}

static void	ft_four(int **stack_a, int **stack_b, int first)
{
	int	num_first;

	num_first = stack_a[1][first];
	if (first == 0)
		ft_px(stack_a, stack_b, 'b');
	else if (first == (stack_a[0][0] - 1))
		ft_rrx(stack_a, stack_b, 'a');
	else
	{
		while (stack_a[1][0] != num_first)
			ft_rx(stack_a, stack_b, 'a');
	}
}
