/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:25:55 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 19:28:48 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include <time.h>

static void	put_terrain(t_so_long *gm)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < gm->height)
	{
		x = 0;
		while (x < gm->width)
		{
			mlx_image_to_window(gm->mlx, gm->ground_txtr->image[0], x
				* CELL_SIZE, y * CELL_SIZE);
			if (!is_wall(gm, y, x))
				print_grass(gm, y, x);
			if (is_wall(gm, y, x))
				print_wall(gm, y, x);
			else if (gm->map[y][x] == 'C')
				mlx_image_to_window(gm->mlx, gm->coll_txtr->image[ft_rand(0,
						NB_TEXTURES_COLL - 1)], x * CELL_SIZE, y * CELL_SIZE);
			x++;
		}
		y++;
	}
}

void	window_initiate(t_so_long *gm)
{
	ft_srand(time(NULL));
	gm->mlx = mlx_init(gm->width * CELL_SIZE, (gm->height) * CELL_SIZE,
			"so_long", false);
	set_textures_terrain(gm);
	put_terrain(gm);
	set_textures_exit(gm);
	set_textures_player(gm);
	set_textures_ennemies(gm);
	place_enemies(gm);
	print_total_coll(gm);
	print_current_coll(gm);
	print_steps(gm);
	play_sound("sounds/Digital_Love_8bit.wav &");
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*gm;

	gm = (t_so_long *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		unleak(gm);
		exit(0);
	}
	if (is_movment_key(keydata))
		move(keydata, gm);
}

void	update(void *param)
{
	t_so_long	*gm;

	gm = (t_so_long *)param;
	gm->frame++;
	if (gm->frame % 15 == 0)
		next_animation_frame(gm->player);
	if (gm->frame % 10 == 0)
		next_animation_frame(gm->enemies);
	if (ft_rand(1, 35) == 5)
		play_enemies(gm, gm->enemies);
}

int	main(int ac, char **av)
{
	t_so_long	gm;

	map_analyser(ac, av, &gm);
	window_initiate(&gm);
	mlx_key_hook(gm.mlx, &my_keyhook, &gm);
	mlx_loop_hook(gm.mlx, &update, &gm);
	mlx_loop(gm.mlx);
	unleak(&gm);
	exit(0);
}
