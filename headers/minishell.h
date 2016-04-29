/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:27:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/29 18:30:18 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <fcntl.h>

struct  s_historique
{
	char	*commande;
	struct s_historique	*prec;
	struct s_historique *next;
};

typedef struct s_historique t_historique;

struct	s_shell
{
	char			**env;
	int				curseur;
	char			*line;
	int				fd_histo;
	t_historique	*historique;
};

typedef struct s_shell t_shell;

// FICHIER DE TEST A SUPPRIMER A LA FIN

/*
** TEST_C
*/

void	print_buffer(char buffer[4]);

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
void	use_caps(char *caps);

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
** FT_HISTORIQUE_C
*/

void	rembobinage(t_shell *myshell);
void	fill_historique(t_shell *myshell);
void	free_historique(t_shell *myshell);
void	stockage(t_shell *myshell);

/*
** FT_UNSETENV_C
*/

void	ft_unsetenv(char **env, char **commande);

/*
** FT_SETENV_C
*/

void	ft_setenv(char ***env, char **commande);

/*
** LINE_C
*/

void	print_key(char buffer[4], t_shell *myshell);
void	up_historique(t_shell *myshell);
void	down_historique(t_shell *myshell);
void	move_right(t_shell *myshell);
void	move_left(t_shell *myshell);

/*
** LINE_2_C
*/

void	delete_car(t_shell *myshell);

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
