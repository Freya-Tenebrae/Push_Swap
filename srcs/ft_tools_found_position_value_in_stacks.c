/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_found_position_value_in_stacks.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:27:29 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:37 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

unsigned int	ft_get_last_position_in_stack(t_stacks *stack)
{
	unsigned int	i;
	unsigned int	j;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	while (stack != NULL)
	{
		i = j;
		stack = stack->next;
		j++;
	}
	return (i);
}

unsigned int	ft_found_position_bigger_under_than_value(t_stacks *stack, \
					unsigned int value)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	order;
	unsigned int	order_max_under_value;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	order_max_under_value = UINT_MAX;
	while (stack != NULL)
	{
		order = stack->order;
		if (order < value && (order_max_under_value < order || \
			order_max_under_value == UINT_MAX))
		{
			order_max_under_value = stack->order;
			i = j;
		}
		stack = stack->next;
		j++;
	}
	return (i);
}

unsigned int	ft_found_position_smaller_over_than_value(t_stacks *stack, \
					unsigned int value)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	order;
	unsigned int	order_min_over_value;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	order_min_over_value = UINT_MAX;
	while (stack != NULL)
	{
		order = stack->order;
		if (value < order && (order < order_min_over_value || \
			order_min_over_value == UINT_MAX))
		{
			order_min_over_value = stack->order;
			i = j;
		}
		stack = stack->next;
		j++;
	}
	return (i);
}

unsigned int	ft_found_position_smallest_number(t_stacks *stack)
{
	unsigned int	i;
	unsigned int	j;
	int				number;

	if (stack == NULL)
		return (0);
	i = 0;
	j = 0;
	number = stack->content;
	while (stack->next != NULL)
	{
		stack = stack->next;
		j++;
		if (stack->content < number)
		{
			number = stack->content;
			i = j;
		}
	}
	return (i);
}

unsigned int	ft_found_position_bigest_number(t_stacks *stack)
{
	unsigned int	i;
	unsigned int	j;
	int				number;

	if (stack == NULL)
		return (0);
	i = 0;
	j = 0;
	number = stack->content;
	while (stack->next != NULL)
	{
		stack = stack->next;
		j++;
		if (stack->content > number)
		{
			number = stack->content;
			i = j;
		}
	}
	return (i);
}
