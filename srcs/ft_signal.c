/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 14:48:35 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/30 16:46:51 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sigint(int sig)
{
	if (sig == SIGINT)
	{
		interruption = 1;
	}
}

void	init_sig(void)
{
	signal(SIGINT, ft_sigint);
}
		
