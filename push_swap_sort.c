/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:47:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 12:46:05 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_sort_func.h"

void	ps_sort(t_ps_ctx *ctx)
{
	if (ft_lstsize(ctx->a) <= 10)
		ps_sort_brute(ctx);
	else if (ft_lstsize(ctx->a) < 100)
		ps_sort_quick(ctx, 5);
	else if (ft_lstsize(ctx->a) < 250)
		ps_sort_quick(ctx, 6);
	else
		ps_sort_quick(ctx, 13);
}
