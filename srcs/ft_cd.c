/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:36:31 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 13:48:30 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_cd(char **env, char **commande)
{
	char	*path;

	path = (char*)malloc(256 * sizeof(char));
	if (commande[2] == NULL)
	{
		if ((access(commande[1], F_OK) == 0) && (access(commande[1], X_OK) == 0))
		{
			getcwd(path, 256);
			insert_env(env, "OLDPWD", path);
			chdir(commande[1]);
			path = (char*)malloc(256 * sizeof(char));
			getcwd(path, 256);
			insert_env(env, "PWD", path);
		}
		else
			ft_putstr("Erreur : invalid directory\n");
	}
	else
		ft_putstr("Erreur : nombre d'arguments invalides\n");
}
