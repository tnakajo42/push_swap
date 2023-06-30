/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:13:50 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 19:12:05 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../turk_method/turk_method.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc == 1)
		return (0);
	if (!argument_validation(argv))
	{
		write(2, "Error\n", 6);
		return (42);
	}
	a = create_stack(argv);
	b = NULL;
	if (size_of_stack(a) == 3 && !is_a_ordered(a))
		sort_three(&a);
	else if (size_of_stack(a) == 4 && !is_a_ordered(a))
		sort_four(&a, &b);
	else if (size_of_stack(a) == 5 && !is_a_ordered(a))
		sort_five(&a, &b);
	else
		turk_method(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
