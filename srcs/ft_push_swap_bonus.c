/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:49:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/20 17:24:52 by cmaginot         ###   ########.fr       */
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

static int	ft_fetch_one_action(char ***standart_read, char ***tmp_stdin, \
				int *i)
{
	int		j;
	int		res_gnl;
	char	*line;

	*i += 1;
	j = -1;
	line = NULL;
	res_gnl = get_next_line(0, &line);
	*tmp_stdin = *standart_read;
	if (res_gnl == -1)
		*standart_read = NULL;
	else
		*standart_read = malloc(sizeof(char **) * (*i + 1));
	if (!*standart_read)
	{
		ft_freestrs(tmp_stdin, *i);
		free(line);
		return (-1);
	}
	while (++j < *i && *tmp_stdin != NULL)
		(*standart_read)[j] = (*tmp_stdin)[j];
	(*standart_read)[j++] = line;
	(*standart_read)[j] = NULL;
	free(line);
	return (res_gnl);
}

static int	ft_fetch_actions(char ***standart_read)
{
	int		i;
	int		res_gnl;
	char	**tmp_stdin;

	i = 0;
	res_gnl = 1;
	while (res_gnl == 1)
	{
		res_gnl = ft_fetch_one_action(standart_read, &tmp_stdin, &i);
		if (tmp_stdin != NULL)
			free (tmp_stdin);
		if (res_gnl == -1)
			return (-1);
	}
	return (0);
}

static void	ft_exec_actions(char **standart_read, t_stacks **stack_a, \
				t_stacks **stack_b)
{
	while (standart_read++ != NULL)
	{
		if (ft_strcmp(*standart_read, "pa") == 0)
			ft_push(stack_a, stack_b, 'A');
		if (ft_strcmp(*standart_read, "pb") == 0)
			ft_push(stack_a, stack_b, 'B');
		if (ft_strcmp(*standart_read, "sa") == 0)
			ft_swap(stack_a, stack_b, 'A');
		if (ft_strcmp(*standart_read, "sb") == 0)
			ft_swap(stack_a, stack_b, 'B');
		if (ft_strcmp(*standart_read, "ss") == 0)
			ft_swap(stack_a, stack_b, 'C');
		if (ft_strcmp(*standart_read, "ra") == 0)
			ft_rotate(stack_a, stack_b, 'A');
		if (ft_strcmp(*standart_read, "rb") == 0)
			ft_rotate(stack_a, stack_b, 'B');
		if (ft_strcmp(*standart_read, "rr") == 0)
			ft_rotate(stack_a, stack_b, 'C');
		if (ft_strcmp(*standart_read, "rra") == 0)
			ft_reverse_rotate(stack_a, stack_b, 'A');
		if (ft_strcmp(*standart_read, "rrb") == 0)
			ft_reverse_rotate(stack_a, stack_b, 'B');
		if (ft_strcmp(*standart_read, "rrr") == 0)
			ft_reverse_rotate(stack_a, stack_b, 'C');
	}
}

static int	ft_is_sorted(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	(void)stack_a;
	(void)stack_b;
	(void)size;
	//return 0 if sorted, else return 1
	return (0);
}

int	ft_push_swap(t_stacks **stack_a, t_stacks **stack_b, unsigned int size, \
		char ***strs)
{
	char	**standart_read;

	standart_read = NULL;
	if (ft_check_is_unique(*stack_a) == 0)
	{
		if (ft_fetch_actions(&standart_read) == 0)
		{
			ft_exec_actions(standart_read, stack_a, stack_b);
			if (ft_is_sorted(stack_a, stack_b, size) == 0)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			return (0);
		}
	}
	ft_putstr_fd("Error\n", 2);
	ft_stack_clear(stack_a);
	ft_freestrs(strs, 0);
	return (-1);
}
