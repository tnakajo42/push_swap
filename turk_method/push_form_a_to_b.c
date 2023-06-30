/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_form_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:20:35 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:37:32 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_move	*find_cheapest_node_move(t_node **a);
static void		do_rotates(t_node **a, t_node **b, t_move *move);
static void		do_rev_rotates(t_node **a, t_node **b, t_move *move);

void	push_from_a_to_b(t_node **a, t_node **b)
{
	t_move	*move;

	if (a == NULL)
		return ;
	fill_move(*a, *b);
	*a = (*a)->next;
	while ((*a)->title != head)
	{
		fill_move(*a, *b);
		*a = (*a)->next;
	}
	move = find_cheapest_node_move(a);
	do_rotates(a, b, move);
	do_rev_rotates(a, b, move);
	do_pb(a, b);
}

static t_move	*find_cheapest_node_move(t_node **a)
{
	t_move	*cheapest_move;

	if (a == NULL)
		return (NULL);
	cheapest_move = &((*a)->move);
	if (*a == (*a)->next)
		return (cheapest_move);
	*a = (*a)->next;
	while ((*a)->title != head)
	{
		if (cheapest_move->steps > (*a)->move.steps)
			cheapest_move = &((*a)->move);
		*a = (*a)->next;
	}
	return (cheapest_move);
}

static void	do_rotates(t_node **a, t_node **b, t_move *move)
{
	while (move->rot_a > 0 && move->rot_b > 0)
	{
		move->rot_a--;
		move->rot_b--;
		do_rr(a, b);
	}
	while (move->rot_a > 0)
	{
		move->rot_a--;
		do_ra(a);
	}
	while (move->rot_b > 0)
	{
		move->rot_b--;
		do_rb(b);
	}
}

static void	do_rev_rotates(t_node **a, t_node **b, t_move *move)
{
	while (move->rot_a < 0 && move->rot_b < 0)
	{
		move->rot_a++;
		move->rot_b++;
		do_rrr(a, b);
	}
	while (move->rot_a < 0)
	{
		move->rot_a++;
		do_rra(a);
	}
	while (move->rot_b < 0)
	{
		move->rot_b++;
		do_rrb(b);
	}
}
