/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:20:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/03 14:21:25 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_swap_one_stack(t_stacks **stack)
{
	int	i;

	if (stack == NULL)
		return (-1);
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			i = (*stack)->content;
			(*stack)->content = (*stack)->next->content;
			(*stack)->next->content = i;
		}
	}
	return (0);
}

int	ft_swap(t_stacks **stack_a, t_stacks **stack_b, char stack_letter)
{
	if (stack_letter == 'a')
	{
		ft_putstr_fd("sa\n", 1);
		return (ft_swap_one_stack(stack_a));
	}
	else if (stack_letter == 'b')
	{
		ft_putstr_fd("sb\n", 1);
		return (ft_swap_one_stack(stack_b));
	}
	else if (stack_letter == 'c')
	{
		ft_putstr_fd("ss\n", 1);
		if (ft_swap_one_stack(stack_a) != 0)
			return (-1);
		if (ft_swap_one_stack(stack_a) != 0)
			return (-1);
	}
	return (0);
}
