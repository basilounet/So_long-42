/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:08:12 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 20:42:36 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	t_n_idle_right(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Idle_right_0.png");
	(*t_names)[1] = ft_strdup("Idle_right_1.png");
	(*t_names)[2] = ft_strdup("Idle_right_2.png");
	(*t_names)[3] = ft_strdup("Idle_right_3.png");
	(*t_names)[4] = ft_strdup("Idle_right_4.png");
	(*t_names)[5] = ft_strdup("Idle_right_5.png");
	check_errors_textures_names(gm,
		(t_textures *)(ft_lst_getel(gm->player->animations,
				"idle_right")->content));
}

static void	t_n_idle_left(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Idle_left_0.png");
	(*t_names)[1] = ft_strdup("Idle_left_1.png");
	(*t_names)[2] = ft_strdup("Idle_left_2.png");
	(*t_names)[3] = ft_strdup("Idle_left_3.png");
	(*t_names)[4] = ft_strdup("Idle_left_4.png");
	(*t_names)[5] = ft_strdup("Idle_left_5.png");
	check_errors_textures_names(gm,
		(t_textures *)(ft_lst_getel(gm->player->animations,
				"idle_left")->content));
}

static void	t_n_idle_back(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Idle_back_0.png");
	(*t_names)[1] = ft_strdup("Idle_back_1.png");
	(*t_names)[2] = ft_strdup("Idle_back_2.png");
	(*t_names)[3] = ft_strdup("Idle_back_3.png");
	(*t_names)[4] = ft_strdup("Idle_back_4.png");
	(*t_names)[5] = ft_strdup("Idle_back_5.png");
	check_errors_textures_names(gm,
		(t_textures *)(ft_lst_getel(gm->player->animations,
				"idle_back")->content));
}

static void	t_n_idle_front(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Idle_front_0.png");
	(*t_names)[1] = ft_strdup("Idle_front_1.png");
	(*t_names)[2] = ft_strdup("Idle_front_2.png");
	(*t_names)[3] = ft_strdup("Idle_front_3.png");
	(*t_names)[4] = ft_strdup("Idle_front_4.png");
	(*t_names)[5] = ft_strdup("Idle_front_5.png");
	check_errors_textures_names(gm,
		(t_textures *)(ft_lst_getel(gm->player->animations,
				"idle_front")->content));
}

void	set_textures_player(t_so_long *gm)
{
	static char	*sides[5] = {"idle_left", "idle_front", "idle_back",
		"idle_right", 0};
	static void	(*funcs[5])(t_so_long *, char ***) = {&t_n_idle_left,
		&t_n_idle_front, &t_n_idle_back, &t_n_idle_right, 0};
	t_textures	*new_txtr;
	int			i;

	i = 0;
	new_txtr = NULL;
	while (sides[i] && funcs[i])
	{
		new_txtr = init_txtr(gm, new_txtr, NB_TEXTURES_P_IDLE);
		ft_lstadd_back(&gm->player->animations, ft_lstnew(sides[i], new_txtr));
		if (ft_lstsize(gm->player->animations) != (size_t)(i + 1))
			error(gm, MALLOC_ERROR);
		set_textures(gm, (t_textures *)
			(ft_lst_getel(gm->player->animations, sides[i])->content),
			PLAYER_TEXTURES_PATH, funcs[i]);
		create_images(gm, gm->player, sides[i]);
		i++;
	}
	gm->player->current_animation = (t_textures *) \
		(ft_lst_getel(gm->player->animations, "idle_right")->content);
	set_animation(gm->player, "idle_right");
}
