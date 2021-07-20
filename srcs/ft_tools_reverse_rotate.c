/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:20:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/20 17:22:26 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_stack_removelast(t_stacks **stack)
{
	t_stacks	*tmp_stack;

	tmp_stack = *stack;
	while (tmp_stack->next != NULL)
	{
		if ((tmp_stack->next)->next == NULL)
			tmp_stack->next = NULL;
		else
			tmp_stack = tmp_stack->next;
	}
}

static void	ft_stack_add_front(t_stacks **astack, t_stacks *new_stack)
{
	if (*astack == 0)
		*astack = new_stack;
	else if (new_stack != 0)
	{
		new_stack->next = *astack;
		*astack = new_stack;
	}
}

static int	ft_reverse_rotate_one_stack(t_stacks **stack)
{
	t_stacks	*tmp_stack;

	if (stack == NULL)
		return (-1);
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			tmp_stack = ft_stack_last(*stack);
			ft_stack_removelast(stack);
			ft_stack_add_front(stack, tmp_stack);
		}
	}
	return (0);
}

static int	ft_reverse_rotate_part_2(t_stacks **stack_a, t_stacks **stack_b, \
		char stack_letter)
{
	int	result;

	result = 0;
	if (stack_letter == 'c')
	{
		ft_putstr_fd("rrr\n", 1);
		if (ft_reverse_rotate_one_stack(stack_a) != 0)
			result += -1;
		if (ft_reverse_rotate_one_stack(stack_b) != 0)
			result += -1;
		return (result);
	}
	else if (stack_letter == 'C')
	{
		if (ft_reverse_rotate_one_stack(stack_a) != 0)
			result += -1;
		if (ft_reverse_rotate_one_stack(stack_b) != 0)
			result += -1;
		return (result);
	}
	return (0);
}

int	ft_reverse_rotate(t_stacks **stack_a, t_stacks **stack_b, char stack_letter)
{
	if (stack_letter == 'a')
	{
		ft_putstr_fd("rra\n", 1);
		return (ft_reverse_rotate_one_stack(stack_a));
	}
	else if (stack_letter == 'A')
		return (ft_reverse_rotate_one_stack(stack_a));
	else if (stack_letter == 'b')
	{
		ft_putstr_fd("rrb\n", 1);
		return (ft_reverse_rotate_one_stack(stack_b));
	}
	else if (stack_letter == 'B')
		return (ft_reverse_rotate_one_stack(stack_b));
	else
	{
		return (ft_reverse_rotate_part_2(stack_a, stack_b, stack_letter));
	}
}
