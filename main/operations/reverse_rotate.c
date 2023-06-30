/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:37:35 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rrotate(t_node **stack);

void	do_rra(t_node **a)
{
	if (rrotate(a))
		write (STDOUT_FILENO, "rra\n", 4);
}

void	do_rrb(t_node **b)
{
	if (rrotate(b))
		write (STDOUT_FILENO, "rrb\n", 4);
}

void	do_rrr(t_node **a, t_node **b)
{
	if (rrotate(a) + rrotate(b))
		write (STDOUT_FILENO, "rrr\n", 4);
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
