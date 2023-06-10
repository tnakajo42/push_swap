/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:53:31 by tnakajo           #+#    #+#             */
/*   Updated: 2022/12/24 21:23:57 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
void	main(void)
{
	char	str1[] = "http://www.tutorialspoint.com";
	char	str2[] = "http://www.tutorialspoint.com";
	int		i;
	int		size;

	size = 10;
	printf("\n---------------memset---------------\n\n");
	i = 0;
	memset(str1, '\0', size);
	while (i < size || str1[i])
	{
		printf("%d ", str1[i]);
		i++;
	}
	printf("\n");
	i = 0;
	ft_memset(str2, '\0', size);
	while (i < size || str2[i])
	{
		printf("%d ", str2[i]);
		i++;
	}
	printf("\n-------------------------------------\n\n");
}
*/
