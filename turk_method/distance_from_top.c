/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_from_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:58:14 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	dist_w_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == head)
		return (dist);
	while (node->title != head)
	{
		++dist;
		node = node->prev;
	}
	return (dist);
}

int	dist_w_rev_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == head)
		return (dist);
	while (node->title != head)
	{
		++dist;
		node = node->next;
	}
	return (dist);
}
