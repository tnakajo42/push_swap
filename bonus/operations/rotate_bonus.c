/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:30 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:50:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	rotate(t_node **stack);

void	do_ra(t_node **a)
{
	rotate(a);
}

void	do_rb(t_node **b)
{
	rotate(b);
}

void	do_rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}

static int	rotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = nohead;
	(*stack) = (*stack)->next;
	(*stack)->title = head;
	return (1);
}
