/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:36:01 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_node **stack);

void	do_ra(t_node **a)
{
	if (rotate(a))
		write(STDOUT_FILENO, "ra\n", 3);
}

void	do_rb(t_node **b)
{
	if (rotate(b))
		write(STDOUT_FILENO, "rb\n", 3);
}

void	do_rr(t_node **a, t_node **b)
{
	if (rotate(a) + rotate(b))
		write(STDOUT_FILENO, "rr\n", 3);
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
