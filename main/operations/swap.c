/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:36:08 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_node **stack);

void	do_sa(t_node **a)
{
	if (swap(a))
		write(STDOUT_FILENO, "sa\n", 3);
}

void	do_sb(t_node **b)
{
	if (swap(b))
		write(STDOUT_FILENO, "sb\n", 3);
}

void	do_ss(t_node **a, t_node **b)
{
	if (swap(a) + swap(b))
		write(STDOUT_FILENO, "ss\n", 3);
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
