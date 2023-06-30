/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:56:11 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/29 11:54:25 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<limits.h>
# include "../libft/libft.h"

typedef enum e_title {nohead, head}	t_title;

typedef struct s_move
{
	int	rot_a;
	int	rot_b;
	int	steps;
}	t_move;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	t_title			title;
	t_move			move;
}	t_node;

/* create stack */
t_node	*create_node(int n);
t_node	*create_stack(char **av);
void	free_stack(t_node **stack);
void	free_stacks(t_node **a, t_node **b);

/* argument validation */
enum	e_boolean {false, true};
int		argument_validation(char **av);

/* operations */
void	do_sa(t_node **a);
void	do_sb(t_node **b);
void	do_ss(t_node **a, t_node **b);
void	do_pa(t_node **a, t_node **b);
void	do_pb(t_node **a, t_node **b);
void	do_ra(t_node **a);
void	do_rb(t_node **b);
void	do_rr(t_node **a, t_node **b);
void	do_rra(t_node **a);
void	do_rrb(t_node **b);
void	do_rrr(t_node **a, t_node **b);

#endif
