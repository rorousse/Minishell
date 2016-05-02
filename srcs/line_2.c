/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:18:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/02 13:31:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_car(void)
{
	int	i;

	move_left();
	deletion_line();
	i = g_pos_line;
	while (g_line[i])
	{
		ft_putchar(g_line[i]);
		i++;
	}
	ft_putchar('_');
	while (i >= g_pos_line)
	{
		use_caps("le");
		i--;
	}
}

void	start_line(void)
{
	while ((!(g_x == 0 && g_y == 0)) && g_pos_line > 0)
		move_left();
}

void	end_line(void)
{
	int	taille;

	taille = ft_strlen(g_line);
	while (g_pos_line < taille)
		move_right();
}

void	right_word(void)
{
	int	i;
	int	boleen;

	i = g_pos_line;
	boleen = 0;
	while (g_line[i] && boleen == 0)
	{
		if (g_line[i] == ' ' && g_line[i+1] != ' ' && ft_isprint(g_line[i +1]))
			boleen = 1;
		i++;
	}
	if (boleen == 1)
	{
		while (g_pos_line < i)
			move_right();
	}
}
	
void	left_word(void)
{
	int	i;
	int	boleen;

	i = g_pos_line;
	boleen = 0;
	while (i >= 0 && boleen == 0)
	{
		if (g_line[i] == ' ' && (i - 1) >= 0 && ft_isprint(g_line[i-1]) && g_line[i-1] != ' ')
			boleen = 1;
		i--;
	}
	if (boleen == 1)
	{
		while (g_pos_line > i)
			move_left();
	}
}
