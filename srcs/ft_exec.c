/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 21:23:26 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/08 10:59:44 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	exec_fils(char *program, char **commande, char **env)
{
	char	**args;

	args = &(commande[0]);
	execve(program, args, env);
}

static void	exec_pere(void)
{
	wait(NULL);
}

void		ft_exec(char *program, char **commande, char **env)
{
	pid_t	mypid;

	if ((access(program, F_OK) == 0) && (access(program, X_OK) == 0))
	{
		mypid = fork();
		if (mypid == 0)
			exec_fils(program, commande, env);
		else
			exec_pere();
	}
	else
		ft_putstr_fd("Erreur : programme innaccessible\n", 2);
}
