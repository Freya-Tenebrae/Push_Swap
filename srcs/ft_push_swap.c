/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:19:16 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:32 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_check_is_unique(t_stacks *stack_a)
{
	t_stacks	*stackptr;

	while (stack_a != NULL)
	{
		stackptr = stack_a->next;
		while (stackptr != NULL)
		{
			if (stack_a->content == stackptr->content)
				return (-1);
			stackptr = stackptr->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

static int	ft_is_already_sorted(t_stacks **stack_a)
{
	t_stacks	*tmpstack;
	int			number;

	if (stack_a == NULL)
		return (-1);
	tmpstack = *stack_a;
	number = tmpstack->content;
	while (tmpstack != NULL)
	{
		if (tmpstack->content >= number)
			number = tmpstack->content;
		else
			return (1);
		tmpstack = tmpstack->next;
	}
	return (0);
}

static int	ft_replace_next_smallest_number(t_stacks **stack, int number, \
				unsigned int i)
{
	t_stacks	*tmpstack;
	int			new_number;

	if (stack == NULL)
		return (0);
	tmpstack = *stack;
	new_number = number;
	while (tmpstack != NULL)
	{
		if (new_number == number && tmpstack->content > number)
			new_number = tmpstack->content;
		if (tmpstack->content <= new_number && tmpstack->content > number)
		{
			new_number = tmpstack->content;
			tmpstack->order = i;
		}
		tmpstack = tmpstack->next;
	}
	return (new_number);
}

static int	ft_replace_number_by_logical_order(t_stacks **stack_a, \
	unsigned int size)
{
	t_stacks		*tmpstack;
	int				number;
	unsigned int	i;

	if (stack_a == NULL)
		return (-1);
	if (*stack_a == NULL)
		return (-1);
	tmpstack = *stack_a;
	number = tmpstack->content;
	i = 0;
	while (tmpstack != NULL)
	{
		if (tmpstack->content <= number)
		{
			number = tmpstack->content;
			tmpstack->order = i;
		}
		tmpstack = tmpstack->next;
	}
	while (++i < size)
	{
		number = ft_replace_next_smallest_number(stack_a, number, i);
	}
	return (0);
}

int	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, unsigned int size, \
		char ***strs)
{
	if (ft_check_is_unique(*stack_a) == 0)
	{
		if (ft_replace_number_by_logical_order(stack_a, size) == 0)
		{
			if (ft_is_already_sorted(stack_a) == 0)
				;
			else if (size <= 5)
				ft_push_swap_small_stack(stack_a, stack_b, size);
			else if (size <= 800)
				ft_push_swap_custom_sort(stack_a, stack_b, size);
			else
				ft_push_swap_order_radix_sort(stack_a, stack_b, size);
			ft_stack_clear(stack_a);
			ft_freestrs(strs, 0);
			return (0);
		}
	}
	ft_putstr_fd("Error\n", 2);
	ft_stack_clear(stack_a);
	ft_freestrs(strs, 0);
	return (-1);
}

/*
			if (ft_is_already_sorted(stack_a) == 0)
				;
			// else if (size <= 5)
			// 	ft_push_swap_small_stack(stack_a, stack_b, size);
			// else if (size >= 2000)
			// 	ft_push_swap_order_radix_sort(stack_a, stack_b, size);
			// else if (size >= 1000)
			// 	ft_push_swap_quick_sort(stack_a, stack_b, size, 0);
			// else
			ft_push_swap_custom_sort(stack_a, stack_b, size);
			ft_stack_clear(stack_a);
			ft_freestrs(strs, 0);
			return (0);
*/
