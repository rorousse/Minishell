/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_double_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:32:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/05 13:50:49 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_double_str(char ***str, char *new)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char**)malloc(ft_get_size_double_str(*str) * sizeof(char*));
	while ((*str)[i] != NULL)
	{
		copy[i] = (*str)[i];
		i++;
	}
	copy[i] = NULL;
	free(*str);
	*str = (char**)malloc((i + 2) * sizeof(char*));
	i = 0;
	while (copy[i] != NULL)
	{
		(*str)[i] = copy[i];
		i++;
	}
	(*str)[i] = ft_strdup(new);
	(*str)[i + 1] = NULL;
}

/*
** Cette fonction prend en argument un pointeur sur un char**, et insere un char* a la fin de celui-ci.
** Pour que l'opertaions soit possible, le char** doit avoir ete alloue dynamiquement.
*/ 
