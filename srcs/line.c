/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:02:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/11 18:19:55 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_key(char buffer[4])
{
	struct winsize	w;
	int				taille;

	ioctl(0, TIOCGWINSZ, &w);
	insertion_line(buffer[0]);
	taille = g_pos_line;
	start_line();
	write(1, g_line, ft_strlen(g_line));
	g_x = g_x + ft_strlen(g_line);
	g_y = g_x / (w.ws_col + 1);
	g_x = g_x % (w.ws_col + 1);
	g_pos_line = ft_strlen(g_line);
	if (g_x == w.ws_col)
	{
		use_caps("do");
		g_y++;
		g_x = 0;
	}
	while (g_pos_line > taille + 1)
		move_left();
}

void	up_historique(t_shell *myshell)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	free(g_line);
	g_line = ft_strdup((myshell->historique)->commande);
	while ((g_x != 0 || g_y != 0) && g_pos_line > 0)
		move_left();
	use_caps("cd");
	write(1, g_line, ft_strlen(g_line));
	g_pos_line = ft_strlen(g_line);
	g_x = g_x + g_pos_line;
	g_y = g_x / w.ws_col;
	g_x = g_x % w.ws_col;
	if ((myshell->historique)->prec != NULL)
		myshell->historique = (myshell->historique)->prec;
}

void	down_historique(t_shell *myshell)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	free(g_line);
	g_line = ft_strdup((myshell->historique)->commande);
	while ((g_x != 0  || g_y != 0) && g_pos_line > 0)
		move_left();
	use_caps("cd");
	write(1, g_line, ft_strlen(g_line));
	g_pos_line = ft_strlen(g_line);
	g_x = g_x + g_pos_line;
	g_x = g_x % w.ws_col;
	g_y = g_x / w.ws_col;
	if ((myshell->historique)->next != NULL)
		myshell->historique = (myshell->historique)->next;
}

void	move_left(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_pos_line--;
	g_x--;
	if (g_x == -1)
	{
		g_x = 0;
		g_y--;
		use_caps("up");
		while (g_x != w.ws_col - 1)
		{
			use_caps("nd");
			g_x++;
		}
	}
	else
		use_caps("le");
}

void	move_right(void)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	g_pos_line++;
	g_x++;
	if (g_x == w.ws_col)
	{
		g_x = 0;
		g_y++;
		use_caps("do");
	}
	else
		use_caps("nd");
}
