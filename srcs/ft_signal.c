/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 14:48:35 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 18:07:11 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int sig)
{
	if (sig == SIGINT)
	{
		free(g_line);
		g_line = ft_strdup("");
		g_pos_line = 0;
		g_x = 0;
		g_y = 0;
		ft_putchar('\n');
		aff_prompt(NULL);
	}
}

void	init_sig(void)
{
	signal(SIGINT, ft_sigint);
}
		
