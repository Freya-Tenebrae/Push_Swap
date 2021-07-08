/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:07 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/03 14:22:13 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_check_is_all_num(int argc, const char **argv)
{
	int	i;
	int	len;

	i = 0;
	if (argc < 2)
		return (-1);
	while (++i < argc)
	{
		len = ft_strlen(argv[i]);
		while (--len >= 0)
		{
			if (ft_isdigit((argv[i])[len]) == 0)
				return (-1);
		}
	}
	return (0);
}

static int	ft_init_stacks(int argc, const char **argv, t_stacks **stack_a, \
	t_stacks **stack_b)
{
	int			i;
	t_stacks	*tmpstack;

	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	while (++i < argc)
	{
		tmpstack = ft_stack_new(ft_atoi(argv[i]));
		if (!tmpstack)
		{
			ft_stack_clear(stack_a);
			return (-1);
		}
		ft_stack_add_back(stack_a, tmpstack);
	}
	return (0);
}

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

static void	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	ft_putstr_fd("PUSH_SWAP_STATES : \n- check error OK\n- tools OK\
		\n- swap push rotate and reverse rotate need to be tested\
		\n- sorting algo need to be done\n", 1);
}

int	main(int argc, const char **argv)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (ft_check_is_all_num(argc, argv) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (ft_init_stacks(argc, argv, &stack_a, &stack_b) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (ft_check_is_unique(stack_a) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_stack_clear(&stack_a);
		return (-1);
	}
	ft_push_swap(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
	return (0);
}
