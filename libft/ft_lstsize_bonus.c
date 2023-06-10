/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:37:01 by tnakajo           #+#    #+#             */
/*   Updated: 2023/02/11 15:10:27 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node)
	{
		i++;
		node = node -> next;
	}
	return (i);
}
/* 
void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*elemnull;

	char		c;
	char		*str = ft_strdup("hey");
	char		*str2 = ft_strdup("say");
	char		*str3 = ft_strdup("jump");
	char		*str4 = ft_strdup("kick");
	char		*strnull = ft_strdup("");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elemnull = ft_lstnew(strnull);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
    printf("-----\n");
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4 || !elemnull)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		elem->next = elem2;
		elem2->next = elem3;
		elem3->next = elem4;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
		elem2->next = NULL;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
		elem = NULL;
		c = ft_lstsize(elem) + 48;
		write(1, &c, 1);
		write(1, "\n", 1);
	}
    printf("-----\n");
	return (0);
}
 */