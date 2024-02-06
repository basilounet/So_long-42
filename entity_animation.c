/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:08:56 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/18 15:51:03 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	update_animation_pos(t_entity *entity)
{
	t_textures	*txtr;
	size_t		i;

	i = 0;
	txtr = entity->current_animation;
	while (i < txtr->nb_textures)
	{
		txtr->image[i]->instances[0].x = entity->x * CELL_SIZE;
		txtr->image[i]->instances[0].y = entity->y * CELL_SIZE;
		i++;
	}
}

void	set_animation(t_entity *entity, char *name)
{
	t_textures	*txtr;

	txtr = (t_textures *)(ft_lst_getel(entity->animations, name)->content);
	entity->current_animation->image[entity->animation_frame]->\
		instances[0].enabled = 0;
	entity->current_animation = txtr;
	entity->animation_frame = 0;
	entity->current_animation->image[0]->instances[0].enabled = 1;
	update_animation_pos(entity);
}

void	next_animation_frame(t_entity *entity)
{
	entity->current_animation->image[entity->animation_frame]->\
		instances[0].enabled = 0;
	entity->animation_frame = ++entity->animation_frame
		% (entity->current_animation->nb_textures);
	entity->current_animation->image[entity->animation_frame]->\
		instances[0].enabled = 1;
}

void	set_frame(t_entity *entity, int index)
{
	entity->current_animation->image[entity->animation_frame]->\
		instances[0].enabled = 0;
	entity->animation_frame = index;
	entity->current_animation->image[index]->instances[0].enabled = 1;
}
