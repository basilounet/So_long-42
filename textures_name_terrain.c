/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_name_terrain.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:37 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 19:43:46 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	set_coll_textures_names(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("Food_0.png");
	(*t_names)[1] = ft_strdup("Food_1.png");
	(*t_names)[2] = ft_strdup("Food_2.png");
	(*t_names)[3] = ft_strdup("Food_3.png");
	(*t_names)[4] = ft_strdup("Food_4.png");
	(*t_names)[5] = ft_strdup("Food_5.png");
	(*t_names)[6] = ft_strdup("Food_6.png");
	(*t_names)[7] = ft_strdup("Food_7.png");
	(*t_names)[8] = ft_strdup("Food_8.png");
	(*t_names)[9] = ft_strdup("Food_9.png");
	(*t_names)[10] = ft_strdup("Food_10.png");
	(*t_names)[11] = ft_strdup("Food_11.png");
	(*t_names)[12] = ft_strdup("Food_12.png");
	(*t_names)[13] = ft_strdup("Food_13.png");
	(*t_names)[14] = ft_strdup("Food_14.png");
	check_errors_textures_names(gm, gm->coll_txtr);
}

static void	set_ground_textures_names(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("grass_0.png");
	(*t_names)[1] = ft_strdup("grass_1.png");
	(*t_names)[2] = ft_strdup("grass_2.png");
	(*t_names)[3] = ft_strdup("grass_3.png");
	(*t_names)[4] = ft_strdup("grass_4.png");
	(*t_names)[5] = ft_strdup("grass_5.png");
	(*t_names)[6] = ft_strdup("grass_6.png");
	(*t_names)[7] = ft_strdup("grass_7.png");
	(*t_names)[8] = ft_strdup("grass_8.png");
	(*t_names)[9] = ft_strdup("grass_9.png");
	(*t_names)[10] = ft_strdup("grass_10.png");
	check_errors_textures_names(gm, gm->ground_txtr);
}

static void	set_wall_textures_names_part2(t_so_long *gm, char ***t_names)
{
	(*t_names)[24] = ft_strdup("mountain_T_0.png");
	(*t_names)[25] = ft_strdup("mountain_T_1.png");
	(*t_names)[26] = ft_strdup("mountain_T_2.png");
	(*t_names)[27] = ft_strdup("mountain_T_3.png");
	(*t_names)[28] = ft_strdup("mountain_side_corner_in_right_0.png");
	(*t_names)[29] = ft_strdup("mountain_side_corner_in_right_1.png");
	(*t_names)[30] = ft_strdup("mountain_side_corner_in_right_2.png");
	(*t_names)[31] = ft_strdup("mountain_side_corner_in_right_3.png");
	(*t_names)[32] = ft_strdup("mountain_side_corner_in_left_0.png");
	(*t_names)[33] = ft_strdup("mountain_side_corner_in_left_1.png");
	(*t_names)[34] = ft_strdup("mountain_side_corner_in_left_2.png");
	(*t_names)[35] = ft_strdup("mountain_side_corner_in_left_3.png");
	(*t_names)[36] = ft_strdup("mountain_I.png");
	(*t_names)[37] = ft_strdup("mountain_-.png");
	(*t_names)[38] = ft_strdup("mountain_L_0.png");
	(*t_names)[39] = ft_strdup("mountain_L_1.png");
	(*t_names)[40] = ft_strdup("mountain_L_2.png");
	(*t_names)[41] = ft_strdup("mountain_L_3.png");
	(*t_names)[42] = ft_strdup("mountain_end_0.png");
	(*t_names)[43] = ft_strdup("mountain_end_1.png");
	(*t_names)[44] = ft_strdup("mountain_end_2.png");
	(*t_names)[45] = ft_strdup("mountain_end_3.png");
	(*t_names)[46] = ft_strdup("mountain_solo.png");
	check_errors_textures_names(gm, gm->wall_txtr);
}

static void	set_wall_textures_names(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("mountain_full.png");
	(*t_names)[1] = ft_strdup("mountain_corner_in_0.png");
	(*t_names)[2] = ft_strdup("mountain_corner_in_1.png");
	(*t_names)[3] = ft_strdup("mountain_corner_in_2.png");
	(*t_names)[4] = ft_strdup("mountain_corner_in_3.png");
	(*t_names)[5] = ft_strdup("mountain_side_T_0.png");
	(*t_names)[6] = ft_strdup("mountain_side_T_1.png");
	(*t_names)[7] = ft_strdup("mountain_side_T_2.png");
	(*t_names)[8] = ft_strdup("mountain_side_T_3.png");
	(*t_names)[9] = ft_strdup("mountain_diagonal_0.png");
	(*t_names)[10] = ft_strdup("mountain_diagonal_1.png");
	(*t_names)[11] = ft_strdup("mountain_corner_0.png");
	(*t_names)[12] = ft_strdup("mountain_corner_1.png");
	(*t_names)[13] = ft_strdup("mountain_corner_2.png");
	(*t_names)[14] = ft_strdup("mountain_corner_3.png");
	(*t_names)[15] = ft_strdup("mountain_+.png");
	(*t_names)[16] = ft_strdup("mountain_+3_0.png");
	(*t_names)[17] = ft_strdup("mountain_+3_1.png");
	(*t_names)[18] = ft_strdup("mountain_+3_2.png");
	(*t_names)[19] = ft_strdup("mountain_+3_3.png");
	(*t_names)[20] = ft_strdup("mountain_side_0.png");
	(*t_names)[21] = ft_strdup("mountain_side_1.png");
	(*t_names)[22] = ft_strdup("mountain_side_2.png");
	(*t_names)[23] = ft_strdup("mountain_side_3.png");
	set_wall_textures_names_part2(gm, t_names);
}

void	set_textures_terrain(t_so_long *gm)
{
	set_textures(gm, gm->ground_txtr, GROUND_TEXTURES_PATH,
		&set_ground_textures_names);
	set_textures(gm, gm->wall_txtr, WALL_TEXTURES_PATH,
		&set_wall_textures_names);
	set_textures(gm, gm->coll_txtr, COLL_TEXTURES_PATH,
		&set_coll_textures_names);
	set_textures(gm, gm->fonts_txtr, FONTS_TEXTURES_PATH, &set_fonts_names);
}
