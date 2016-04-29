/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:28:04 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 13:25:58 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//fonction de test, a effacer a la fin
/*
static void	aff_histo(t_shell *myshell)
{
	rembobinage(myshell);
	while (myshell->historique != NULL && (myshell->historique)->next != NULL)
	{
		ft_putstr((myshell->historique)->commande);
		ft_putchar('\n');
		myshell->historique = (myshell->historique)->next;
	}
	ft_putstr((myshell->historique)->commande);
	ft_putchar('\n');
}
*/
int			main(int argc, char **argv, char **environ)
{
	t_shell	myshell;

	(void)argc;
	(void)argv;
	myshell.env = ft_split_copy(environ);
	myshell.curseur = 0;
	myshell.line = ft_strdup("");
	myshell.fd_histo = open("historique.txt", O_RDWR | O_CREAT);
	myshell.historique = NULL;
	fill_historique(&myshell);
	prompt(&myshell);
	close(myshell.fd_histo);
	free_historique(&myshell);
	ft_free_double_str(myshell.env);
	return (0);
}
