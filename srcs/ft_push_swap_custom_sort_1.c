/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_custom_sort_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:55:03 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 10:23:45 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_push_b_by_not_ordered(t_stacks **stack_a, t_stacks **stack_b, \
				unsigned int size)
{
	unsigned int	order_act;
	unsigned int	value;
	unsigned int	i;

	order_act = (*stack_a)->order - 1;
	i = 0;
	while (i++ < size)
	{
		value = (*stack_a)->order;
		if (value == order_act + 1)
		{
			ft_rotate(stack_a, stack_b, 'a');
			order_act = value;
		}
		else
			ft_push(stack_a, stack_b, 'b');
	}
}

static void	ft_push_b_by_smaller(t_stacks **stack_a, t_stacks **stack_b, \
				unsigned int size)
{
	unsigned int	content_act;
	unsigned int	value;
	unsigned int	i;

	content_act = (*stack_a)->order;
	i = 0;
	while (i++ < size)
	{
		value = (*stack_a)->order;
		if (value >= content_act)
		{
			ft_rotate(stack_a, stack_b, 'a');
			content_act = value;
		}
		else
			ft_push(stack_a, stack_b, 'b');
	}
}

static void	ft_rotation(t_stacks **stack_a, t_stacks **stack_b, \
				int n_rotation_a, int n_rotation_b)
{
	while (n_rotation_a > 0 && n_rotation_b > 0)
	{
		n_rotation_a -= 1;
		n_rotation_b -= 1;
		ft_rotate(stack_a, stack_b, 'c');
	}
	while (n_rotation_a < 0 && n_rotation_b < 0)
	{
		n_rotation_a += 1;
		n_rotation_b += 1;
		ft_reverse_rotate(stack_a, stack_b, 'c');
	}
	while (n_rotation_a > 0)
	{
		n_rotation_a -= 1;
		ft_rotate(stack_a, stack_b, 'a');
	}
	while (n_rotation_a < 0)
	{
		n_rotation_a += 1;
		ft_reverse_rotate(stack_a, stack_b, 'a');
	}
	while (n_rotation_b > 0)
	{
		n_rotation_b -= 1;
		ft_rotate(stack_a, stack_b, 'b');
	}
	while (n_rotation_b < 0)
	{
		n_rotation_b += 1;
		ft_reverse_rotate(stack_a, stack_b, 'b');
	}
}

void	ft_push_swap_custom_sort(t_stacks **stack_a, t_stacks **stack_b, \
			unsigned int size)
{
	unsigned int	pos_optimised;
	unsigned int	i;
	int				n_rotation_a;
	int				n_rotation_b;

	pos_optimised = ft_get_optimised_pivot_a(*stack_a, size);
	i = 0;
	while (i++ < pos_optimised / 2)
		ft_rotate(stack_a, stack_b, 'a');
	if (pos_optimised % 2 == 0)
		ft_push_b_by_not_ordered(stack_a, stack_b, size);
	else
		ft_push_b_by_smaller(stack_a, stack_b, size);
	while (*stack_b != NULL)
	{
		ft_get_optimised_push_a(*stack_a, *stack_b, &n_rotation_a, \
			&n_rotation_b);
		ft_rotation(stack_a, stack_b, n_rotation_a, n_rotation_b);
		ft_push(stack_a, stack_b, 'a');
	}
	while ((*stack_a)->order != 0)
		ft_rotate(stack_a, stack_b, 'a');
}
