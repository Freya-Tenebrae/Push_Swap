/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_custom_sort_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:18:08 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/16 10:24:46 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static void	ft_get_size_stacks(t_stacks *tmp_stack_a, t_stacks *tmp_stack_b, \
				unsigned int *size_stack_a, unsigned int *size_stack_b)
{
	*size_stack_a = 0;
	*size_stack_b = 0;
	while (tmp_stack_a != NULL)
	{
		*size_stack_a += 1;
		tmp_stack_a = tmp_stack_a->next;
	}
	while (tmp_stack_b != NULL)
	{
		*size_stack_b += 1;
		tmp_stack_b = tmp_stack_b->next;
	}
}

static unsigned int	ft_get_bigger_under_than_value(t_stacks *stack, \
						unsigned int value)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	order;
	unsigned int	order_max_under_value;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	order_max_under_value = UINT_MAX;
	while (stack != NULL)
	{
		order = stack->order;
		if (order < value && (order_max_under_value < order || \
			order_max_under_value == UINT_MAX))
		{
			order_max_under_value = stack->order;
			i = j;
		}
		stack = stack->next;
		j++;
	}
	return (i);
}

static unsigned int	ft_get_smaller_over_than_value(t_stacks *stack, \
						unsigned int value)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	order;
	unsigned int	order_min_over_value;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	order_min_over_value = UINT_MAX;
	while (stack != NULL)
	{
		order = stack->order;
		if (value < order && (order < order_min_over_value || \
			order_min_over_value == UINT_MAX))
		{
			order_min_over_value = stack->order;
			i = j;
		}
		stack = stack->next;
		j++;
	}
	return (i);
}

static unsigned int	ft_get_last_position(t_stacks *stack)
{
	unsigned int	i;
	unsigned int	j;

	if (stack == NULL)
		return (0);
	i = UINT_MAX;
	j = 0;
	while (stack != NULL)
	{
		i = j;
		stack = stack->next;
		j++;
	}
	return (i);
}

static unsigned int	ft_get_pos_to_push(t_stacks *tmp_stack_a, \
	unsigned int value)
{
	unsigned int	bigger_under_than_value;
	unsigned int	smaller_over_than_value;
	unsigned int	pos;

	bigger_under_than_value = ft_get_bigger_under_than_value(tmp_stack_a, \
								value);
	smaller_over_than_value = ft_get_smaller_over_than_value(tmp_stack_a, \
								value);
	if (smaller_over_than_value == UINT_MAX)
		pos = ft_found_position_bigest_number(tmp_stack_a);
	else if (bigger_under_than_value == UINT_MAX)
	{
		pos = ft_found_position_smallest_number(tmp_stack_a) - 1;
		if (pos == UINT_MAX)
			pos = ft_get_last_position(tmp_stack_a);
	}
	else
		pos = bigger_under_than_value;
	return (pos);
}

static unsigned int	ft_get_number_of_actions(t_stacks *tmp_stack_a, \
						t_stacks *tmp_stack_b, unsigned int pos_act_to_push_a, \
						unsigned int pos_act_b)
{
	unsigned int	number_total_of_action;
	unsigned int	size_stack_a;
	unsigned int	size_stack_b;
	int				n_rotation_a;
	int				n_rotation_b;

	number_total_of_action = 0;
	ft_get_size_stacks(tmp_stack_a, tmp_stack_b, &size_stack_a, &size_stack_b);
	if (pos_act_to_push_a < size_stack_a / 2 || size_stack_a == 1)
		n_rotation_a = pos_act_to_push_a;
	else
		n_rotation_a = pos_act_to_push_a - size_stack_a;
	if (pos_act_b < size_stack_b / 2 || size_stack_b == 1)
		n_rotation_b = pos_act_b;
	else
		n_rotation_b = pos_act_b - size_stack_b;
	while (n_rotation_a > 0 && n_rotation_b > 0)
	{
		n_rotation_a -= 1;
		n_rotation_b -= 1;
		number_total_of_action += 1;
	}
	while (n_rotation_a < 0 && n_rotation_b < 0)
	{
		n_rotation_a += 1;
		n_rotation_b += 1;
		number_total_of_action += 1;
	}
	if (n_rotation_a > 0)
		number_total_of_action += n_rotation_a;
	else if (n_rotation_a < 0)
		number_total_of_action -= n_rotation_a;
	if (n_rotation_b > 0)
		number_total_of_action += n_rotation_b;
	else if (n_rotation_b < 0)
		number_total_of_action -= n_rotation_b;
	return (number_total_of_action);
}

static void	ft_get_optimised_pivot_b(t_stacks *tmp_stack_a, \
			t_stacks **tmp_stack_b, unsigned int *pos_optimised_a, \
			unsigned int *pos_optimised_b)
{
	t_stacks		*tmp_stack_b_bis;
	unsigned int	pos_act_to_push_a;
	unsigned int	pos_act_b;
	unsigned int	number_of_action_act;
	unsigned int	number_of_action_min;

	tmp_stack_b_bis = *tmp_stack_b;
	pos_act_b = 0;
	number_of_action_min = UINT_MAX;
	while (*tmp_stack_b != NULL)
	{
		pos_act_to_push_a = ft_get_pos_to_push(\
								tmp_stack_a, (*tmp_stack_b)->order) + 1;
		number_of_action_act = ft_get_number_of_actions(tmp_stack_a, \
									tmp_stack_b_bis, pos_act_to_push_a, \
									pos_act_b);
		if (number_of_action_act < number_of_action_min)
		{
			number_of_action_min = number_of_action_act;
			*pos_optimised_a = pos_act_to_push_a;
			*pos_optimised_b = pos_act_b;
		}
		*tmp_stack_b = (*tmp_stack_b)->next;
		pos_act_b += 1;
	}
}

void	ft_get_optimised_push_a(t_stacks *tmp_stack_a, t_stacks *tmp_stack_b, \
			int *n_rotation_a, int *n_rotation_b)
{
	unsigned int	size_stack_a;
	unsigned int	size_stack_b;
	unsigned int	pos_optimised_a;
	unsigned int	pos_optimised_b;

	if (tmp_stack_a != NULL && tmp_stack_b != NULL)
	{
		ft_get_size_stacks(tmp_stack_a, tmp_stack_b, &size_stack_a, \
			&size_stack_b);
		ft_get_optimised_pivot_b(tmp_stack_a, &tmp_stack_b, &pos_optimised_a, \
			&pos_optimised_b);
		if (pos_optimised_a < size_stack_a / 2 || size_stack_a == 1)
			*n_rotation_a = pos_optimised_a;
		else
			*n_rotation_a = pos_optimised_a - size_stack_a;
		if (pos_optimised_b < size_stack_b / 2 || size_stack_b == 1)
			*n_rotation_b = pos_optimised_b;
		else
			*n_rotation_b = pos_optimised_b - size_stack_b;
	}
}
