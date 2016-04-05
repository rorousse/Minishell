/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:27:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 14:14:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

/*
** ENVIRONNEMENT_C
*/

char	*env_get_value(char **env, char *name);
int		env_get_pos(char **env, char *name);
void	insert_env(char **env, char *name, char *value);

/*
** FT_CD_C
*/

void	ft_cd(char **env, char **commande);

/*
** FT_ENV_C
*/

void	ft_env(char **env);

/*
** FT_UNSETENV_C
*/

void	ft_unsetenv(char **env, char **commande);

/*
** PROMPT_C
*/

int		prompt(char **env);

/*
** TRAITEMENT_LINE
*/

void	traitement_line(char **env, char *line);

#endif
