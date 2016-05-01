/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 14:48:35 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 11:54:17 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int sig)
{
	if (sig == SIGINT)
	{
		free(g_line);
		g_line = ft_strdup("");
		g_curseur = 0;
		ft_putchar('\n');
		aff_prompt();
	}
}
/*
void	ft_sigquit(int sig)
{
	if (sig == SIGKILL)
		ft_putstr("Boum\n");
}
*/
	

void	init_sig(void)
{
	signal(SIGINT, ft_sigint);
}
		
