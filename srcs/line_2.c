/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:18:00 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 18:21:21 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_car(t_shell *myshell)
{
	(myshell->curseur)--;
	deletion_line(myshell);
	use_caps("le");
	use_caps("dc");
}
