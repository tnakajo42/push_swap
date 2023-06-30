/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:37:36 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		push(t_node **dest, t_node **src);
static t_node	*pop(t_node **src);

void	do_pa(t_node **a, t_node **b)
{
	if (push(a, b))
		write (STDOUT_FILENO, "pa\n", 3);
}

void	do_pb(t_node **a, t_node **b)
{
	if (push(b, a))
		write (STDOUT_FILENO, "pb\n", 3);
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
