/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:27:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 11:12:05 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>

struct  s_historique
{
	char	*commande;
	struct s_historique	*prec;
	struct s_historique *next;
};

typedef struct s_historique t_historique;

struct	s_shell
{
	char			**historique;
	char			**env;
	int				curseur;
	char			*line;
	t_historique	historique;
};

typedef struct s_shell t_shell;

/*
** CAPS_C
*/

int		init_term(struct termios *term);
int		close_term(struct termios *term);

/*
** ENVIRONNEMENT_C
*/

char	*env_get_value(char **env, char *name);
int		env_get_pos(char **env, char *name);
void	insert_env(char ***env, char *name, char *value);

/*
** FT_CAPTURE_C
*/

void	ft_capture(t_shell *myshell);

/*
** FT_CD_C
*/

void	ft_cd(t_shell *myshell, char **commande);

/*
** FT_ENV_C
*/

void	ft_env(t_shell *myshell, char **commande);

/*
** FT_EXEC_C
*/

void	ft_exec(char *program, char **commande, char **env);

/*
** FT_UNSETENV_C
*/

void	ft_unsetenv(char **env, char **commande);

/*
** FT_SETENV_C
*/

void	ft_setenv(char ***env, char **commande);

/*
** MULTIPLES_LINES_C
*/

void	check_multiples_lines(t_shell *myshell);

/*
** PROMPT_C
*/

int		prompt(t_shell *myshell);

/*
** TRAITEMENT_LINE
*/

void	insertion_line(t_shell *myshell, char c);
void	deletion_line(t_shell *myshell);
void	traitement_line(t_shell *myshell);

#endif
