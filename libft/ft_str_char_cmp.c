/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_cmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:11:13 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/08 12:08:14 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_char_cmp(char *str, char *str2, char c)
{
	int	i;

	i = 0;
	while (str[i] && str2[i] && str[i] == str2[i] &&
	str[i + 1] != c && str2[i + 1] != c)
		i++;
	return (str[i] - str2[i]);
}
