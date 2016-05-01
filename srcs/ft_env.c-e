/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:47:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/24 16:18:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	affichage(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}

void		ft_env(t_shell *myshell, char **commande)
{
	char	**tempenv;

	if (commande[1] == NULL)
		affichage(myshell->env);
	else if (ft_strcmp(commande[1], "-i") == 0)
	{
		tempenv = (char**)malloc(1 * sizeof(char*));
		*tempenv = NULL;
		ft_exec(commande[2], &(commande[2]), tempenv);
		free(tempenv);
	}
	else if (ft_strcmp(commande[1], "-u") == 0)
	{
		tempenv = ft_split_copy(myshell->env);
		ft_delete_double_str(tempenv, env_get_pos(tempenv, commande[2]));
		ft_exec(commande[3], &(commande[3]), tempenv);
		ft_free_double_str(tempenv);
	}
	else
		ft_putstr_fd("Env : erreur\n", 2);
}
