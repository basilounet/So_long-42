/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unleak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:50:07 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 18:09:21 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	free_gnl(int fd, t_so_long *gm, char *str)
{
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	error(gm, MALLOC_ERROR);
}

void	free_recu_data(t_so_long *gm)
{
	if (!gm->recu_data)
		return ;
	ft_free_map(gm->recu_data->map, gm->height);
	free(gm->recu_data);
}

void	unleak(t_so_long *gm)
{
	kill_sounds();
	ft_free_map(gm->map, gm->height);
	free_recu_data(gm);
	ft_lstclear(&gm->w_rules, &free);
	free_txtr(gm->mlx, gm->fonts_txtr);
	free_txtr(gm->mlx, gm->wall_txtr);
	free_txtr(gm->mlx, gm->ground_txtr);
	free_txtr(gm->mlx, gm->coll_txtr);
	free_entity(gm->exit, gm->mlx);
	free_entity(gm->player, gm->mlx);
	free_entity(gm->enemies, gm->mlx);
	ft_lstclear(&gm->steps_images, &free);
	ft_lstclear(&gm->current_coll_images, &free);
	if (!gm->mlx)
		return ;
	mlx_close_window(gm->mlx);
	mlx_terminate(gm->mlx);
}
