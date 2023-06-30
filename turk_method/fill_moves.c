/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:29 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:57:25 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static int	max(int x, int y);

void	fill_move(t_node *a, t_node *b)
{
	a->move.rot_a = dist_w_rot(a);
	a->move.rot_b = dist_w_rot(new_pos_b(b, a));
	a->move.steps = max(a->move.rot_a, a->move.rot_b);
	if (dist_w_rot(a) + dist_w_rev_rot(new_pos_b(b, a)) < a->move.steps)
	{
		a->move.rot_a = dist_w_rot(a);
		a->move.rot_b = -dist_w_rev_rot(new_pos_b(b, a));
		a->move.steps = a->move.rot_a - a->move.rot_b;
	}
	if (dist_w_rev_rot(a) + dist_w_rot(new_pos_b(b, a)) < a->move.steps)
	{
		a->move.rot_a = -dist_w_rev_rot(a);
		a->move.rot_b = dist_w_rot(new_pos_b(b, a));
		a->move.steps = -a->move.rot_a + a->move.rot_b;
	}
	if (max(dist_w_rev_rot(a), dist_w_rev_rot(new_pos_b(b, a))) < a->move.steps)
	{
		a->move.rot_a = -dist_w_rev_rot(a);
		a->move.rot_b = -dist_w_rev_rot(new_pos_b(b, a));
		a->move.steps = max(-a->move.rot_a, -a->move.rot_b);
	}
}

static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
