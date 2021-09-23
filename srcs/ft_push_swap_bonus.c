/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:49:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/21 14:30:24 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_check_is_unique(t_stacks *stack_a)
{
	t_stacks	*stackptr;

	while (stack_a != NULL)
	{
		stackptr = stack_a->next;
		while (stackptr != NULL)
		{
			if (stack_a->content == stackptr->content)
				return (-1);
			stackptr = stackptr->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

static void	ft_exec_one_actions(char *standart_read, t_stacks **stack_a, \
				t_stacks **stack_b)
{
	if (ft_strcmp(standart_read, "pa") == 0)
		ft_push(stack_a, stack_b, 'A');
	else if (ft_strcmp(standart_read, "pb") == 0)
		ft_push(stack_a, stack_b, 'B');
	else if (ft_strcmp(standart_read, "sa") == 0)
		ft_swap(stack_a, stack_b, 'A');
	else if (ft_strcmp(standart_read, "sb") == 0)
		ft_swap(stack_a, stack_b, 'B');
	else if (ft_strcmp(standart_read, "ss") == 0)
		ft_swap(stack_a, stack_b, 'C');
	else if (ft_strcmp(standart_read, "ra") == 0)
		ft_rotate(stack_a, stack_b, 'A');
	else if (ft_strcmp(standart_read, "rb") == 0)
		ft_rotate(stack_a, stack_b, 'B');
	else if (ft_strcmp(standart_read, "rr") == 0)
		ft_rotate(stack_a, stack_b, 'C');
	else if (ft_strcmp(standart_read, "rra") == 0)
		ft_reverse_rotate(stack_a, stack_b, 'A');
	else if (ft_strcmp(standart_read, "rrb") == 0)
		ft_reverse_rotate(stack_a, stack_b, 'B');
	else if (ft_strcmp(standart_read, "rrr") == 0)
		ft_reverse_rotate(stack_a, stack_b, 'C');
}

static void	ft_exec_all_actions(char **standart_read, t_stacks **stack_a, \
				t_stacks **stack_b)
{
	while (*standart_read != NULL)
	{
		ft_exec_one_actions(*standart_read, stack_a, stack_b);
		standart_read++;
	}
}

static int	ft_is_sorted(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*tmpstack;
	int			number;

	if (stack_a == NULL)
		return (-1);
	tmpstack = *stack_a;
	number = tmpstack->content;
	while (tmpstack != NULL)
	{
		if (tmpstack->content >= number)
			number = tmpstack->content;
		else
			return (1);
		tmpstack = tmpstack->next;
	}
	if (*stack_b == NULL)
		return (0);
	return (1);
}

int	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, unsigned int size, \
		char ***strs)
{
	char	**standart_read;

	(void)size;
	standart_read = NULL;
	if (ft_check_is_unique(*stack_a) == 0)
	{
		if (ft_fetch_actions(&standart_read) == 0)
		{
			ft_exec_all_actions(standart_read, stack_a, stack_b);
			if (ft_is_sorted(stack_a, stack_b) == 0)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			ft_stack_clear(stack_a);
			ft_freestrs(strs);
			ft_freestrs(&standart_read);
			return (0);
		}
	}
	ft_putstr_fd("Error\n", 2);
	ft_stack_clear(stack_a);
	ft_freestrs(strs);
	return (-1);
}
