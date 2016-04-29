/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiples_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 10:36:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 10:42:11 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	check_multiples_lines(t_shell *myshell)
{
	char	**multiples;
	int		i;

	i = 0;
	multiples = ft_strsplit(myshell->line, ';');
	while (multiples[i] != NULL && ft_strcmp(myshell->line, "exit") != 0)
	{
		free(myshell->line);
		myshell->line = ft_strdup(multiples[i]);
		traitement_line(myshell);
		i++;
	}
	ft_free_double_str(multiples);
}
