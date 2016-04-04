/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:28:04 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 14:48:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	free_copy(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

int			main(int argc, char **argv, char **environ)
{
	char **env;

	int i = 0;
	(void)argc;
	(void)argv;
	env = ft_split_copy(environ);
	prompt(env);
	free_copy(env);
	return (0);
}
