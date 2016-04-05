/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:04:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 13:14:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	prompt(char **env)
{
	char	*line;

	line = ft_strdup("");
	while (ft_strcmp(line, "exit") != 0)
	{
		free(line);
		ft_putstr("\033[32m");
		ft_putstr(env_get_value(env, "PWD"));
		ft_putstr(": $>\033[37m");
		if (get_next_line(0, &line) < 0)
		{
			ft_putstr("Erreur : Fin du programme\n");
			return (0);
		}
		traitement_line(env, line);
	}
	free(line);
	return (0);
}
