/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_other_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:27:29 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/14 03:23:53 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_print_content_stack(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_putstr("stack a : |");
	if (stack_a != NULL)
	{
		while (stack_a->next != NULL)
		{
			ft_putnbr(stack_a->content);
			ft_putstr(" ");
			stack_a = stack_a->next;
		}
		ft_putnbr(stack_a->content);
	}
	ft_putstr("|\nstack b : |");
	if (stack_b != NULL)
	{
		while (stack_b->next != NULL)
		{
			ft_putnbr(stack_b->content);
			ft_putstr(" ");
			stack_b = stack_b->next;
		}
		ft_putnbr(stack_b->content);
	}
	ft_putstr("|\n");
}

void	ft_print_order_stack(t_stacks *stack_a, t_stacks *stack_b)
{
	ft_putstr("stack a : |");
	if (stack_a != NULL)
	{
		while (stack_a->next != NULL)
		{
			ft_putnbr(stack_a->order);
			ft_putstr(" ");
			stack_a = stack_a->next;
		}
		ft_putnbr(stack_a->order);
	}
	ft_putstr("|\nstack b : |");
	if (stack_b != NULL)
	{
		while (stack_b->next != NULL)
		{
			ft_putnbr(stack_b->order);
			ft_putstr(" ");
			stack_b = stack_b->next;
		}
		ft_putnbr(stack_b->order);
	}
	ft_putstr("|\n");
}

int	ft_found_position_smallest_number(t_stacks *stack)
{
	int	i;
	int	j;
	int	number;

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

int	ft_found_position_bigest_number(t_stacks *stack)
{
	int	i;
	int	j;
	int	number;

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
