/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:44:24 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 18:40:02 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	set_textures_names_exit(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("bundle_0.png");
	(*t_names)[1] = ft_strdup("bundle_1.png");
	(*t_names)[2] = ft_strdup("bundle_2.png");
	(*t_names)[3] = ft_strdup("bundle_3.png");
	(*t_names)[4] = ft_strdup("bundle_4.png");
	check_errors_textures_names(gm,
		(t_textures *)(ft_lst_getel(gm->exit->animations, "exit")->content));
}

void	set_textures_exit(t_so_long *gm)
{
	t_textures	*new_txtr;

	new_txtr = NULL;
	new_txtr = init_txtr(gm, new_txtr, NB_TEXTURES_EXIT);
	ft_lstadd_back(&gm->exit->animations, ft_lstnew("exit", new_txtr));
	set_textures(gm, (t_textures *)
		(ft_lst_getel(gm->exit->animations, "exit")->content),
		COLL_TEXTURES_PATH, &set_textures_names_exit);
	gm->exit->current_animation = (t_textures *)
		(ft_lst_getel(gm->exit->animations, "exit")->content);
	create_images(gm, gm->exit, "exit");
	set_animation(gm->exit, "exit");
}

void	create_images(t_so_long *gm, t_entity *entity, char *name)
{
	t_textures	*txtr;
	size_t		i;

	i = 0;
	txtr = (t_textures *)(ft_lst_getel(entity->animations, name)->content);
	while (i < txtr->nb_textures)
	{
		mlx_image_to_window(gm->mlx, txtr->image[i], entity->x * CELL_SIZE,
			entity->y * CELL_SIZE);
		txtr->image[i]->instances[0].enabled = 0;
		i++;
	}
}

void	check_victory(t_so_long *gm)
{
	if (gm->player->x == gm->exit->x && gm->player->y == gm->exit->y)
	{
		ft_printf("Congratulations you won!\n");
		unleak(gm);
		exit(0);
	}
}
