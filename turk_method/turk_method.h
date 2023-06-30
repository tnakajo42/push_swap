/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:37:25 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 19:53:49 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_METHOD_H
# define TURK_METHOD_H

# include "../main/push_swap.h"
/* turk_method.c */
void	turk_method(t_node **a, t_node **b);
void	sort_three(t_node **stack);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);

/* push_from_a_to_b.c */
void	push_from_a_to_b(t_node **a, t_node **b);

/* size_of_stack.c */
int		size_of_stack(t_node *stack);

/* is_ordered.c */
int		is_a_ordered(t_node *a);

/* is_sorted.c */
int		is_a_sorted(t_node *a);
int		is_b_sorted(t_node *b);

/* distance_from_top.c */
int		dist_w_rot(t_node *node);
int		dist_w_rev_rot(t_node *node);

/* fill_moves_n_steps.c */
void	fill_move(t_node *a, t_node *b);

/* position_in_b.c */
t_node	*new_pos_b(t_node *b, t_node *node);
t_node	*max_node_in_stack(t_node *stack);
t_node	*min_node_in_stack(t_node *stack);

/* position_in_a.c */
t_node	*node_new_pos_a(t_node *a, t_node *node);

/* empty_b.c */
void	empty_b(t_node **a, t_node **b);

/* finish_a.c */
void	finish_a(t_node **a);

#endif