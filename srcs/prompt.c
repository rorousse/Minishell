/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:04:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/28 19:29:54 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	prompt(t_shell *myshell)
{
	struct termios	term;

	init_term(&term);
	while (ft_strcmp(myshell->line, "exit") != 0)
	{
		// preparation du prompt
		free(myshell->line);
		ft_putstr("\033[32m");
		myshell->line = (char*)malloc(256 * sizeof(char));
		getcwd(myshell->line, 256);
		ft_putstr(myshell->line);
		free(myshell->line);
		myshell->line = ft_strdup("");
		ft_putstr(": $>\033[37m");
 
		//  capture de la ligne

		ft_capture(myshell);

		// traitement de la ligne
		traitement_line(myshell); 
	}
	close_term(&term);
	free(myshell->line);
	return (0);
}
