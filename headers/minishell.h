/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:27:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/04 15:27:47 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

/*
** ENVIRONNEMENT_C
*/

char	*env_get_value(char **env, char *name);

/*
** PROMPT_C
*/

int		prompt(char **env);

/*
** TRAITEMENT_LINE
*/

void	traitement_line(char *line);

#endif
