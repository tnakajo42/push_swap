/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:42 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:50:29 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	swap(t_node **stack);

void	do_sa(t_node **a)
{
	swap(a);
}

void	do_sb(t_node **b)
{
	swap(b);
}

void	do_ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}

static int	swap(t_node **stack)
{
	if ((*stack == NULL) || ((*stack) == (*stack)->next))
		return (0);
	if ((*stack)->prev == (*stack)->next)
	{
		(*stack)->title = nohead;
		(*stack) = (*stack)->next;
		(*stack)->title = head;
	}
	else
	{
		(*stack)->title = nohead;
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->prev = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev->next = (*stack);
		(*stack)->next->prev = (*stack);
		(*stack) = (*stack)->prev;
		(*stack)->title = head;
	}
	return (1);
}
