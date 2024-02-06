/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:10:11 by bvasseur          #+#    #+#             */
/*   Updated: 2023/11/29 05:30:37 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int to_find)
{
	int		i;

	i = ft_strlen(str);
	if (to_find == 0)
		return ((char *) &str[i]);
	while (i >= 0)
	{
		if (str[i] == (char)to_find)
			return ((char *) &str[i]);
		i--;
	}
	return ((char *) 0);
}
