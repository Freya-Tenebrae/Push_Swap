/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_order_radix_sort.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:55:03 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 18:45:34 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/*
	ordermax_in_binary is equal to the size - 1 converted in number of digit \
	1 or 0
	for example 18 (10010) is equal to 5
*/

static unsigned int	ft_get_order_number_max(int i)
{
	int	j;

	j = 0;
	while ((i >> j) != 0)
		j++;
	return (j - 1);
}

static int	ft_getpowertwo(int i)
{
	int	j;
	int	n;

	j = 0;
	n = 1;
	while (++j < i)
		n *= 2;
	return (n);
}

static unsigned int	ft_push_swap_order_radix_sort_b_to_a(t_stacks **stack_a, \
						t_stacks **stack_b, unsigned int ordermax_in_binary, \
						unsigned int i)
{
	unsigned int	j;
	unsigned int	k;
	unsigned int	l;

	j = ft_get_size_one_stacks(*stack_b);
	k = 0;
	l = 0;
	while (k++ < j)
	{
		if ((i != ordermax_in_binary + 1) && \
			!((*stack_b)->order & ft_getpowertwo(i + 1)))
		{
			ft_rotate(stack_a, stack_b, 'b');
			l++;
		}
		else
			ft_push(stack_a, stack_b, 'a');
	}
	return (l);
}

void	ft_push_swap_order_radix_sort(t_stacks **stack_a, t_stacks **stack_b, \
			unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;
	unsigned int	ordermax_in_binary;

	i = 0;
	l = 0;
	ordermax_in_binary = ft_get_order_number_max(size - 1);
	while (i++ <= ordermax_in_binary)
	{
		j = 0;
		while (j++ < size - l)
		{
			if ((*stack_a)->order & ft_getpowertwo(i))
				ft_rotate(stack_a, stack_b, 'a');
			else
				ft_push(stack_a, stack_b, 'b');
		}
		l = ft_push_swap_order_radix_sort_b_to_a(stack_a, stack_b, \
				ordermax_in_binary, i);
	}
}
