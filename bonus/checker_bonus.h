/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:35:35 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/27 18:52:55 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../main/push_swap.h"

void	error_exit(t_node **a, t_node **b, char *line);
void	do_rules(t_node **a, t_node **b, char *line);
void	arg_check(int argc, char **argv);

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