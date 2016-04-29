/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:02:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 18:17:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_key(char buffer[4], t_shell *myshell)
{
	use_caps("im");
	ft_putchar(buffer[0]);
	insertion_line(myshell, buffer[0]); 
	(myshell->curseur)++;
	use_caps("ei");
}

void	up_historique(t_shell *myshell)
{
	free(myshell->line);
	myshell->line = ft_strdup((myshell->historique)->commande);
	while (myshell->curseur > 0)
	{
		use_caps("le");
		(myshell->curseur)--;
	}
	use_caps("ce");
	write(1, myshell->line, ft_strlen(myshell->line));
	myshell->curseur = ft_strlen(myshell->line);
	if ((myshell->historique)->prec != NULL)
		myshell->historique = (myshell->historique)->prec;
}

void	down_historique(t_shell *myshell)
{
	free(myshell->line);
	myshell->line = ft_strdup((myshell->historique)->commande);
	while (myshell->curseur > 0)
	{
		use_caps("le");
		(myshell->curseur)--;
	}
	use_caps("ce");
	write(1, myshell->line, ft_strlen(myshell->line));
	myshell->curseur = ft_strlen(myshell->line);
	if ((myshell->historique)->next != NULL)
		myshell->historique = (myshell->historique)->next;
}

void	move_left(t_shell *myshell)
{
	(myshell->curseur)--;
	use_caps("le");
}

void	move_right(t_shell *myshell)
{
	(myshell->curseur)++;
	use_caps("nd");
}