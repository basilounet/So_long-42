/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:08:41 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 17:33:52 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	print_grass(t_so_long *gm, int y, int x)
{
	int	amount_grass;
	int	index_grass;
	int	i;

	i = 0;
	amount_grass = ft_rand(-1, 3);
	while (i < amount_grass)
	{
		index_grass = ft_rand(1, NB_TEXTURES_GROUND - 1);
		mlx_image_to_window(gm->mlx, gm->ground_txtr->image[index_grass], x
			* CELL_SIZE + ft_rand(0, CELL_SIZE - 16), y * CELL_SIZE + ft_rand(0,
				CELL_SIZE - 16));
		i++;
	}
}
