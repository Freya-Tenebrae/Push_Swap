/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:07 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/03 14:22:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stacks	*ft_stack_new(int content)
{
	t_stacks	*stack;

	stack = malloc(sizeof(stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->next = NULL;
	return (stack);
}

void	ft_stack_clear(t_stacks **stack)
{
	t_stacks	*stacknext;

	if (stack != NULL)
	{
		while (*stack != NULL)
		{
			stacknext = (*stack)->next;
			*stack = stacknext;
		}
	}
}

t_stacks	*ft_stack_last(t_stacks *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_stack_add_back(t_stacks **astack, t_stacks *new_stack)
{
	t_stacks	*tmp_stack;

	if (astack != NULL)
	{
		if (*astack == NULL)
			*astack = new_stack;
		else if (new_stack != NULL)
		{
			tmp_stack = ft_stack_last(*astack);
			tmp_stack->next = new_stack;
		}
	}
}
