/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:07:57 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/26 19:52:45 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

void	create_wall_rules(t_so_long *gm)
{
	ft_lstadd_back(&gm->w_rules, ft_lstnew("F", create_rule("=========", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("CI", create_rule("=====!===", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("S+1", create_rule("=====!=!=", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("/", create_rule("=====!==!", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("\\", create_rule("======!!=", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("C", create_rule("=!=!=   =", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("+", create_rule("=====!!!!", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("+3", create_rule("=====!!=!", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("S", create_rule("=!=== = =", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("T", create_rule("==!==! ! ", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("SCR", create_rule("=!=== = !", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("SCL", create_rule("=!=== ! =", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("I", create_rule("=!!==    ", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("-", create_rule("===!!    ", 0)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("L", create_rule("==!=!    ", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("U", create_rule("=!=!!    ", 1)));
	ft_lstadd_back(&gm->w_rules, ft_lstnew("O", create_rule("=!!!!    ", 0)));
	if (ft_lstsize(gm->w_rules) != 17)
		error(gm, MALLOC_ERROR);
}

int	get_index_texture(t_list *rules, t_tile tile)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = rules;
	while (tmp)
	{
		if (((t_tile *)tmp->content)->should_rotate)
		{
			if (check_all_rotations(tile, *(t_tile *)tmp->content) != -1)
				return (i + check_all_rotations(tile, *(t_tile *)tmp->content));
			i += 4;
		}
		else
		{
			if (is_tile_matching_rule(tile, *(t_tile *)tmp->content))
				return (i);
			i++;
		}
		tmp = tmp->next;
	}
	return (NB_TEXTURES_WALLS - 1);
}
