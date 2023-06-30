/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:56 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:57:33 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_node	*mid_pos_in_stack(t_node *stack, t_node *node);

t_node	*new_pos_b(t_node *b, t_node *node)
{
	t_node	*min_node;
	t_node	*max_node;

	if ((b == NULL) || (b == b->next))
		return (b);
	min_node = min_node_in_stack(b);
	max_node = max_node_in_stack(b);
	if (min_node->value > node->value)
		return (max_node);
	if (max_node->value < node->value)
		return (max_node);
	return (mid_pos_in_stack(b, node));
}

t_node	*min_node_in_stack(t_node *stack)
{
	t_node	*min_node;

	if (stack == NULL)
		return (0);
	min_node = stack;
	stack = stack->next;
	while (stack->title != head)
	{
		if (min_node->value > stack->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_node	*max_node_in_stack(t_node *stack)
{
	t_node	*max_node;

	if (stack == NULL)
		return (0);
	max_node = stack;
	stack = stack->next;
	while (stack->title != head)
	{
		if (max_node->value < stack->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static t_node	*mid_pos_in_stack(t_node *stack, t_node *node)
{
	while (!(stack->value < node->value
			&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}
