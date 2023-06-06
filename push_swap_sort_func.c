/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:47:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 16:56:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_func.h"
#include "push_swap_utils.h"

static void	ps_sort_pivot(t_ps_ctx *ctx, int pivot)
{
	int		idx;

	idx = ps_where_qlower(ctx->a, pivot);
	while (idx != -1)
	{
		if (ft_lstsize(ctx->a) - idx > idx)
			while (idx-- != 0)
				ps_ra(ctx);
		else if (idx != 0)
		{
			idx = ft_lstsize(ctx->a) - idx;
			while (idx-- != 0)
				ps_rra(ctx);
		}
		ps_pb(ctx);
		idx = ps_where_qlower(ctx->a, pivot);
	}
}

static void	ps_sort_pusha(t_ps_ctx *ctx, int idx)
{
	int	k;

	k = 0;
	if (ft_lstsize(ctx->b) - idx > idx)
		while (k++ < idx)
			ps_rb(ctx);
	else if (idx != 0)
	{
		idx = ft_lstsize(ctx->b) - idx;
		while (k++ < idx)
			ps_rrb(ctx);
	}
	ps_pa(ctx);
}

static void	ps_sort_end(t_ps_ctx *ctx)
{
	int	maxidx;

	if (ft_lstsize(ctx->b) <= 1)
		return ;
	while (ft_lstsize(ctx->b) != 0)
	{
		maxidx = ps_where_max(ctx->b);
		ps_sort_pusha(ctx, maxidx);
	}
}

void	ps_sort_quick(t_ps_ctx *ctx, int time)
{
	int		pivot;
	int		k;
	int		min;
	int		max;

	if (ft_lstsize(ctx->a) <= 1)
		return ;
	min = ps_min(ctx->a);
	max = ps_max(ctx->a);
	k = 1;
	while (ft_lstsize(ctx->a) != 0)
	{
		pivot = min + ((max - min) / time) * k;
		ps_sort_pivot(ctx, pivot);
		++k;
	}
	ps_sort_end(ctx);
}
