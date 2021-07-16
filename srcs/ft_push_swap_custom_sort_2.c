/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_custom_sort_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:18:08 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/15 20:28:16 by cmaginot         ###   ########.fr       */
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

unsigned int	ft_get_optimised_pivot_a(t_stacks *tmp_stack, unsigned int size)
{
	unsigned int	pos_stack;
	unsigned int	pos_optimised;
	unsigned int	old_number;

	if (tmp_stack == NULL)
		return (-1);
	pos_stack = 0;
	pos_optimised = 0;
	old_number = 0;
	while (tmp_stack != NULL)
	{
		ft_get_optimized_pivot_by_order(tmp_stack, &pos_stack, \
			&pos_optimised, &old_number);
		ft_get_optimized_pivot_greater(tmp_stack, &pos_stack, \
			&pos_optimised, &old_number);
		if (old_number > size / 2)
			return (pos_optimised);
		tmp_stack = tmp_stack->next;
	}
	return (pos_optimised);
}
