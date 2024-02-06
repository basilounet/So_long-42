/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_innit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:11:40 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 19:40:41 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

t_tile	init_tile(t_so_long *gm, size_t i, size_t j)
{
	t_tile	tile;

	tile = (t_tile){.left = '1', .right = '1', .top = '1', .bottom = '1',
		.top_left = '1', .top_right = '1', .bottom_left = '1',
		.bottom_right = '1'};
	tile.middle = gm->map[i][j];
	if (j > 0)
		tile.left = gm->map[i][j - 1];
	if (j < gm->width - 1)
		tile.right = gm->map[i][j + 1];
	if (i > 0)
		tile.top = gm->map[i - 1][j];
	if (i < gm->height - 1)
		tile.bottom = gm->map[i + 1][j];
	if (i > 0 && j > 0)
		tile.top_left = gm->map[i - 1][j - 1];
	if (i > 0 && j < gm->width - 1)
		tile.top_right = gm->map[i - 1][j + 1];
	if (i < gm->height - 1 && j > 0)
		tile.bottom_left = gm->map[i + 1][j - 1];
	if (i < gm->height - 1 && j < gm->width - 1)
		tile.bottom_right = gm->map[i + 1][j + 1];
	return (tile);
}

t_textures	*init_txtr(t_so_long *gm, t_textures *txtr, size_t nb_textures)
{
	txtr = ft_calloc(sizeof(t_textures), 1);
	if (!txtr)
		error(gm, MALLOC_ERROR);
	txtr->nb_textures = nb_textures;
	txtr->textures_name = ft_calloc(sizeof(char *), nb_textures);
	if (!txtr->textures_name)
		error(gm, MALLOC_ERROR);
	txtr->textures = ft_calloc(sizeof(mlx_texture_t *), nb_textures);
	if (!txtr->textures)
		error(gm, MALLOC_ERROR);
	txtr->image = ft_calloc(sizeof(mlx_image_t *), nb_textures);
	if (!txtr->image)
		error(gm, MALLOC_ERROR);
	return (txtr);
}

void	init_gm(t_so_long *gm)
{
	gm->mlx = NULL;
	gm->map = NULL;
	gm->height = 0;
	gm->width = 0;
	gm->recu_data = NULL;
	gm->w_rules = NULL;
	gm->frame = 0;
	gm->nb_coll = 0;
	gm->steps = 0;
	gm->steps_images = 0;
	gm->current_coll_images = 0;
	gm->fonts_txtr = init_txtr(gm, gm->fonts_txtr, NB_TEXTURES_FONTS);
	gm->wall_txtr = init_txtr(gm, gm->wall_txtr, NB_TEXTURES_WALLS);
	gm->ground_txtr = init_txtr(gm, gm->ground_txtr, NB_TEXTURES_GROUND);
	gm->coll_txtr = init_txtr(gm, gm->coll_txtr, NB_TEXTURES_COLL);
	gm->exit = ft_calloc(sizeof(t_entity), 1);
	gm->player = ft_calloc(sizeof(t_entity), 1);
	gm->enemies = ft_calloc(sizeof(t_entity), 1);
	if (!gm->player || !gm->enemies)
		error(gm, MALLOC_ERROR);
	create_wall_rules(gm);
}

void	set_textures(t_so_long *gm, t_textures *txtr,
		char *path, void (*set_texture_name)(t_so_long *gm, char ***t_names))
{
	char	*name;
	size_t	i;

	i = 0;
	if (!txtr)
		error(gm, MALLOC_ERROR);
	set_texture_name(gm, &txtr->textures_name);
	while (i < txtr->nb_textures)
	{
		name = ft_strjoin(path, txtr->textures_name[i]);
		if (!name)
			error(gm, MALLOC_ERROR);
		txtr->textures[i] = mlx_load_png(name);
		txtr->image[i] = mlx_texture_to_image(gm->mlx, txtr->textures[i]);
		if (name)
			free(name);
		if (!txtr->textures[i] || !txtr->image[i])
			error(gm, MLX_ERROR);
		i++;
	}
}
