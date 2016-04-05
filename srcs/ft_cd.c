/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:36:31 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 15:37:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_cd(char ***env, char **commande)
{
	char	*path;

	if (commande[1] != NULL && commande[2] == NULL)
	{
		if ((access(commande[1], F_OK) == 0) && (access(commande[1], X_OK) == 0))
		{
			path = (char*)malloc(256 * sizeof(char));
			getcwd(path, 256);
			insert_env(env, "OLDPWD", path);
			chdir(commande[1]);
			getcwd(path, 256);
			insert_env(env, "PWD", path);
			free(path);
		}
		else
			ft_putstr("Erreur : invalid directory\n");
	}
	else
		ft_putstr("Erreur : nombre d'arguments invalides\n");
}
