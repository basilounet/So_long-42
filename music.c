/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:00:52 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/23 10:52:19 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include <stdlib.h>
#include <unistd.h>

void	play_sound(char *path)
{
	char	*str;

	str = ft_strjoin("paplay ", path);
	if (!str)
		return ;
	system(str);
	free(str);
}

void	kill_sounds(void)
{
	system("pkill paplay &");
}
