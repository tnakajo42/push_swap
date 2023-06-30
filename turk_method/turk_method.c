/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:37:19 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:51:42 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

void	turk_method(t_node **a, t_node **b)
{
	if (is_a_sorted(*a))
		return ;
	else if (is_a_ordered(*a))
	{
		finish_a(a);
		return ;
	}
	while (!is_a_ordered(*a))
		push_from_a_to_b(a, b);
	empty_b(a, b);
	finish_a(a);
}

void	sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->prev->value;
	if (middle < bottom && middle < top && bottom > top)
		do_sa(stack);
	else if (top > middle && top > bottom && middle > bottom)
	{
		do_sa(stack);
		do_rra(stack);
	}
	else if (top > middle && top > bottom && middle < bottom)
		do_ra(stack);
	else if (top < middle && top < bottom && middle > bottom)
	{
		do_sa(stack);
		do_ra(stack);
	}
	else if (top < middle && top > bottom && middle > bottom)
		do_rra(stack);
}
