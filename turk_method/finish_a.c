/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:35 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:50:43 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

void	finish_a(t_node **a)
{
	t_node	*min_node;

	min_node = min_node_in_stack(*a);
	if (dist_w_rot(min_node) < dist_w_rev_rot(min_node))
		while (min_node->title != head)
			do_ra(a);
	else
		while (min_node->title != head)
			do_rra(a);
}
