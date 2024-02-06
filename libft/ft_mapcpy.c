/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:47:57 by bvasseur          #+#    #+#             */
/*   Updated: 2023/12/06 20:45:26 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mapcpy(char **original, size_t len)
{
	char	**map;
	size_t	i;

	i = 0;
	map = ft_calloc(sizeof(char *), len + 1);
	if (!map)
		return (NULL);
	while (i < len)
	{
		map[i] = ft_strdup(original[i]);
		if (!map[i])
			return (ft_free_map(map, i));
		i++;
	}
	return (map);
}
