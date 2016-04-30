/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:04:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/30 16:56:25 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	aff_prompt(void)
{
	char	*prompt;

	ft_putstr("\033[32m");
	prompt = (char*)malloc(256 * sizeof(char));
	getcwd(prompt, 256);
	ft_putstr(prompt);
	ft_putstr(": $>\033[37m");
	free(prompt);
}

int		prompt(t_shell *myshell)
{
	struct termios	term;

	init_term(&term);
	while (ft_strcmp(myshell->line, "exit") != 0)
	{
		// preparation du prompt
		aff_prompt();
		free(myshell->line);
		myshell->line = ft_strdup("");
 
		//  capture de la ligne

		ft_capture(myshell);

		// stockage dans l'historique
		
		stockage(myshell);

		// traitement de la ligne
		check_multiples_lines(myshell); 
	}
	close_term(&term);
	free(myshell->line);
	return (0);
}
