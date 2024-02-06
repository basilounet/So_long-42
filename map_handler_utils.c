/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:50:58 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 18:25:39 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	is_component(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

t_recu	*innit_data(t_so_long *gm)
{
	t_recu	*data;

	data = ft_calloc(sizeof(t_recu), 1);
	if (!data)
		return (NULL);
	data->map = ft_mapcpy(gm->map, gm->height);
	data->e_total = 0;
	data->p_total = 0;
	data->c_total = 0;
	data->c_seen = 0;
	data->e_seen = 0;
	data->p_xpos = 0;
	data->p_ypos = 0;
	return (data);
}

void	check_lines(t_so_long *gm)
{
	size_t	len_line;
	size_t	row;
	size_t	i;

	row = 0;
	while (row < gm->height)
	{
		i = 0;
		len_line = ft_strlentc(gm->map[row], '\n');
		if (len_line != gm->width)
			error(gm, INVALID_SHAPE);
		while (i < len_line)
			if (!is_component(gm->map[row][i++]))
				error(gm, INVALID_CHARACTER);
		if (gm->map[row][0] != '1' || gm->map[row][len_line - 1] != '1')
			error(gm, INVALID_WALLS);
		if ((row == 0 || row == gm->height - 1) && ft_countc(gm->map[row],
				'1') != len_line)
			error(gm, INVALID_WALLS);
		row++;
	}
}
