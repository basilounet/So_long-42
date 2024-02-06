/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:51:33 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 18:15:32 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_map(char **map, size_t len)
{
	size_t	i;

	i = 0;
	if (!map)
		return (NULL);
	while (i < len)
		if (map[i++])
			free(map[i - 1]);
	if (map)
		free(map);
	return (NULL);
}
