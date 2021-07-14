/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_small_stack.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:50:42 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/14 03:23:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_push_swap_underequal_3_part2(t_stacks **stack_a, \
			t_stacks **stack_b, int i, int j)
{
	if (j == 2)
	{
		if (i == 1)
			ft_swap(stack_a, stack_b, 'a');
	}
	else if (j == 1)
	{
		ft_reverse_rotate(stack_a, stack_b, 'a');
		if (i == 0)
			ft_swap(stack_a, stack_b, 'a');
	}
	else
	{
		if (i == 2)
		{
			ft_swap(stack_a, stack_b, 'a');
			ft_reverse_rotate(stack_a, stack_b, 'a');
		}
		else
			ft_rotate(stack_a, stack_b, 'a');
	}
}

static void	ft_push_swap_underequal_3_part1(t_stacks **stack_a, \
			t_stacks **stack_b, unsigned int size)
{
	int	i;
	int	j;

	if (size == 2)
	{
		if (ft_found_position_smallest_number(*stack_a) == 1)
			ft_swap(stack_a, stack_b, 'a');
	}
	else if (size == 3)
	{
		i = ft_found_position_smallest_number(*stack_a);
		j = ft_found_position_bigest_number(*stack_a);
		ft_push_swap_underequal_3_part2(stack_a, stack_b, i, j);
	}
}

void	ft_push_swap_small_stack(t_stacks **stack_a, t_stacks **stack_b, \
			unsigned int size)
{
	unsigned int	i;

	while (size > 3)
	{
		i = ft_found_position_smallest_number(*stack_a);
		if (i == 1)
			ft_swap(stack_a, stack_b, 'a');
		else if (i <= (size / 2))
		{
			while (i-- > 0)
				ft_rotate(stack_a, stack_b, 'a');
		}
		else
		{
			while (i++ < size)
				ft_reverse_rotate(stack_a, stack_b, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
		size--;
	}
	ft_push_swap_underequal_3_part1(stack_a, stack_b, size);
	while (*stack_b != NULL)
		ft_push(stack_a, stack_b, 'a');
}
