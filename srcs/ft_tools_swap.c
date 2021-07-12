/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:20:09 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/12 18:36:44 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_swap_one_stack(t_stacks **stack)
{
	int				tmp_content;
	unsigned int	tmp_order;

	if (stack == NULL)
		return (-1);
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			tmp_content = (*stack)->content;
			tmp_order = (*stack)->order;
			(*stack)->content = ((*stack)->next)->content;
			(*stack)->order = ((*stack)->next)->order;
			((*stack)->next)->content = tmp_content;
			((*stack)->next)->order = tmp_order;
		}
	}
	return (0);
}

int	ft_swap(t_stacks **stack_a, t_stacks **stack_b, char stack_letter)
{
	int	result;

	result = 0;
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
			result += -1;
		if (ft_swap_one_stack(stack_b) != 0)
			result += -1;
		return (result);
	}
	return (0);
}
