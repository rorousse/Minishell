/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:08:55 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 14:15:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*env_get_value(char **env, char *name)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (env[i] != NULL && ft_str_char_cmp(env[i], name, '=') != 0)
	{
		i++;
	}
	if (env[i] == NULL)
		return (NULL);
	while (env[i][y] != '=')
		y++;
	return (&(env[i][y + 1]));
}
