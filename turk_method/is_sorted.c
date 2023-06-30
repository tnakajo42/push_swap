/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:36:47 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:50:57 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	is_a_sorted(t_node *a)
{
	if (a == NULL)
		return (true);
	while (a->next->title != head)
	{
		if (a->value > a->next->value)
			return (false);
		a = a -> next;
	}
	return (true);
}

int	is_b_sorted(t_node *b)
{
	if (b == NULL)
		return (true);
	while (b->next->title != head)
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}
