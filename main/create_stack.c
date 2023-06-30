/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:00:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:39:03 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	malloc_error_exit(t_node **head);

t_node	*create_stack(char **av)
{
	int		i;
	t_node	*stack_head;
	t_node	*node_prev;

	stack_head = create_node(ft_atoi(av[1]));
	if (!(stack_head))
		malloc_error_exit(&stack_head);
	stack_head->title = head;
	stack_head->next = stack_head;
	stack_head->prev = stack_head;
	i = 2;
	node_prev = stack_head->prev;
	while (av[i])
	{
		node_prev->next = create_node(ft_atoi(av[i]));
		if (!(node_prev->next))
			malloc_error_exit(&stack_head);
		node_prev->next->next = stack_head;
		node_prev->next->prev = node_prev;
		node_prev = node_prev->next;
		node_prev->title = nohead;
		i++;
		stack_head->prev = node_prev;
	}
	return (stack_head);
}

t_node	*create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	free_stack(t_node **stack)
{
	t_node	*node;

	if ((*stack) == NULL)
		return ;
	(*stack)->prev->next = NULL;
	while (*stack)
	{
		node = (*stack);
		(*stack) = (*stack)->next;
		free(node);
	}
}

void	free_stacks(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
}

static void	malloc_error_exit(t_node **head)
{
	free_stack(head);
	write (STDERR_FILENO, "Error\n", 6);
	write (STDERR_FILENO, "Malloc failure.\n", 16);
	exit(42);
}
