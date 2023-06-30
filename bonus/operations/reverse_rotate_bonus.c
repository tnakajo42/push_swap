/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:22 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:51:02 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	rrotate(t_node **stack);

void	do_rra(t_node **a)
{
	rrotate(a);
}

void	do_rrb(t_node **b)
{
	rrotate(b);
}

void	do_rrr(t_node **a, t_node **b)
{
	rrotate(a);
	rrotate(b);
}

static int	rrotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = nohead;
	(*stack) = (*stack)->prev;
	(*stack)->title = head;
	return (1);
}
