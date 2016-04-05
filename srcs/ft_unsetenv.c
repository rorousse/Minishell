/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:02:14 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 14:45:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_unsetenv(char **env, char **commande)
{
	int	pos;

	if (commande[1] != NULL && commande[2] == NULL)
	{
		pos = env_get_pos(env, commande[1]);
		if (pos != -1)
		{
			free(env[pos]);
			while (env[pos] != NULL)
			{
				env[pos] = env[pos + 1];
				pos++;
			}
		}
		else
			ft_putstr("Erreur : variable inexistante\n");
	}
	else
		ft_putstr("Erreur : nombre d'arguments invalides\n");
}
