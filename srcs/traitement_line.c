/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:21:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/08 11:11:27 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	pathing_part_two(char **chemins, char **commande, char **env)
{
	int		i;
	int		bool;

	i = 0;
	bool = 0;
	while (chemins[i] != NULL && bool == 0)
	{
		free(commande[0]);
		commande[0] = ft_strdup(chemins[i]);
		if (access(commande[0], F_OK) == 0)
		{
			ft_exec(commande[0], commande, env);
			bool = 1;
		}
		i++;
	}
}

static void	pathing(char **env, char **commande)
{
	char	**chemins;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(env_get_value(env, "PATH"));
	ft_replace_char(temp, ':', ' ');
	chemins = ft_strsplit(temp, ' ');
	free(temp);
	while (chemins[i] != NULL)
	{
		temp = ft_strjoin(chemins[i], "/");
		free(chemins[i]);
		chemins[i] = ft_strjoin(temp, commande[0]);
		free(temp);
		i++;
	}
	pathing_part_two(chemins, commande, env);
	ft_free_double_str(chemins);
}

void		traitement_line(char ***env, char *line)
{
	char	**commande;

	ft_replace_char(line, 9, ' ');
	commande = ft_strsplit(line, ' ');
	if (commande != NULL && *commande != NULL)
	{
		if (ft_strchr(*commande, '/') != NULL)
			ft_exec(commande[0], commande, *env);
		else if (ft_strcmp("cd", commande[0]) == 0)
			ft_cd(env, commande);
		else if (ft_strcmp("env", commande[0]) == 0)
			ft_env(*env, commande);
		else if (ft_strcmp("unsetenv", commande[0]) == 0)
			ft_unsetenv(*env, commande);
		else if (ft_strcmp("setenv", commande[0]) == 0)
			ft_setenv(env, commande);
		else
			pathing(*env, commande);
	}
	ft_free_double_str(commande);
}
