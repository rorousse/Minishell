/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:51:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/02 12:50:34 by rorousse         ###   ########.fr       */
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

	while (buffer[0] != 10 && buffer[0] != 4)
	{
		init_capture(buffer);
		read(0, buffer, 4);
		if (ft_isprint(buffer[0])) // si la touche est affichable
			print_key(buffer);
		else if (buffer[0] == 27 && buffer[1] == 91) // si la touche est une fleche
		{
			if (buffer[2] == 68 && !(g_x == 0 && g_y == 0) && g_pos_line > 0)// si la touche est gauche
				move_left();
			else if (buffer[2] == 67 && g_pos_line < (int)ft_strlen(g_line)) //droite
				move_right();
			else if (buffer[2] == 65 && myshell->historique != NULL) //haut
				up_historique(myshell);
			else if (buffer[2] == 66 && myshell->historique != NULL) //bas
				down_historique(myshell);
			else if (buffer[2] == 72)
				start_line();
			else if (buffer[2] == 70)
				end_line();
		}
		else if (buffer[0] == 127 && g_pos_line != 0)
			delete_car();
		else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 67)
			right_word();
		else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 68)
			left_word();
		else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 66)
			move_down();
//		print_buffer(buffer);
	}
	if (buffer[0] == 4)
	{
		free(g_line);
		g_line = ft_strdup("exit");
	}
	ft_putchar('\n');
}
