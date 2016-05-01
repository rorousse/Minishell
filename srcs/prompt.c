/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:04:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 19:25:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	find_first(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Les caracteres reconnus sont : ' " ` { [ (
** et leurs equivalents de fermeture
** A cause de l'architecture de la fonction il faut toujours
** placer les caracteres dont le caractere de fermeture est 
** different de celui d'ouverture a la fin, et incrementer
** le '+' dans le second if de autant
*/

static int	ft_parsing(void)
{
	int	parsing[6];
	int	i;
	int	pos;
	
	i = 0;
	while (i < 6)
	{
		parsing[i] = 0;
		i++;
	}
	i = 0;
	while (g_line[i])
	{
		if ((pos = find_first("'\"`{[(", g_line[i])) != -1)
			parsing[pos]++;
		if ((pos = find_first("}])", g_line[i])) != -1)
			parsing[pos + 3]--;
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if ((i < 3 && parsing[i] % 2 != 0) || (i > 2 && parsing[i] != 0))
			return (0);
		i++;
	}
	return (1);
}
			
void	aff_prompt(char *name)
{
	char	*prompt;

	ft_putstr("\033[32m");
	prompt = (char*)malloc(256 * sizeof(char));
	if (name != NULL)
		prompt = ft_strdup(name);
	else
		getcwd(prompt, 256);
	ft_putstr(prompt);
	g_x = g_x + ft_strlen(prompt);
	g_x = g_x + 3;
	ft_putstr(": $>\033[37m");
	free(prompt);
}

int		prompt(t_shell *myshell)
{
	struct termios	term;

	init_term(&term);
	while (ft_strcmp(g_line, "exit") != 0)
	{
		// preparation du prompt
		g_x = 0;
		g_y = 0;
		aff_prompt(NULL);
		free(g_line);
		g_line = ft_strdup("");
		g_pos_line = 0;

		//  capture de la ligne

		ft_capture(myshell);

		// stockage dans l'historique

		while (ft_parsing() != 1)
		{
			g_x = 0;
			g_y = 0;
			ft_capture(myshell);
		}
		stockage(myshell);

		// traitement de la ligne
		check_multiples_lines(myshell); 
	}
	close_term(&term);
	free(g_line);
	return (0);
}
