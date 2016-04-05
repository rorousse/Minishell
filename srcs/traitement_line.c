/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:21:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 15:24:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void		traitement_line(char ***env, char *line)
{
	char **commande;

	commande = ft_strsplit(line, ' ');
	if (commande != NULL && *commande != NULL)
	{
		if (ft_strchr(*commande, '/') != NULL)
			ft_putstr("ah, un programme ! On le traitera plus tard\n");
		else
		{
			if (ft_strcmp("cd", commande[0]) == 0)
				ft_cd(env, commande);
			else if (ft_strcmp("env", commande[0]) == 0)
				ft_env(*env);
			else if (ft_strcmp("unsetenv", commande[0]) == 0)
				ft_unsetenv(*env, commande);
			else if(ft_strcmp("setenv", commande[0]) == 0)
				ft_setenv(env, commande);
		}
	}
	ft_free_double_str(commande);
}
