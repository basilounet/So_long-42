/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleak_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:23:28 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 17:30:58 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	free_textures(mlx_texture_t **textures, size_t nb_textures)
{
	size_t	i;

	i = 0;
	if (!textures)
		return ;
	while (i < nb_textures)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
	free(textures);
}

void	free_images(mlx_t *mlx, mlx_image_t **images, size_t nb_textures)
{
	size_t	i;

	i = 0;
	if (!images)
		return ;
	while (i < nb_textures)
	{
		if (images[i])
			mlx_delete_image(mlx, images[i]);
		i++;
	}
	free(images);
}

void	free_txtr(mlx_t *mlx, t_textures *txtr)
{
	size_t	i;

	i = 0;
	if (!txtr)
		return ;
	ft_free_map(txtr->textures_name, txtr->nb_textures);
	free_textures(txtr->textures, txtr->nb_textures);
	free_images(mlx, txtr->image, txtr->nb_textures);
	free(txtr);
}

void	free_entity(t_entity *entity, mlx_t *mlx)
{
	t_list	*next;
	t_list	*lst;

	if (!entity)
		return ;
	lst = entity->animations;
	while (lst)
	{
		next = lst->next;
		free(lst->name);
		free_txtr(mlx, (t_textures *)lst->content);
		free(lst);
		lst = next;
	}
	free(entity);
}
