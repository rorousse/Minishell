/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:28:04 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 16:26:58 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int			main(int argc, char **argv, char **environ)
{
	char **env;

	(void)argc;
	(void)argv;
	env = ft_split_copy(environ);
	prompt(&env);
	ft_free_double_str(env);
	return (0);
}
