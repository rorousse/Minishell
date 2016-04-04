/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:21:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 15:31:30 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_split(char **commande)
{
	int	i;

	i = 0;
	while (commande[i] != NULL)
	{
		free(commande[i]);
		i++;
	}
	free(commande[i]);
	free(commande);
}

void		traitement_line(char *line)
{
	char **commande;

	commande = ft_strsplit(line, ' ');
	if (ft_strchr(*commande, '/') != NULL)
		ft_putstr("ah, un programme ! On le traitera plus tard\n");
	else
		ft_putstr("hm, serait ce autre chose ? cherchons\n");
	free_split(commande);
}
