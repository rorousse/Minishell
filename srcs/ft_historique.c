/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_historique.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 11:41:06 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 15:32:43 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_historique	*create_elem(char *line)
{
	t_historique *new;

	new = (t_historique*)malloc(sizeof(t_historique));
	new->prec = NULL;
	new->next = NULL;
	new->commande = ft_strdup(line);
	return (new);
}

void				rembobinage(t_shell *myshell)
{
	while (myshell->historique != NULL && (myshell->historique)->prec != NULL)
		myshell->historique = (myshell->historique)->prec;
}

void				stockage(t_shell *myshell)
{
	t_historique	*new;

	new = create_elem(myshell->line);
	write(myshell->fd_histo, myshell->line, ft_strlen(myshell->line));
	write(myshell->fd_histo, "\n", 1);
	if (myshell->historique == NULL)
		myshell->historique = new;
	else
	{
		while ((myshell->historique)->next != NULL)
			myshell->historique = (myshell->historique)->next;
		(myshell->historique)->next = new;
		new->prec = myshell->historique;
		myshell->historique = (myshell->historique)->next;
	}
}

void				free_historique(t_shell *myshell)
{
	t_historique	*temp;

	rembobinage(myshell);
	while (myshell->historique != NULL)
	{
		temp = (myshell->historique)->next;
		free((myshell->historique)->commande);
		free(myshell->historique);
		myshell->historique = temp;
	}
}

void				fill_historique(t_shell *myshell)
{
	char			*line;
	t_historique	*new;

	while (get_next_line(myshell->fd_histo, &line) > 0)
	{
		new = create_elem(line);
		if (myshell->historique == NULL)
			myshell->historique = new;
		else
		{
			(myshell->historique)->next = new;
			new->prec = myshell->historique;
			myshell->historique = new;
		}
		free(line);
	}
}
