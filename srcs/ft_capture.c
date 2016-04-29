/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:51:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 10:19:23 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_capture(t_shell *myshell)
{
	char	buffer[4];
	char	*cmd;
	int		i;

	while (buffer[0] != 10)
	{
		i = 0;
		while(i < 4)
		{
			buffer[i] = 0;
			i++;
		}
		read(0, buffer, 4);
		if (ft_isprint(buffer[0]))
		{
			cmd = tgetstr("im", NULL);
			tputs(cmd, 0, &(ft_putchar));
			ft_putchar(buffer[0]);
			insertion_line(myshell, buffer[0]); // On insere la touche dans la ligne du shell
			(myshell->curseur)++;
			cmd = tgetstr("ei", NULL);
			tputs(cmd, 0, &(ft_putchar));
		} 
		else if (buffer[0] == 27 && buffer[1] == 91)
		{
			if (buffer[2] == 68 && myshell->curseur > 0)
			{
				(myshell->curseur)--;
				cmd = tgetstr("le", NULL);
				tputs(cmd, 0, &(ft_putchar));
			}
			else if (buffer[2] == 67 && myshell->curseur < (int)ft_strlen(myshell->line))
			{
				(myshell->curseur)++;
				cmd = tgetstr("nd", NULL);
				tputs(cmd, 0, &(ft_putchar));
			}
		}
		else if (buffer[0] == 127 && myshell->curseur > 0)
		{
			(myshell->curseur)--;
			deletion_line(myshell);
			cmd = tgetstr("le", NULL);
			tputs(cmd, 0, &(ft_putchar));
			cmd = tgetstr("dc", NULL);
			tputs(cmd, 0, &(ft_putchar));
		}
	}
	ft_putchar('\n');
	myshell->curseur = 0;
}
