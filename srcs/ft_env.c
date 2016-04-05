/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:47:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 12:48:05 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr(env[i]);
		ft_putchar('\n');
		i++;
	}
}
