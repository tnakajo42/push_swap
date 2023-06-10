/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_iux_md_mi_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:21:16 by tnakajo           #+#    #+#             */
/*   Updated: 2023/01/11 21:17:54 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_u_md_mi_bonus(unsigned int u, int b, int a)
{
	int		i;
	int		j;
	char	*u_;
	int		len;
	int		a_;

	i = 0;
	j = 0;
	u_ = ft_itoa_bonus((long)u);
	len = ft_strlen_bonus(u_);
	a_ = a;
	if (len < a)
		while (len < a--)
			i = ft_found_c('0', i);
	if (u == 0 && a_ == 0)
		i = ft_found_c(' ', i);
	else
		i = ft_found_s(u_, i);
	while (b - i > 0)
		i = ft_found_c(' ', i);
	free (u_);
	return (i);
}

int	ft_found_x_md_mi_bonus(size_t x, int b, int a, char flag)
{
	int		i;
	int		len;
	int		a_;

	i = 0;
	len = ft_x_len_bonus(x, 0);
	a_ = a;
	if (flag == '#' && x != 0)
		i = ft_found_s("0x", i);
	if (len < a)
		while (len < a--)
			i = ft_found_c('0', i);
	if (x == 0 && a_ == 0)
		i = ft_found_c(' ', i);
	else
		i = ft_found_x(x, i);
	while (b - i > 0)
		i = ft_found_c(' ', i);
	return (i);
}

int	ft_found_bigx_md_mi_bonus(size_t bigx, int b, int a, char flag)
{
	int		i;
	int		len;
	int		a_;

	i = 0;
	len = ft_x_len_bonus(bigx, 0);
	a_ = a;
	if (flag == '#' && bigx != 0)
		i = ft_found_s("0X", i);
	if (len < a)
		while (len < a--)
			i = ft_found_c('0', i);
	if (bigx == 0 && a_ == 0)
		i = ft_found_c(' ', i);
	else
		i = ft_found_bigx(bigx, i);
	while (b - i > 0)
		i = ft_found_c(' ', i);
	return (i);
}
