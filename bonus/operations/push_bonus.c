/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:14 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:51:07 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int		push(t_node **dest, t_node **src);
static t_node	*pop(t_node **src);

void	do_pa(t_node **a, t_node **b)
{
	push(a, b);
}

void	do_pb(t_node **a, t_node **b)
{
	push(b, a);
}

static int	push(t_node **dest, t_node **src)
{
	t_node	*new_head;

	if (*src == NULL)
		return (0);
	if (!(*dest))
	{
		*dest = pop(src);
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
	else
	{
		new_head = pop(src);
		(*dest)->prev->next = new_head;
		new_head->prev = (*dest)->prev;
		new_head->next = (*dest);
		(*dest)->prev = new_head;
		(*dest)->title = nohead;
		(*dest) = new_head;
	}
	return (1);
}

static t_node	*pop(t_node **src)
{
	t_node	*top;

	if (*src == (*src)->next)
	{
		top = *src;
		*src = NULL;
		return (top);
	}
	else
	{
		top = *src;
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		(*src) = (*src)->next;
		(*src)->title = head;
	}
	return (top);
}
