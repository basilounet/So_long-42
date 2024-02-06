/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:03:58 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 20:41:55 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	flood_fill(size_t ypos, size_t xpos, t_so_long *gm)
{
	if (gm->recu_data->map[ypos][xpos] == '1')
		return ;
	if (gm->recu_data->map[ypos][xpos] == 'C')
		gm->recu_data->c_seen += 1;
	if (gm->recu_data->map[ypos][xpos] == 'E')
	{
		gm->recu_data->e_seen += 1;
		gm->exit->x = xpos;
		gm->exit->y = ypos;
	}
	gm->recu_data->map[ypos][xpos] = '1';
	if (ypos > 0)
		flood_fill(ypos - 1, xpos, gm);
	if (xpos < gm->width)
		flood_fill(ypos, xpos + 1, gm);
	if (ypos < gm->height)
		flood_fill(ypos + 1, xpos, gm);
	if (xpos > 0)
		flood_fill(ypos, xpos - 1, gm);
}

static void	check_path(t_so_long *gm)
{
	flood_fill(gm->recu_data->p_ypos, gm->recu_data->p_xpos, gm);
	if (gm->recu_data->e_seen != 1)
		error(gm, UNREACHABLE_E);
	if (gm->recu_data->c_seen != gm->recu_data->c_total)
		error(gm, UNREACHABLE_C);
	gm->player->x = gm->recu_data->p_xpos;
	gm->player->y = gm->recu_data->p_ypos;
}

static void	check_playable(t_so_long *gm)
{
	int	col;

	col = 0;
	gm->recu_data = innit_data(gm);
	if (!gm->recu_data || !gm->recu_data->map)
		error(gm, MALLOC_ERROR);
	while (gm->map[col])
	{
		gm->recu_data->e_total += ft_countc(gm->map[col], 'E');
		gm->recu_data->p_total += ft_countc(gm->map[col], 'P');
		gm->recu_data->c_total += ft_countc(gm->map[col], 'C');
		if (ft_countc(gm->map[col], 'P') == 1)
		{
			gm->recu_data->p_xpos = ft_strlentc(gm->map[col], 'P');
			gm->recu_data->p_ypos = col;
		}
		col++;
	}
	if (gm->recu_data->p_total != 1)
		error(gm, INVALID_NUMBER_P);
	if (gm->recu_data->e_total != 1)
		error(gm, INVALID_NUMBER_E);
	if (gm->recu_data->c_total < 1)
		error(gm, INVALID_NUMBER_C);
	check_path(gm);
}

static void	ft_get_map(char *path, t_so_long *gm)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	gm->map = ft_calloc(sizeof(char **), gm->height + 1);
	if (!gm->map)
		error(gm, MALLOC_ERROR);
	str = get_next_line(fd);
	while (str)
	{
		gm->map[i] = ft_calloc(sizeof(char *), ft_strlen(str) + 1);
		if (!gm->map[i])
		{
			free_gnl(fd, gm, str);
			error(gm, MALLOC_ERROR);
		}
		ft_strncpy(gm->map[i], str, ft_strlen(str) + 1);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	map_analyser(int ac, char **av, t_so_long *gm)
{
	int	fd;

	init_gm(gm);
	if (ac != 2)
		error(gm, INVALID_AC_AMOUNT);
	if (ft_strrchr(av[1], '.') == NULL)
		error(gm, MISSING_FORMAT);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 5) != 0)
		error(gm, INVALID_FORMAT);
	fd = open(av[1], O_RDONLY);
	close(fd);
	if (fd < 0)
		error(gm, INVALID_FD);
	gm->height = ft_numbers_of_lines(av[1]);
	ft_get_map(av[1], gm);
	gm->width = ft_strlentc(gm->map[0], '\n');
	check_lines(gm);
	check_playable(gm);
}
