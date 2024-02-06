/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_movment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:03:07 by bvasseur          #+#    #+#             */
/*   Updated: 2024/02/03 12:26:51 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	place_enemy(t_so_long *gm, t_entity *entity, int i)
{
	int	x;
	int	y;

	if (i <= 0)
		return ;
	while (1)
	{
		x = ft_rand(-1, 1);
		y = ft_rand(-1, 1);
		if (!is_wall(gm, entity->y + y, entity->x + x) && !(entity->y
				+ y == gm->player->y && entity->x + x == gm->player->x))
			break ;
	}
	entity->x += x;
	entity->y += y;
	place_enemy(gm, gm->enemies, i - 1);
}

void	place_enemies(t_so_long *gm)
{
	gm->enemies->x = gm->player->x;
	gm->enemies->y = gm->player->y;
	place_enemy(gm, gm->enemies, ft_rand(50, 150));
	update_animation_pos(gm->enemies);
}

void	play_enemies(t_so_long *gm, t_entity *entity)
{
	int	x;
	int	y;

	while (1)
	{
		x = ft_rand(-1, 1);
		y = ft_rand(-1, 1);
		if (!is_wall(gm, entity->y + y, entity->x + x))
			break ;
	}
	entity->y += y;
	entity->x += x;
	update_animation_pos(entity);
	check_lost(gm);
}

void	check_lost(t_so_long *gm)
{
	if (gm->enemies->x == gm->player->x && gm->enemies->y == gm->player->y)
	{
		ft_printf("You were bite by the fox, you lost.\n");
		unleak(gm);
		exit(0);
	}
}
