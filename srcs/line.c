/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:02:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 11:29:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_key(char buffer[4])
{
	use_caps("im");
	ft_putchar(buffer[0]);
	insertion_line(buffer[0]); 
	(g_curseur)++;
	use_caps("ei");
}

void	up_historique(t_shell *myshell)
{
	int	taille;

	taille = ft_strlen(g_line);
	free(g_line);
	g_line = ft_strdup((myshell->historique)->commande);
	while (g_curseur > 0)
	{
		use_caps("le");
		g_curseur--;
	}
	use_caps("cd");
	write(1, g_line, ft_strlen(g_line));
	g_curseur = ft_strlen(g_line);
	if ((myshell->historique)->prec != NULL)
		myshell->historique = (myshell->historique)->prec;
}

void	down_historique(t_shell *myshell)
{
	free(g_line);
	g_line = ft_strdup((myshell->historique)->commande);
	while (g_curseur > 0)
	{
		use_caps("le");
		g_curseur--;
	}
	use_caps("ce");
	write(1, g_line, ft_strlen(g_line));
	g_curseur = ft_strlen(g_line);
	if ((myshell->historique)->next != NULL)
		myshell->historique = (myshell->historique)->next;
}

void	move_left(void)
{
	g_curseur--;
	use_caps("le");
}

void	move_right(void)
{
	g_curseur++;
	use_caps("nd");
}
