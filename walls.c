/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:23 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 20:03:33 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	print_wall(t_so_long *gm, size_t y, size_t x)
{
	int	index_image;

	index_image = get_index_texture(gm->w_rules, init_tile(gm, y, x));
	mlx_image_to_window(gm->mlx, gm->wall_txtr->image[index_image], x
		* CELL_SIZE, y * CELL_SIZE);
}

int	is_wall(t_so_long *gm, int y, int x)
{
	if (x < 0 || y < 0 || x > (int)gm->width || y > (int)gm->height)
		return (1);
	return (gm->map[y][x] == '1');
}
