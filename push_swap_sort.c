/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:47:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 15:23:48 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_func.h"
#include "push_swap_sort_func.h"

void	ps_sort(t_ps_ctx *ctx)
{
	if (ft_lstsize(ctx->a) <= 1)
		return ;
	else if (ft_lstsize(ctx->a) <= 2)
	{
		if (*((int *)ctx->a->content) > *((int *)ctx->a->next->content))
			ps_sa(ctx);
	}
	else if (ft_lstsize(ctx->a) <= 3)
		ps_sort_small(ctx);
	else if (ft_lstsize(ctx->a) <= 5)
		ps_sort_five(ctx);
	else if (ft_lstsize(ctx->a) < 100)
		ps_sort_quick(ctx, 5);
	else if (ft_lstsize(ctx->a) < 250)
		ps_sort_quick(ctx, 6);
	else
		ps_sort_quick(ctx, 13);
}
