/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:33:59 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 17:54:40 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include <math.h>

void	remove_coll(t_so_long *gm, int y, int x)
{
	size_t	i;
	size_t	j;

	i = 0;
	gm->nb_coll++;
	set_frame(gm->exit, floor((float)gm->nb_coll / (float)gm->recu_data->c_total
			* (NB_TEXTURES_EXIT - 1)));
	while (i < gm->coll_txtr->nb_textures)
	{
		j = 0;
		while (j < gm->coll_txtr->image[i]->count)
		{
			if (gm->coll_txtr->image[i]->instances[j].y / CELL_SIZE == y
				&& gm->coll_txtr->image[i]->instances[j].x / CELL_SIZE == x)
			{
				gm->coll_txtr->image[i]->instances[j].enabled = 0;
				gm->map[y][x] = 0;
				print_current_coll(gm);
				return ;
			}
			j++;
		}
		i++;
	}
}
