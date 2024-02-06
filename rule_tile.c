/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/01/11 16:17:15 by bvasseur          #+#    #+#             */
/*   Updated: 2024/01/11 16:17:15 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

t_tile	*create_rule(const char *rules, int should_rotate)
{
	t_tile	*rule;

	rule = ft_calloc(sizeof(t_tile), 1);
	if (!rule)
		return (NULL);
	rule->should_rotate = should_rotate;
	rule->middle = rules[0];
	rule->left = rules[1];
	rule->right = rules[2];
	rule->top = rules[3];
	rule->bottom = rules[4];
	rule->top_left = rules[5];
	rule->top_right = rules[6];
	rule->bottom_left = rules[7];
	rule->bottom_right = rules[8];
	return (rule);
}

void	rotate_rule(t_tile *rule)
{
	t_tile	new_rule;

	new_rule.should_rotate = rule->should_rotate;
	new_rule.middle = rule->middle;
	new_rule.left = rule->bottom;
	new_rule.right = rule->top;
	new_rule.top = rule->left;
	new_rule.bottom = rule->right;
	new_rule.top_left = rule->bottom_left;
	new_rule.top_right = rule->top_left;
	new_rule.bottom_left = rule->bottom_right;
	new_rule.bottom_right = rule->top_right;
	*rule = new_rule;
}

int	compare(int a, int b, char comparator)
{
	if (comparator == '=')
		return (a == b);
	if (comparator == '!')
		return (a != b);
	return (1);
}

int	is_tile_matching_rule(t_tile tile, t_tile rule)
{
	int	count;

	count = 0;
	count += compare(tile.middle, tile.middle, rule.middle);
	count += compare(tile.middle, tile.left, rule.left);
	count += compare(tile.middle, tile.right, rule.right);
	count += compare(tile.middle, tile.top, rule.top);
	count += compare(tile.middle, tile.bottom, rule.bottom);
	count += compare(tile.middle, tile.top_left, rule.top_left);
	count += compare(tile.middle, tile.top_right, rule.top_right);
	count += compare(tile.middle, tile.bottom_left, rule.bottom_left);
	count += compare(tile.middle, tile.bottom_right, rule.bottom_right);
	return (count == 9);
}

int	check_all_rotations(t_tile tile, t_tile rule)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (is_tile_matching_rule(tile, rule))
			return (i);
		rotate_rule(&rule);
		i++;
	}
	return (-1);
}
