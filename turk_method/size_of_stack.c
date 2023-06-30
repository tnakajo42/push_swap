/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:37:07 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:38:09 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	size_of_stack(t_node *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	stack = stack->next;
	size = 1;
	while (stack->title != head)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}
