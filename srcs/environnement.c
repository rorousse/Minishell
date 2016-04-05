/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:08:55 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 15:44:35 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char		*env_get_value(char **env, char *name)
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


int			env_get_pos(char **env, char *name)
{
	int i;

	i = 0;
	while (env[i] != NULL && ft_str_char_cmp(env[i], name, '=') != 0)
	{
		i++;
	}
	if (env[i] == NULL)
		return (-1);
	return (i);
}

void		insert_env(char ***env, char *name, char *value)
{
	char	*concat;
	int		pos;
	char	*valuead;

	valuead = ft_strjoin("=", value);
	pos = env_get_pos(*env, name);
	if (pos == -1)
	{
		concat = ft_strjoin(name, valuead);
		ft_insert_double_str(env, concat);
		free(concat);
	}
	else
	{
		free(env[0][pos]);
		env[0][pos] = ft_strjoin(name, valuead);
	}
	free(valuead);
}
		
