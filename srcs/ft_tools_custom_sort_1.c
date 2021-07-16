/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_custom_sort_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:18:08 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:36 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_get_optimized_pivot_by_order(t_stacks *tmp_stack, \
				unsigned int *pos_stack, unsigned int *pos_optimised, \
				unsigned int *old_number)
{
	unsigned int	new_number;
	unsigned int	order_act;
	unsigned int	value;

	new_number = 1;
	order_act = tmp_stack->order;
	while (tmp_stack != NULL)
	{
		value = tmp_stack->order;
		if (value == order_act + 1)
		{
			new_number += 1;
			order_act = value;
		}
		tmp_stack = tmp_stack->next;
	}
	if (new_number >= *old_number)
	{
		*pos_optimised = *pos_stack;
		*old_number = new_number;
	}
	*pos_stack += 1;
}

static void	ft_get_optimized_pivot_greater(t_stacks *tmp_stack, \
				unsigned int *pos_stack, unsigned int *pos_optimised, \
				unsigned int *old_number)
{
	unsigned int	new_number;
	unsigned int	content_act;
	unsigned int	value;

	new_number = 1;
	content_act = tmp_stack->order;
	while (tmp_stack != NULL)
	{
		value = tmp_stack->order;
		if (value > content_act)
		{
			new_number += 1;
			content_act = value;
		}
		tmp_stack = tmp_stack->next;
	}
	if (new_number >= *old_number)
	{
		*pos_optimised = *pos_stack;
		*old_number = new_number;
	}
	*pos_stack += 1;
}

static void	ft_optimizing_pivot_by_order(t_stacks **stack_a, \
				unsigned int pos_optimised, unsigned int size)
{
	t_stacks		*tmp_stack;
	unsigned int	order_act;
	unsigned int	value;
	unsigned int	i;

	tmp_stack = *stack_a;
	i = 0;
	while (i++ < pos_optimised)
		tmp_stack = tmp_stack->next;
	order_act = (*stack_a)->order - 1;
	i = 0;
	while (i++ < size)
	{
		value = tmp_stack->order;
		if (value == order_act + 1)
		{
			tmp_stack->will_be_push = 0;
			order_act = value;
		}
		else
			tmp_stack->will_be_push = 1;
		tmp_stack = tmp_stack->next;
		if (tmp_stack == NULL)
			tmp_stack = *stack_a;
	}
}

static void	ft_optimizing_pivot_by_greater(t_stacks **stack_a, \
				unsigned int pos_optimised, unsigned int size)
{
	t_stacks		*tmp_stack;
	unsigned int	content_act;
	unsigned int	value;
	unsigned int	i;

	tmp_stack = *stack_a;
	i = 0;
	while (i++ < pos_optimised)
		tmp_stack = tmp_stack->next;
	content_act = tmp_stack->order;
	i = 0;
	while (i++ < size)
	{
		value = tmp_stack->order;
		if (value > content_act)
		{
			tmp_stack->will_be_push = 0;
			content_act = value;
		}
		else
			tmp_stack->will_be_push = 1;
		tmp_stack = tmp_stack->next;
		if (tmp_stack == NULL)
			tmp_stack = *stack_a;
	}
}

void	ft_get_optimised_pivot_a(t_stacks *tmp_stack, unsigned int size)
{
	unsigned int	pos_stack;
	unsigned int	pos_optimised;
	unsigned int	old_number;

	pos_stack = 0;
	pos_optimised = 0;
	old_number = 0;
	while (tmp_stack != NULL && old_number > size / 2)
	{
		ft_get_optimized_pivot_by_order(tmp_stack, &pos_stack, \
			&pos_optimised, &old_number);
		ft_get_optimized_pivot_greater(tmp_stack, &pos_stack, \
			&pos_optimised, &old_number);
		tmp_stack = tmp_stack->next;
	}
	if (pos_optimised % 2 == 0)
		ft_optimizing_pivot_by_order(&tmp_stack, pos_optimised / 2, size);
	else
		ft_optimizing_pivot_by_greater(&tmp_stack, pos_optimised / 2, size);
}
