/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_quick_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:55:03 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 10:20:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_get_mediane_on_size(t_stacks **stack_a, unsigned int size)
{
	t_stacks		*tmp_stack;
	float			number;
	unsigned int	i;

	tmp_stack = *stack_a;
	number = 0.0;
	i = 0;
	while (tmp_stack != NULL && i++ < size)
	{
		number += (float)tmp_stack->order / (float)size;
		tmp_stack = tmp_stack->next;
	}
	return ((int)number);
}

static int	ft_already_sorted_on_size(t_stacks **stack_a, unsigned int size)
{
	t_stacks		*tmp_stack;
	unsigned int	number;
	unsigned int	i;

	tmp_stack = *stack_a;
	number = tmp_stack->order;
	i = 0;
	while (i++ < size)
	{
		tmp_stack = tmp_stack->next;
		if (tmp_stack->order < number)
			return (-1);
		number = tmp_stack->order;
	}
	return (0);
}

static void	ft_push_swap_underequal_3_alt(t_stacks **stack_a, \
			t_stacks **stack_b, unsigned int i, unsigned int j)
{
	if (i == 2)
	{
		if (j == 1)
			ft_swap(stack_a, stack_b, 'b');
	}
	else if (i == 1)
	{
		ft_reverse_rotate(stack_a, stack_b, 'b');
		if (j == 0)
			ft_swap(stack_a, stack_b, 'b');
	}
	else
	{
		if (j == 2)
		{
			ft_swap(stack_a, stack_b, 'b');
			ft_reverse_rotate(stack_a, stack_b, 'b');
		}
		else
			ft_rotate(stack_a, stack_b, 'b');
	}
}

static void	ft_sort_size(t_stacks **stack_a, t_stacks **stack_b, \
				unsigned int size)
{
	unsigned int	i;
	int				j;
	unsigned int	mediane;

	i = -1;
	j = 0;
	mediane = ft_get_mediane_on_size(stack_a, size);
	while (++i < size)
	{
		if ((*stack_a)->order <= mediane)
			ft_push(stack_a, stack_b, 'b');
		else
		{
			j += 1;
			ft_rotate(stack_a, stack_b, 'a');
		}
	}
	i = 0;
	while (j - i++ > 0)
		ft_reverse_rotate(stack_a, stack_b, 'a');
	if (j > 1)
	{
		if ((*stack_a)->order > ((*stack_a)->next)->order)
			ft_swap(stack_a, stack_b, 'a');
	}
	ft_push_swap_underequal_3_alt(stack_a, stack_b, \
		ft_found_position_smallest_number(*stack_b), \
		ft_found_position_bigest_number(*stack_b));
	while (*stack_b != NULL)
		ft_push(stack_a, stack_b, 'a');
	while (size-- > 0)
		ft_rotate(stack_a, stack_b, 'a');
}

void	ft_push_swap_quick_sort(t_stacks **stack_a, t_stacks **stack_b, \
			unsigned int size, int n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	mediane;

	i = 0;
	j = 0;
	if (size > 5)
	{
		mediane = ft_get_mediane_on_size(stack_a, size);
		while (i++ < size)
		{
			if ((*stack_a)->order <= mediane)
			{
				j++;
				ft_push(stack_a, stack_b, 'b');
			}
			else
				ft_rotate(stack_a, stack_b, 'a');
		}
		i = 0;
		(void)n;
		while (i++ < size - j && n != 0)
			ft_reverse_rotate(stack_a, stack_b, 'a');
		while (*stack_b != NULL)
			ft_push(stack_a, stack_b, 'a');
		ft_push_swap_quick_sort(stack_a, stack_b, j, n + 1);
		ft_push_swap_quick_sort(stack_a, stack_b, size - j, n + 1);
	}
	else
	{
		if (ft_already_sorted_on_size(stack_a, size) != 0)
			ft_sort_size(stack_a, stack_b, size);
		else
		{
			while (i++ < size)
				ft_rotate(stack_a, stack_b, 'a');
		}
	}
}
