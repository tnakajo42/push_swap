/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:19:30 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:51:31 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static int	pos_finder(t_node **a, int b, int num_b)
{
	int	pos;

	pos = 1;
	if ((*a)->value < b)
		pos++;
	if ((*a)->next->value < b)
		pos++;
	if ((*a)->next->next->value < b)
		pos++;
	if (num_b <= 1 && (*a)->next->next->next->value < b)
		pos++;
	if (num_b == 0 && (*a)->next->next->next->next->value < b)
		pos++;
	return (pos);
}

static int	do_pb_biggest_or_lowest(t_node **a, t_node **b, int n_b, int max_p)
{
	int	min_p;
	int	pos_this_a;
	int	pos_next_a;
	int	pos_prev_a;

	min_p = 1;
	pos_this_a = pos_finder(a, (*a)->value, n_b);
	pos_next_a = pos_finder(a, (*a)->next->value, n_b);
	pos_prev_a = pos_finder(a, (*a)->prev->value, n_b);
	if (pos_prev_a == min_p || pos_prev_a == max_p)
		do_rra(a);
	else if (pos_next_a == min_p || pos_next_a == max_p)
		do_ra(a);
	else if (pos_this_a != min_p && pos_this_a != max_p)
	{
		do_ra(a);
		do_ra(a);
	}
	do_pb(a, b);
	return (n_b + 1);
}

void	sort_five(t_node **a, t_node **b)
{
	int	pos;
	int	num_b;

	num_b = do_pb_biggest_or_lowest(a, b, 0, 5);
	num_b = do_pb_biggest_or_lowest(a, b, num_b, 4);
	sort_three(a);
	while (num_b)
	{
		pos = pos_finder(a, (*b)->value, num_b);
		if (pos == 1)
			do_pa(a, b);
		else if ((num_b == 2 && pos == 4) || (num_b == 1 && pos == 5))
		{
			do_pa(a, b);
			do_ra(a);
		}
		else
		{
			do_ra(a);
			do_pa(a, b);
			do_rra(a);
		}
		num_b--;
	}
}
