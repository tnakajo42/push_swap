/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:20:23 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/30 16:33:52 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp -> next = new;
		}
	}
}

/* void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write (STDOUT_FILENO, elem->content, len);
	write (STDOUT_FILENO, "\n", 1);
}

int main(int argc, const char *argv[])
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("first");
	char		*str2 = strdup("second");
	char		*str3 = strdup("third");
	char		*str4 = strdup("fourth");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		begin = NULL;
		ft_lstadd_back(&begin, elem);
		ft_lstadd_back(&begin, elem2);
		ft_lstadd_back(&begin, elem3);
		ft_lstadd_back(&begin, elem4);
		while (begin)
		{
			ft_print_result(begin);
			begin = begin->next;
		}
	}
	return (0);
} */
