/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environnement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:08:55 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 13:51:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char *adapt_value(char *value)
{
	char	*str;

	str = ft_strjoin("=", value);
	free(value);
	return (str);
}

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

void		insert_env(char **env, char *name, char *value)
{
	char	*concat;
	int		pos;

	value = adapt_value(value);
	pos = env_get_pos(env, name);
	if (pos == -1)
	{
		concat = ft_strjoin(name, value);
		ft_insert_double_str(&env, concat);
	}
	else
	{
		free(env[pos]);
		env[pos] = ft_strjoin(name, value);
	}
	free(value);
}
		
