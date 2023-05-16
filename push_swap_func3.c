/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:39:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 15:19:24 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_func.h"
#include "push_swap.h"

void	ps_rrr(t_ps_ctx *ctx)
{
	ft_putendl_fd("rrr", STDOUT_FILENO);
	ps_rra(ctx);
	ps_rrb(ctx);
}
