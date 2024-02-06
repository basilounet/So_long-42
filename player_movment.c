/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:17 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 17:59:23 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	is_movment_key(mlx_key_data_t keydata)
{
	return (keydata.action != MLX_RELEASE && (keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_RIGHT));
}

static void	change_animation(mlx_key_data_t keydata, t_entity *entity)
{
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& entity->facing != 0)
	{
		set_animation(entity, "idle_right");
		entity->facing = 0;
	}
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& entity->facing != 1)
	{
		set_animation(entity, "idle_back");
		entity->facing = 1;
	}
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& entity->facing != 2)
	{
		set_animation(entity, "idle_left");
		entity->facing = 2;
	}
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& entity->facing != 3)
	{
		set_animation(entity, "idle_front");
		entity->facing = 3;
	}
}

void	move(mlx_key_data_t keydata, t_so_long *gm)
{
	change_animation(keydata, gm->player);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && !is_wall(gm,
			gm->player->y - 1, gm->player->x))
		gm->player->y -= 1;
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& !is_wall(gm, gm->player->y, gm->player->x - 1))
		gm->player->x -= 1;
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& !is_wall(gm, gm->player->y + 1, gm->player->x))
		gm->player->y += 1;
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& !is_wall(gm, gm->player->y, gm->player->x + 1))
		gm->player->x += 1;
	else
		return ;
	if (gm->map[gm->player->y][gm->player->x] == 'C')
		remove_coll(gm, gm->player->y, gm->player->x);
	gm->steps++;
	ft_printf("number of steps : %d\n", gm->steps);
	print_steps(gm);
	play_sound("sounds/walking_on_grass.wav &");
	update_animation_pos(gm->player);
	check_lost(gm);
	if (gm->nb_coll >= gm->recu_data->c_total)
		check_victory(gm);
}
