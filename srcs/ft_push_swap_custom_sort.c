/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_custom_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:55:03 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:33 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_rotation_part_2(t_stacks **stack_a, t_stacks **stack_b, \
				int n_rotation_b)
{
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
	ft_rotation_part_2(stack_a, stack_b, n_rotation_b);
}

static void	ft_rotation_to_pos(t_stacks **stack_a, t_stacks **stack_b, \
				unsigned int pos_a)
{
	unsigned int	size_stack_a;
	unsigned int	size_stack_b;
	int				n_rotation;

	ft_get_size_stacks(*stack_a, *stack_b, &size_stack_a, \
		&size_stack_b);
	if (pos_a < size_stack_a / 2 || size_stack_a == 1)
		n_rotation = pos_a;
	else
		n_rotation = pos_a - size_stack_a;
	while (n_rotation > 0)
	{
		n_rotation -= 1;
		ft_rotate(stack_a, stack_b, 'a');
	}
	while (n_rotation < 0)
	{
		n_rotation += 1;
		ft_reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	ft_push_swap_custom_sort(t_stacks **stack_a, t_stacks **stack_b, \
			unsigned int size)
{
	unsigned int	i;
	int				n_rotation_a;
	int				n_rotation_b;

	ft_get_optimised_pivot_a(*stack_a, size);
	i = 0;
	while (i++ < size)
	{
		if ((*stack_a)->will_be_push == 0)
			ft_rotate(stack_a, stack_b, 'a');
		else
			ft_push(stack_a, stack_b, 'b');
	}
	while (*stack_b != NULL)
	{
		ft_get_optimised_push_a(*stack_a, *stack_b, &n_rotation_a, \
			&n_rotation_b);
		ft_rotation(stack_a, stack_b, n_rotation_a, n_rotation_b);
		ft_push(stack_a, stack_b, 'a');
	}
	ft_rotation_to_pos(stack_a, stack_b, \
		ft_found_position_smallest_number(*stack_a));
}
