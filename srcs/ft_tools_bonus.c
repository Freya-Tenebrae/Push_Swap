/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaginot <cmaginot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:49:26 by cmaginot          #+#    #+#             */
/*   Updated: 2021/07/21 14:26:51 by cmaginot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

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
		ft_freestrs(tmp_stdin, *i);
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
		if (res_gnl == -1)
		{
			ft_freestrs(&tmp_stdin, i);
			return (-1);
		}
	}
	return (0);
}
