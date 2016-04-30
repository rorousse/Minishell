/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:51:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/30 16:45:59 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_capture(char buffer[4])
{
	int		i;

	i = 0;
	while(i < 4)
	{
		buffer[i] = 0;
		i++;
	}
}

void	use_caps(char *caps)
{
	char	*cmd;

	cmd = tgetstr(caps, NULL);
	tputs(cmd, 0, &(ft_putchar));
}

void	ft_capture(t_shell *myshell)
{
	char	buffer[4];

	interruption = 0;
	while (buffer[0] != 10 && (interruption == 0))
	{
		init_capture(buffer);
		read(0, buffer, 4);
		if (ft_isprint(buffer[0])) // si la touche est affichable
			print_key(buffer, myshell);
		else if (buffer[0] == 27 && buffer[1] == 91) // si la touche est une fleche
		{
			if (buffer[2] == 68 && myshell->curseur > 0)// si la touche est gauche
				move_left(myshell);
			else if (buffer[2] == 67 && myshell->curseur < (int)ft_strlen(myshell->line)) //droite
				move_right(myshell);
			else if (buffer[2] == 65 && myshell->historique != NULL) //haut
				up_historique(myshell);
			else if (buffer[2] == 66 && myshell->historique != NULL) //bas
				down_historique(myshell);
		}
		else if (buffer[0] == 127 && myshell->curseur > 0)
			delete_car(myshell);
//		print_buffer(buffer);
	}
	ft_putchar('\n');
	myshell->curseur = 0;
}
