/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:33:30 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/24 21:30:25 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f || !del)
		return (NULL);
	begin = NULL;
	while (lst)
	{
		new = ft_lstnew((f)(lst -> content));
		if (!new)
		{
			ft_lstclear(&begin, del);
			free(new);
			return (NULL);
		}
		ft_lstadd_back(&begin, new);
		lst = lst -> next;
	}
	free(new);
	return (begin);
}

/* void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, ((char *)elem->content), len);
	write(1, "\n", 1);
}

void	*ft_map(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}

void    ft_del(void *content)
{
	free(content);
}

int main(int argc, const char *argv[])
{
	t_list		*lst;
	char *str1 = ft_strdup("happy");
	char *str2 = ft_strdup("children");
	char *str3 = ft_strdup("merry");
	char *str4 = ft_strdup("christmas");

	printf("here\n");
	ft_lstadd_back(&lst, ft_lstnew(str1));
	ft_lstadd_back(&lst, ft_lstnew(str2));
	ft_lstadd_back(&lst, ft_lstnew(str3));
	ft_lstadd_back(&lst, ft_lstnew(str4));
	free(str1);

	t_list		*list;
	alarm(5);
	if (atoi(argv[1]) == 1)
	{
		if (!(list = ft_lstmap(lst, &ft_map, &ft_del)))
			return (0);
		if (list == lst)
			printf("A new list is not returned\n");
		int i;
		i = 0;
		ft_print_result(list);
		while (list->next)
		{
			list = list->next;
			ft_print_result(list);
			i++;
		}
	}
	ft_lstclear(&lst, &ft_del);
	ft_lstclear(&list, &ft_del);

	return (0);
} */
