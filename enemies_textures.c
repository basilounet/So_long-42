/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:09:03 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 18:39:20 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	set_enemies_textures_names(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Idle_head_0.png");
	(*t_names)[1] = ft_strdup("Idle_head_1.png");
	(*t_names)[2] = ft_strdup("Idle_head_2.png");
	(*t_names)[3] = ft_strdup("Idle_head_3.png");
	(*t_names)[4] = ft_strdup("Idle_head_4.png");
	(*t_names)[5] = ft_strdup("Idle_head_5.png");
	(*t_names)[6] = ft_strdup("Idle_head_6.png");
	(*t_names)[7] = ft_strdup("Idle_head_7.png");
	(*t_names)[8] = ft_strdup("Idle_head_8.png");
	(*t_names)[9] = ft_strdup("Idle_head_9.png");
	(*t_names)[10] = ft_strdup("Idle_head_10.png");
	(*t_names)[11] = ft_strdup("Idle_head_11.png");
	(*t_names)[12] = ft_strdup("Idle_head_12.png");
	(*t_names)[13] = ft_strdup("Idle_head_13.png");
	(*t_names)[14] = ft_strdup("Idle_head_14.png");
	(*t_names)[15] = ft_strdup("Idle_head_15.png");
	(*t_names)[16] = ft_strdup("Idle_head_16.png");
	(*t_names)[17] = ft_strdup("Idle_head_17.png");
	check_errors_textures_names(gm,
		(t_textures *)ft_lst_getel(gm->enemies->animations,
			"idle_side")->content);
}

void	set_textures_ennemies(t_so_long *gm)
{
	t_textures	*new_txtr;

	new_txtr = NULL;
	new_txtr = init_txtr(gm, new_txtr, NB_TEXTURES_ENEMY_IDLE);
	ft_lstadd_back(&gm->enemies->animations, ft_lstnew("idle_side",
			new_txtr));
	set_textures(gm, (t_textures *)
		(ft_lst_getel(gm->enemies->animations, "idle_side")->content),
		ENEMY_TEXTURES_PATH, &set_enemies_textures_names);
	gm->enemies->current_animation = (t_textures *) \
		(ft_lst_getel(gm->enemies->animations,
				"idle_side")->content);
	create_images(gm, gm->enemies, "idle_side");
	set_animation(gm->enemies, "idle_side");
}
