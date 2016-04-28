/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:01:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/22 16:04:51 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     init_term(struct termios *term)
{
    char    *terminal;

    terminal = NULL;
    if ((terminal = getenv("TERM")) == NULL)
    {
        ft_putstr("Erreur : impossible de trouver le terminal");
        return (-1);
    }
    if ((tgetent(NULL, terminal)) == ERR)
    {
        ft_putstr("Erreur : tgetent\n");
        return (-1);
    }
    if (tcgetattr(0, term) == -1)
    {
        ft_putstr("Error : tcgetattr\n");
        return (-1);
    }
    term->c_lflag &= ~(ICANON);
    term->c_lflag &= ~(ECHO);
    term->c_cc[VMIN]= 1; // rechercher ce que cela fait
    term->c_cc[VTIME] = 0; // rechercher ce que cela fait
    if (tcsetattr(0, TCSADRAIN, term) == -1)
        return (-1);
    ft_putstr("initialisation ok\n");
    return (0);
}

int     close_term(struct termios *term)
{
    if (tcgetattr(0, term) == -1)
    {
        ft_putstr("Erreur close : tcgetattr\n");
        return (-1);
    }
    term->c_lflag = (ICANON | ECHO);
    if (tcsetattr(0, 0, term) == -1)
    {
        ft_putstr("Erreur close : tcsettattr\n");
        return (-1);
    }
    ft_putstr("Fin du programme\n");
    return (0);
}
