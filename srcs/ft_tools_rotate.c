/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:20:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/08 12:49:57 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_rotate_one_stack(t_stacks **stack)
{
	t_stacks	*tmp_stack;

	if (stack == NULL)
		return (-1);
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			tmp_stack = (*stack);
			*stack = (*stack)->next;
			tmp_stack->next = NULL;
			ft_stack_add_back(stack, tmp_stack);
		}
	}
	return (0);
}

int	ft_rotate(t_stacks **stack_a, t_stacks **stack_b, char stack_letter)
{
	int result;

	result = 0;
	if (stack_letter == 'a')
	{
		ft_putstr_fd("ra\n", 1);
		return (ft_rotate_one_stack(stack_a));
	}
	else if (stack_letter == 'b')
	{
		ft_putstr_fd("rb\n", 1);
		return (ft_rotate_one_stack(stack_b));
	}
	else if (stack_letter == 'c')
	{
		ft_putstr_fd("rr\n", 1);
		if (ft_rotate_one_stack(stack_a) != 0)
			result += -1;
		if (ft_rotate_one_stack(stack_b) != 0)
			result += -1;
		return (result);
	}
	return (0);
}
