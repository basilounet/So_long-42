/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:50:13 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 20:43:47 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	set_fonts_names(t_so_long *gm, char ***t_names)
{
	(*t_names)[0] = ft_strdup("0.png");
	(*t_names)[1] = ft_strdup("1.png");
	(*t_names)[2] = ft_strdup("2.png");
	(*t_names)[3] = ft_strdup("3.png");
	(*t_names)[4] = ft_strdup("4.png");
	(*t_names)[5] = ft_strdup("5.png");
	(*t_names)[6] = ft_strdup("6.png");
	(*t_names)[7] = ft_strdup("7.png");
	(*t_names)[8] = ft_strdup("8.png");
	(*t_names)[9] = ft_strdup("9.png");
	(*t_names)[10] = ft_strdup("slash.png");
	check_errors_textures_names(gm, gm->fonts_txtr);
}

void	create_number_instances(t_so_long *gm, t_list **lst)
{
	int	i;
	int	*content;

	i = 0;
	content = ft_calloc(sizeof(int), 10);
	if (!content)
		return ;
	while (i < 10)
	{
		content[i] = mlx_image_to_window(gm->mlx, gm->fonts_txtr->image[i], 0,
				0);
		gm->fonts_txtr->image[i]->instances[content[i]].enabled = 0;
		i++;
	}
	ft_lstadd_back(lst, ft_lstnew("", content));
}

void	print_steps(t_so_long *gm)
{
	size_t	len_s;
	size_t	i;
	int		digit;
	int		*content;

	len_s = ft_lennum(gm->steps);
	i = len_s;
	if (ft_lstsize(gm->steps_images) != len_s)
		create_number_instances(gm, &gm->steps_images);
	while (i > 0)
	{
		digit = gm->steps / ft_power(10, len_s - i) % 10;
		content = (int *)(ft_lst_getindex(gm->steps_images, len_s
					- i)->content);
		gm->fonts_txtr->image[ft_mod(digit - 1,
				10)]->instances[content[ft_mod(digit - 1, 10)]].enabled = 0;
		gm->fonts_txtr->image[digit]->instances[content[digit]].x = \
			(ft_lennum(gm->recu_data->c_total) * 2 + 1 + i) * CELL_SIZE;
		gm->fonts_txtr->image[digit]->instances[content[digit]].enabled = 1;
		i--;
	}
}

void	print_current_coll(t_so_long *gm)
{
	size_t	len_s;
	size_t	i;
	int		digit;
	int		*content;

	len_s = ft_lennum(gm->recu_data->c_total);
	i = len_s;
	while (i > 0)
	{
		digit = gm->nb_coll / ft_power(10, len_s - i) % 10;
		content = (int *)(ft_lst_getindex(gm->current_coll_images, len_s
					- i)->content);
		gm->fonts_txtr->image[ft_mod(digit - 1,
				10)]->instances[content[ft_mod(digit - 1, 10)]].enabled = 0;
		gm->fonts_txtr->image[digit]->instances[content[digit]].x = (i - 1)
			* CELL_SIZE;
		gm->fonts_txtr->image[digit]->instances[content[digit]].enabled = 1;
		i--;
	}
}

void	print_total_coll(t_so_long *gm)
{
	int	len_s;
	int	digit;
	int	i;

	len_s = ft_lennum(gm->recu_data->c_total);
	i = len_s;
	while (i > 0)
	{
		create_number_instances(gm, &gm->current_coll_images);
		digit = gm->recu_data->c_total / ft_power(10, len_s - i) % 10;
		mlx_image_to_window(gm->mlx, gm->fonts_txtr->image[digit], (i
				+ ft_lennum(gm->recu_data->c_total)) * CELL_SIZE, 0);
		i--;
	}
	mlx_image_to_window(gm->mlx, gm->fonts_txtr->image[10], (i
			+ ft_lennum(gm->recu_data->c_total)) * CELL_SIZE, 0);
}
