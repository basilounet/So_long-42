/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:17:03 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 13:28:23 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	count_word(char const *s, char sep)
{
	size_t	nb_word;

	nb_word = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			nb_word++;
		while (*s != sep && *s)
			s++;
	}
	return (nb_word);
}

static char	**fill_array(char const *s, char c, char **array)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			array[i] = ft_substr(s, 0, len);
			if (!array)
				return (free_array(array));
			i++;
			s += len;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = fill_array(s, c, array);
	return (array);
}
