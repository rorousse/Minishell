/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:28:04 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 10:32:23 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int			main(int argc, char **argv, char **environ)
{
	t_shell	myshell;;

	(void)argc;
	(void)argv;
	myshell.env = ft_split_copy(environ);
	myshell.curseur = 0;
	myshell.line = ft_strdup("");
	prompt(&myshell);
	ft_free_double_str(myshell.env);
	return (0);
}
