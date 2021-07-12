/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:09:07 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/12 18:21:31 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static int	ft_put_argv_in_strs(int argc, unsigned int *size, \
				const char **argv, const char ***strs)
{
	char	*str;
	int		len;

	if (argc == 2)
	{
		if (ft_strchr((argv[1]), ' ') != NULL)
		{
			str = ft_strdup((argv[1]));
			len = ft_strlen(str);
			*strs = (const char **)ft_split(str, ' ');
			free(str);
			if (!*strs)
				return (-1);
			*size = 0;
			while ((*strs)[*size] != NULL)
				*size += 1;
			return (0);
		}
	}
	*size = argc - 1;
	*strs = &(argv[1]);
	return (0);
}

static int	ft_check_is_all_num(unsigned int size, const char **strs)
{
	unsigned int	i;
	int				len;

	i = -1;
	while (++i < size)
	{
		len = ft_strlen(strs[i]);
		if ((strs[i])[0] == '-' || ft_isdigit((strs[i])[0]) == 1)
		{
			while (--len > 0)
			{
				if (ft_isdigit((strs[i])[len]) == 0)
					return (-1);
			}
		}
	}
	return (0);
}

static int	ft_init_stacks(unsigned int size, const char **strs,\
				t_stacks **stack_a, t_stacks **stack_b)
{
	unsigned int	i;
	t_stacks		*tmpstack;

	i = -1;
	*stack_a = NULL;
	*stack_b = NULL;
	while (++i < size)
	{
		tmpstack = ft_stack_new(ft_atoi(strs[i]));
		if (!tmpstack)
			return (-1);
		ft_stack_add_back(stack_a, tmpstack);
	}
	return (0);
}

int	main(int argc, const char **argv)
{
	t_stacks		*stack_a;
	t_stacks		*stack_b;
	unsigned int	size;
	const char		**strs;

	if (argc == 1)
		return (0);
	if (ft_put_argv_in_strs(argc, &size, argv, &strs) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (ft_check_is_all_num(size, strs) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	if (ft_init_stacks(size, strs, &stack_a, &stack_b) != 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_stack_clear(&stack_a);
		return (-1);
	}
	return (ft_push_swap(&stack_a, &stack_b, size));
}
