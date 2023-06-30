/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:23:10 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:38:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	duplicate_check(char **av);
static int	number_check(char **av);
static void	malloc_failure_exit(void);

int	argument_validation(char **av)
{
	return (duplicate_check(av) && number_check(av));
}

static int	duplicate_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

static int	number_check(char **av)
{
	int		i;
	char	*str_nbr;

	i = 1;
	while (av[i])
	{
		str_nbr = ft_itoa(ft_atoi(av[i]));
		if (!(str_nbr))
			malloc_failure_exit();
		if (ft_strcmp(av[i], str_nbr) != 0)
		{
			free(str_nbr);
			return (false);
		}
		free(str_nbr);
		++i;
	}
	return (true);
}

static void	malloc_failure_exit(void)
{
	write (STDERR_FILENO, "Error\n", 6);
	write (STDERR_FILENO, "Malloc failure.\n", 16);
	exit(42);
}
