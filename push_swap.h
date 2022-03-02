/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:48:21 by samoreno          #+#    #+#             */
/*   Updated: 2022/01/28 13:56:09 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "./ft_libft/libft.h"

void	ft_errors(int argcs, char **argvs, int argcopy);
void	ft_free_stack(int **array);
void	ft_free_split(char **array, int words);
int		ft_count_split(char **split);
void	ft_printerror(void);
int		**ft_stack_a(int argc, char **args);
int		**ft_stack_b(int **stack_a);
void	ft_rx(int **stack_a, int **stack_b, int flag);
void	ft_rab(int **stack);
void	ft_rrx(int **stack_a, int **stack_b, int flag);
void	ft_rrab(int **stack);
void	ft_px(int **stack_a, int **stack_b, int flag);
void	ft_sx(int **stack_a, int **stack_b, int flag);
void	ft_algorithm(int **stack_a, int **stack_b);
int		ft_check_order(int **stack);
void	ft_three_less(int **stack_a, int **stack_b);
void	ft_five_less(int **stack_a, int **stack_b);
int		ft_find_pos(int **stack, int search);
void	ft_hundred(int **stack_a, int **stack_b);
void	ft_top(int **stack_a, int **stack_b, int pos, int element);
void	ft_radix(int **stack_a, int **stack_b);

#endif