/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakajo <tnakajo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:50:02 by tnakajo           #+#    #+#             */
/*   Updated: 2023/06/08 20:14:18 by tnakajo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
// # include <signal.h>
// # include <unistd.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
}					t_node;

typedef struct
{
	// void			*content;
	char			*content;
}					num_node;

#endif