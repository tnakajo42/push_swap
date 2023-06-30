/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:48:26 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/29 14:14:27 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static int	pos_finder_for_four_nums(t_node **a, int b, int num_b)
{
	int	pos;

	pos = 1;
	if ((*a)->value < b)
		pos++;
	if ((*a)->next->value < b)
		pos++;
	if ((*a)->next->next->value < b)
		pos++;
	if (num_b == 0 && (*a)->prev->value < b)
		pos++;
	return (pos);
}

static int	do_pb_biggest_lowest_in4(t_node **a, t_node **b, int n_b, int max_p)
{
	int	min_p;
	int	p_a;
	int	p_prev_a;

	min_p = 1;
	p_a = pos_finder_for_four_nums(a, (*a)->value, n_b);
	p_prev_a = pos_finder_for_four_nums(a, (*a)->prev->value, n_b);
	if (p_a == max_p || p_a == min_p)
	{
		if (p_a == max_p || (*a)->next->value > (*a)->next->next->value)
			do_pb(a, b);
		else if ((*a)->next->next->value > (*a)->prev->value)
			do_pb(a, b);
	}
	else if (p_prev_a == min_p || p_prev_a == max_p)
	{
		do_rra(a);
		do_pb(a, b);
	}
	else if (p_a != min_p)
	{
		do_ra(a);
		do_pb(a, b);
	}
	return (n_b + 1);
}

void	sort_four(t_node **a, t_node **b)
{
	int	pos;
	int	num_b;

	num_b = do_pb_biggest_lowest_in4(a, b, 0, 4);
	sort_three(a);
	pos = pos_finder_for_four_nums(a, (*b)->value, num_b);
	if (pos == 1)
		do_pa(a, b);
	else if (pos == 4)
	{
		do_pa(a, b);
		do_ra(a);
	}
	else if (pos != 1)
	{
		do_ra(a);
		do_pa(a, b);
		do_rra(a);
	}
}
