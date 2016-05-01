/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:28:04 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 17:55:58 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int			main(int argc, char **argv, char **environ)
{
	t_shell	myshell;

	(void)argc;
	(void)argv;
	myshell.env = ft_split_copy(environ);
	g_pos_line = 0;
	g_line = ft_strdup("");
	myshell.fd_histo = open("historique.txt", O_RDWR | O_CREAT, 0750);
	myshell.historique = NULL;
	init_sig();
	fill_historique(&myshell);
	prompt(&myshell);
	close(myshell.fd_histo);
	free_historique(&myshell);
	ft_free_double_str(myshell.env);
	return (0);
}
