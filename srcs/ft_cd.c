/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:36:31 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 16:03:43 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_cd(char **commande)
{
	if (commande[2] == NULL)
	{
		if ((access(commande[1], F_OK) == 0) && (access(commande[1], X_OK) == 0))
			ft_putstr("fichier accessible\n");
		else
			ft_putstr("Erreur : invalid directory\n");
	}
	else
		ft_putstr("Erreur : nombre d'arguments invalides\n");
}
