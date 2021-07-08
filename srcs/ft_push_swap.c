/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:50:42 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/08 15:40:40 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_found_position_smallest_number(t_stacks *stack)
{
	int i;
	int j;
	int number;

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

void	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int j;
	int i;

	// ft_print_stack(*stack_a, *stack_b);
	j = 0;
	if (size == 1)
		return ;
	while (++j < size - 1)
	{
		i = ft_found_position_smallest_number(*stack_a);
		if (i == 1)
			ft_swap(stack_a, stack_b, 'a');
		else if (i <= (size / 2))
		{
			while (i > 0)
			{
				ft_rotate(stack_a, stack_b, 'a');
				// ft_print_stack(*stack_a, *stack_b);
				i--;
			}
		}
		else
		{
			while (i < size)
			{
				ft_reverse_rotate(stack_a, stack_b, 'a');
				// ft_print_stack(*stack_a, *stack_b);
				i++;
			}
		}
		ft_push(stack_a, stack_b, 'b');
		// ft_print_stack(*stack_a, *stack_b);
	}
	if ((*stack_a)->content > ((*stack_a)->next)->content)
		ft_swap(stack_a, stack_b, 'a');
	while (*stack_b != NULL)
	{
		ft_push(stack_a, stack_b, 'a');
		// ft_print_stack(*stack_a, *stack_b);
	}
}