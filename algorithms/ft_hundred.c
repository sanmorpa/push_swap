/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:35:38 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/18 09:44:36 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_pick(int **stack, int t_chunk, int b_chunk);
static void	ft_move_n(int **stack_a, int **stack_b, int move_n);
static void	ft_reorder_b(int **stack_a, int **stack_b, int element, int el_pos);
static int	ft_find_prev(int **stack, int element);

void	ft_hundred(int **stack_a, int **stack_b)
{
	int	chunk_l[3];
	int	last_pos;
	int	last;

	chunk_l[0] = 0;
	chunk_l[1] = stack_a[0][0] / 5;
	chunk_l[2] = 0;
	while (stack_a[0][0] != 0)
	{
		if (chunk_l[2] == chunk_l[1])
		{
			chunk_l[0] = chunk_l[1];
			chunk_l[1] += chunk_l[1];
		}
		ft_move_n(stack_a, stack_b, ft_pick(stack_a, chunk_l[1], chunk_l[0]));
		chunk_l[2]++;
	}
	last_pos = ft_find_pos(stack_b, stack_b[0][0] - 1);
	last = stack_b[1][last_pos];
	ft_top(stack_a, stack_b, last_pos, last);
	while (stack_b[0][0] != 0)
		ft_px(stack_a, stack_b, 'a');
}

static int	ft_pick(int **stack, int t_chunk, int b_chunk)
{
	int	iter_top;
	int	iter_bot;
	int	mean;

	mean = stack[0][0] / 2;
	iter_top = 0;
	iter_bot = stack[0][0] - 1;
	while (iter_top <= mean)
	{
		if (stack[1][iter_top] >= b_chunk && stack[1][iter_top] < t_chunk)
			break ;
		iter_top++;
	}
	while (iter_bot > mean)
	{
		if (stack[1][iter_bot] >= b_chunk && stack[1][iter_bot] < t_chunk)
			break ;
		iter_bot--;
	}
	if ((iter_top - 0) < (stack[0][0] - iter_bot) ||
	((iter_top - 0) == (stack[0][0] - iter_bot) &&
	stack[1][iter_top] < stack[1][iter_bot]))
		return (iter_top);
	return (iter_bot);
}

static void	ft_move_n(int **stack_a, int **stack_b, int move_n)
{
	int	to_move;
	int	iter;
	int	pos_el;

	to_move = stack_a[1][move_n];
	iter = 0;
	pos_el = 0;
	while (stack_a[1][0] != to_move)
	{
		if (move_n > stack_a[0][0] / 2)
			ft_rrx(stack_a, stack_b, 'a');
		else
			ft_rx(stack_a, stack_b, 'a');
	}
	while (iter < stack_b[0][0])
	{
		if (stack_a[1][0] > stack_b[1][iter])
			pos_el++;
		iter++;
	}
	ft_reorder_b(stack_a, stack_b, stack_a[1][0], pos_el);
	ft_px(stack_a, stack_b, 'b');
}

static void	ft_reorder_b(int **stack_a, int **stack_b, int element, int el_pos)
{
	int	iter;
	int	to_top;
	int	el_top;

	iter = 0;
	if (el_pos == 0 || el_pos == stack_b[0][0])
	{
		el_top = ft_find_pos(stack_b, stack_b[0][0] - 1);
		to_top = stack_b[1][el_top];
	}
	else
	{
		el_top = ft_find_prev(stack_b, element);
		to_top = stack_b[1][el_top];
	}
	ft_top(stack_a, stack_b, el_top, to_top);
}

static int	ft_find_prev(int **stack, int element)
{
	int	iter;
	int	pos_ret;
	int	el_ret;

	iter = 0;
	while (iter < stack[0][0])
	{
		if (element > stack[1][iter])
			break ;
		iter++;
	}
	pos_ret = iter;
	el_ret = stack[1][pos_ret];
	iter++;
	while (iter < stack[0][0])
	{
		if (element > stack[1][iter] && stack[1][iter] > el_ret)
		{
			pos_ret = iter;
			el_ret = stack[1][pos_ret];
		}
		iter++;
	}
	return (pos_ret);
}
