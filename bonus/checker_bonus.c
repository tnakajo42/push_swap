/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:21:08 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:38:21 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line_bonus/get_next_line_bonus.h"
#include "../turk_method/turk_method.h"

int	main(int argc, char **argv)
{
	char	*line;
	t_node	*a;
	t_node	*b;

	arg_check(argc, argv);
	a = create_stack(argv);
	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		do_rules (&a, &b, line);
		free (line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_a_sorted(a) && (b == NULL))
		write (STDOUT_FILENO, "OK\n", 3);
	else
		write (STDOUT_FILENO, "KO\n", 3);
	free_stacks(&a, &b);
	return (0);
}

void	arg_check(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (!argument_validation(argv))
	{
		write (STDERR_FILENO, "Error\n", 6);
		exit (42);
	}
}

void	do_rules(t_node **a, t_node **b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		do_pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		do_pb(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		do_ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		do_rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		do_rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		do_rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		do_rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		do_rrr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
		do_sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		do_sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		do_ss(a, b);
	else
		error_exit(a, b, line);
}

void	error_exit(t_node **a, t_node **b, char *line)
{
	free (line);
	free_stacks (a, b);
	write (STDERR_FILENO, "Error\n", 6);
	exit (42);
}
