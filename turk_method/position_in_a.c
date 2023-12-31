/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_in_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:52 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:51:06 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_node	*mid_pos_in_stack_a(t_node *stack, t_node *node);

t_node	*node_new_pos_a(t_node *a, t_node *node)
{
	t_node	*min_node;
	t_node	*max_node;

	if (!node)
		return (a);
	if (a == NULL)
		return (a);
	if (a == (a)->next)
		return (a);
	min_node = min_node_in_stack(a);
	max_node = max_node_in_stack(a);
	if (min_node->value > node->value)
		return (min_node);
	if (max_node->value < node->value)
		return (min_node);
	return (mid_pos_in_stack_a(a, node));
}

static t_node	*mid_pos_in_stack_a(t_node *stack, t_node *node)
{
	while (!(stack->value > node->value
			&& stack->prev->value < node->value))
		stack = stack->prev;
	return (stack);
}
