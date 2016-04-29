/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:51:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 15:38:48 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	use_caps(char *caps)
{
	char	*cmd;

	cmd = tgetstr(caps, NULL);
	tputs(cmd, 0, &(ft_putchar));
}

void	ft_capture(t_shell *myshell)
{
	char	buffer[4];
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
			use_caps("im");
			ft_putchar(buffer[0]);
			insertion_line(myshell, buffer[0]); // On insere la touche dans la ligne du shell
			(myshell->curseur)++;
			use_caps("ei");
		} 
		else if (buffer[0] == 27 && buffer[1] == 91)
		{
			if (buffer[2] == 68 && myshell->curseur > 0)
			{
				(myshell->curseur)--;
				use_caps("le");
			}
			else if (buffer[2] == 67 && myshell->curseur < (int)ft_strlen(myshell->line))
			{
				(myshell->curseur)++;
				use_caps("nd");
			}
			else if (buffer[2] == 65)
			{
				free(myshell->line);
				myshell->line = ft_strdup((myshell->historique)->commande);
				while (myshell->curseur > 0)
				{
					use_caps("le");
					(myshell->curseur)--;
				}
				use_caps("ce");
				write(1, myshell->line, ft_strlen(myshell->line));
				myshell->curseur = ft_strlen(myshell->line);
				if ((myshell->historique)->prec != NULL)
					myshell->historique = (myshell->historique)->prec;
			}
			else if (buffer[2] == 66)
            {
                free(myshell->line);
                myshell->line = ft_strdup((myshell->historique)->commande);
                while (myshell->curseur > 0)
                {
                    use_caps("le");
                    (myshell->curseur)--;
                }
                use_caps("ce");
                write(1, myshell->line, ft_strlen(myshell->line));
                myshell->curseur = ft_strlen(myshell->line);
				if ((myshell->historique)->next != NULL)
					myshell->historique = (myshell->historique)->next;
            }
		}
		else if (buffer[0] == 127 && myshell->curseur > 0)
		{
			(myshell->curseur)--;
			deletion_line(myshell);
			use_caps("le");
			use_caps("dc");
		}
	}
	ft_putchar('\n');
	myshell->curseur = 0;
}
