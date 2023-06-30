/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:41 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:50:49 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	is_a_ordered(t_node *a)
{
	t_node	*min_node;
	t_node	*max_node;
	int		count;

	if (!a)
		return (true);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	count = 1;
	while (min_node != max_node)
	{
		if (min_node->value > min_node->next->value)
			return (false);
		min_node = min_node->next;
		++count;
	}
	if (count == size_of_stack(a))
		return (true);
	return (false);
}
