/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:50:02 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/10 12:14:40 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// export PATH=$HOME/Downloads/code-stable-x64/VSCode-linux-x64/bin:$PATH
// gcc main.c -o push_swap && ./push_swap
// https://codeberg.org/Vusk/push_swap
// gcc main.c libft/*.c ft_printf/*.c -o push_swap && ./push_swap 3 1 5

#include "pushswap.h"
#include <unistd.h>
#include <stdio.h>

num_node *swap_a(num_node	*stack_a)
{
	char *str;

	str = stack_a[1].content;
	stack_a[1].content = stack_a[2].content;
	stack_a[2].content = str;
    ft_printf("sa\n");
	return(stack_a);
}

int	main(int argc, char **argv)
{
	int			i;
	char		arg_len;
	num_node	*stack_a;
	num_node	*stack_b;
	
	i = 0;
	arg_len = 0;
	if (argc == 1)
		return (0);
	else if (argc > 2)
	{
		stack_a = malloc((argc - 1));
		stack_b = malloc((argc - 1));
		while(i < argc)
		{
			arg_len = ft_strlen(argv[i]);
			stack_a[i].content = malloc(arg_len * sizeof(char));
			stack_a[i].content = ft_strdup(argv[i]);
			stack_b[i].content = malloc(arg_len * sizeof(char));
			// stack_b[i].content = ft_strdup(argv[i]);
			i++;
		}
		stack_a[i].content = '\0';
		stack_b[i].content = '\0';
		// stack_a = swap_a(stack_a);
    	ft_printf("-----\n");
		i = 1;
		while(i < argc)
		{
			ft_printf("%s %s\n", stack_a[i].content, stack_b[i].content);
			i++;
		}
		ft_printf("   \na b\n");
	}
    printf("-----\n");
	return (0);
}
