/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:18:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 12:30:22 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_car(void)
{
	g_curseur--;
	deletion_line();
	use_caps("le");
	use_caps("dc");
}

void	start_line(void)
{
	while (g_curseur > 0)
	{
		use_caps("le");
		g_curseur--;
	}
}

void	end_line(void)
{
	int	taille;

	taille = ft_strlen(g_line);
	while (g_curseur < taille)
	{
		g_curseur++;
		use_caps("nd");
	}
}

void	right_word(void)
{
	int	i;
	int	boleen;

	i = g_curseur;
	boleen = 0;
	while (g_line[i] && boleen == 0)
	{
		if (g_line[i] == ' ')
			boleen = 1;
		i++;
	}
	while (g_curseur < i)
		move_right();
}
	
void	left_word(void)
{
	int	i;
	int	boleen;

	i = g_curseur;
	boleen = 0;
	while (i >= 0 && boleen == 0)
	{
		if (g_line[i] == ' ')
			boleen = 1;
		i--;
	}
	while (g_curseur > i)
		move_left();
}
