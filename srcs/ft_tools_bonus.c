/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:49:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/23 16:12:29 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

static char	*ft_get_last_strs(char **standart_read)
{
	char	*s;

	s = NULL;
	if (standart_read == NULL)
		return (NULL);
	while (*standart_read != NULL)
		s = *standart_read++;
	return (s);
}

static int	ft_check_if_action_is_correct(int res_gnl, char **standart_read)
{
	char	*action;

	action = ft_get_last_strs(standart_read);
	if (ft_strcmp(action, "pa") == 0 || \
		ft_strcmp(action, "pb") == 0 || \
		ft_strcmp(action, "sa") == 0 || \
		ft_strcmp(action, "sb") == 0 || \
		ft_strcmp(action, "ss") == 0 || \
		ft_strcmp(action, "ra") == 0 || \
		ft_strcmp(action, "rb") == 0 || \
		ft_strcmp(action, "rr") == 0 || \
		ft_strcmp(action, "rra") == 0 || \
		ft_strcmp(action, "rrb") == 0 || \
		ft_strcmp(action, "rrr") == 0 || \
		(ft_strcmp(action, "") == 0 && res_gnl == 0))
		return (0);
	return (-1);
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
		line = ft_strdup("");
	*standart_read = malloc(sizeof(char **) * (*i + 1));
	if (!*standart_read)
	{
		ft_freestrs(tmp_stdin, *i - 1);
		free(line);
		return (-1);
	}
	while (++j < *i - 1 && *tmp_stdin != NULL)
		(*standart_read)[j] = (*tmp_stdin)[j];
	(*standart_read)[j++] = line;
	(*standart_read)[j] = NULL;
	return (res_gnl);
}

int	ft_fetch_actions(char ***standart_read)
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
		{
			free (tmp_stdin);
			tmp_stdin = NULL;
		}
		if (res_gnl == -1 || \
			ft_check_if_action_is_correct(res_gnl, *standart_read) != 0)
		{
			ft_freestrs(standart_read, i);
			return (-1);
		}
	}
	return (0);
}
