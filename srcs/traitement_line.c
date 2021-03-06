/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 15:21:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/05/01 11:06:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	pathing_part_two(char **chemins, char **commande, t_shell *myshell)
{
	int		i;
	int		tag;

	i = 0;
	tag = 0;
	while (chemins[i] != NULL && tag == 0)
	{
		free(commande[0]);
		commande[0] = ft_strdup(chemins[i]);
		if (access(commande[0], F_OK) == 0)
		{
			ft_exec(commande[0], commande, myshell->env);
			tag = 1;
		}
		i++;
	}
}

static void	pathing(t_shell *myshell, char **commande)
{
	char	**chemins;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strdup(env_get_value(myshell->env, "PATH"));
	ft_replace_char(temp, ':', ' ');
	chemins = ft_strsplit(temp, ' ');
	free(temp);
	while (chemins[i] != NULL)
	{
		temp = ft_strjoin(chemins[i], "/");
		free(chemins[i]);
		chemins[i] = ft_strjoin(temp, commande[0]);
		free(temp);
		i++;
	}
	pathing_part_two(chemins, commande, myshell);
	ft_free_double_str(chemins);
}

void		insertion_line(char c)
{
	int		i;
	char	*new;

	i = 0;
	new = (char*)malloc((ft_strlen(g_line) + 2) * sizeof(char));
	while (i < g_pos_line)
	{
		new[i] = (g_line)[i];
		i++;
	}
	new[i] = c;
	i++;
	while (new[i -1] != '\0')
	{
		new[i] = (g_line)[i -1];
		i++;
	}
	free(g_line);
	g_line = new;
}

void		deletion_line(void)
{
	int		i;
	char	*new;

	i = 0;
	new = (char*)malloc(ft_strlen(g_line) * sizeof(char));
	while (i < g_pos_line)
	{
		new[i] = (g_line)[i];
		i++;
	}
	while ((g_line)[i] != '\0')
	{
		new[i] = (g_line)[i + 1];
		i++;
	}
	free(g_line);
	g_line = new;
}
	
void		traitement_line(t_shell *myshell)
{
	char	**commande;

	ft_replace_char(g_line, 9, ' ');
	commande = ft_strsplit(g_line, ' ');
	if (commande != NULL && *commande != NULL)
	{
		if (ft_strchr(*commande, '/') != NULL)
			ft_exec(commande[0], commande, myshell->env);
		else if (ft_strcmp("cd", commande[0]) == 0)
			ft_cd(myshell, commande);
		else if (ft_strcmp("env", commande[0]) == 0)
			ft_env(myshell, commande);
		else if (ft_strcmp("unsetenv", commande[0]) == 0)
			ft_unsetenv(myshell->env, commande);
		else if (ft_strcmp("setenv", commande[0]) == 0)
			ft_setenv(&(myshell->env), commande);
		else
			pathing(myshell, commande);
	}
	ft_free_double_str(commande);
}
