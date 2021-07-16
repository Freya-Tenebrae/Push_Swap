/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_informations_stacks.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:27:29 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:38 by cmaginot         ###   ########.fr       */
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

unsigned int	ft_get_size_one_stacks(t_stacks *tmp_stack)
{
	unsigned int	size;

	size = 0;
	while (tmp_stack != NULL)
	{
		size += 1;
		tmp_stack = tmp_stack->next;
	}
	return (size);
}

void	ft_get_size_stacks(t_stacks *tmp_stack_a, t_stacks *tmp_stack_b, \
				unsigned int *size_stack_a, unsigned int *size_stack_b)
{
	*size_stack_a = ft_get_size_one_stacks(tmp_stack_a);
	*size_stack_b = ft_get_size_one_stacks(tmp_stack_b);
}
