/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:27:21 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 11:42:55 by rorousse         ###   ########.fr       */
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

// Librairies de test a supprimer a la fin

# include <time.h>

/*
** Les variables globales suivantes ont ete definies en tant que globales car
** on a besoin d'interagir avec elles en temps reel via les signaux. L'autre solution
** etait les singletons, ce qui restreint effectivemenbt l'accessibilitee de la variable
** en question (chose qui n'est absolument pas genante avec un nommage intelligent) mais
** fait au niveau de la memoire la meme chose qu'une globale, a savoir occuper une place
** en memoire jusqu'a la fin du programme ( donc sur le plan effectif et pratique, aucune
** difference si ce n'est la lourdeur d'utilisation des singletons )
*/

char	*g_line;
int		g_curseur;

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
** FT_SIGNAL_C
*/

void	ft_sigquit(int sig);
void	ft_sigint(int sig);
void	init_sig(void);

/*
** LINE_C
*/

void	print_key(char buffer[4]);
void	up_historique(t_shell *myshell);
void	down_historique(t_shell *myshell);
void	move_right(void);
void	move_left(void);

/*
** LINE_2_C
*/

void	delete_car(void);

/*
** MULTIPLES_LINES_C
*/

void	check_multiples_lines(t_shell *myshell);

/*
** PROMPT_C
*/

void	aff_prompt(void);
int		prompt(t_shell *myshell);

/*
** TRAITEMENT_LINE
*/

void	insertion_line(char c);
void	deletion_line(void);
void	traitement_line(t_shell *myshell);

#endif
