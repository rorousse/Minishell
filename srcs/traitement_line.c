/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:21:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/06 13:45:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	pathing(char **env, char **commande)
{
	char	**pathings;
	char	*temp;
	int		i;
	int		bool;

	i = 0;
	bool = 0;
	pathings = ft_strsplit(env_get_value(env, "PATH"), ':');
	while (pathings[i] != NULL && bool == 0)
	{
		temp = ft_strjoin(pathings[i], "/");
		free(pathings[i]);
		pathings[i] = temp;
		temp = commande[0];
		commande[0] = ft_strjoin(pathings[i], temp);
		free(temp);
		if (access(commande[0], F_OK) == 0)
		{
			ft_exec(commande[0], commande, env);
			bool = 1;
		}
		i++;
	}
	ft_free_double_str(pathings);
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
		else if(ft_strcmp("setenv", commande[0]) == 0)
			ft_setenv(env, commande);
		else 
			pathing(*env, commande);
	}
	ft_free_double_str(commande);
}
