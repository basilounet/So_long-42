/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:08:48 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/20 16:29:40 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	check_errors_textures_names(t_so_long *gm, t_textures *txtr)
{
	size_t	i;

	i = 0;
	while (i < txtr->nb_textures)
	{
		if (!txtr->textures_name[i++])
			error(gm, MALLOC_ERROR);
	}
}

void	error_part2(enum e_errors name)
{
	if (name == MALLOC_ERROR)
		write(1, "[ ! ERROR ! ] A malloc error occured\n", 37);
	else if (name == INVALID_AC_AMOUNT)
		write(1, "[ ! ERROR ! ] Incorrect numbers of arguments\n", 45);
	else if (name == MISSING_FORMAT)
		write(1, "[ ! ERROR ! ] There is no format\n", 33);
	exit(name);
}

void	error(t_so_long *gm, enum e_errors name)
{
	unleak(gm);
	write(1, "Error\n", 6);
	if (name == INVALID_FD)
		write(1, "[ ! ERROR ! ] File not found\n", 29);
	else if (name == INVALID_FORMAT)
		write(1, "[ ! ERROR ! ] The format is not .ber\n", 37);
	else if (name == EMPTY_MAP)
		write(1, "[ ! ERROR ! ] The file is empty\n", 32);
	else if (name == INVALID_CHARACTER)
		write(1, "[ ! ERROR ! ] There is an invalid character\n", 44);
	else if (name == INVALID_WALLS)
		write(1, "[ ! ERROR ! ] The map's borders must be walls\n", 46);
	else if (name == INVALID_SHAPE)
		write(1, "[ ! ERROR ! ] The map must be a rectangle\n", 42);
	else if (name == INVALID_NUMBER_P)
		write(1, "[ ! ERROR ! ] There must be only one P (player)\n", 48);
	else if (name == INVALID_NUMBER_E)
		write(1, "[ ! ERROR ! ] There must be only one E (exit)\n", 46);
	else if (name == INVALID_NUMBER_C)
		write(1, "[ ! ERROR ! ] There must be at least one C\n", 43);
	else if (name == UNREACHABLE_E)
		write(1, "[ ! ERROR ! ] The exit is unreachable\n", 38);
	else if (name == UNREACHABLE_C)
		write(1, "[ ! ERROR ! ] At least one consumable is unreachable\n", 53);
	error_part2(name);
}
