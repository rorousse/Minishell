/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 14:29:47 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/08 10:06:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_setenv(char ***env, char **commande)
{
	if (commande[1] != NULL && commande[2] != NULL && commande[3] == NULL)
		insert_env(env, commande[1], commande[2]);
	else
		ft_putstr_fd("Erreur : nombre d'arguments invalides\n", 2);
}
