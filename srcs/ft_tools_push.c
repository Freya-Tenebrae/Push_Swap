/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:20:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:39 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_push_stackone_to_stacktwo(t_stacks **stack_one, \
	t_stacks **stack_two)
{
	t_stacks	*tmp_stack;

	if (stack_one == NULL || stack_two == NULL)
		return (-1);
	if (*stack_one != NULL)
	{
		tmp_stack = (*stack_one)->next;
		if (*stack_two != NULL)
			(*stack_one)->next = (*stack_two);
		else
			(*stack_one)->next = NULL;
		*stack_two = *stack_one;
		*stack_one = tmp_stack;
	}
	return (0);
}

int	ft_push(t_stacks **stack_a, t_stacks **stack_b, char stack_letter)
{
	if (stack_letter == 'a')
	{
		ft_putstr_fd("pa\n", 1);
		return (ft_push_stackone_to_stacktwo(stack_b, stack_a));
	}
	else if (stack_letter == 'b')
	{
		ft_putstr_fd("pb\n", 1);
		return (ft_push_stackone_to_stacktwo(stack_a, stack_b));
	}
	else
		return (-1);
}
