/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:21:16 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 18:11:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_func.h"
#include "push_swap_sort_func.h"
#include "push_swap_utils.h"

static int	ps_lstat(t_list *l, int idx)
{
	while (idx-- != 0)
		l = l->next;
	return (*((int *)l->content));
}

static int	ps_sort_insert_index(t_ps_ctx *ctx)
{
	int	idx;
	int	nb;

	idx = 0;
	nb = ps_lstat(ctx->b, 0);
	while (idx < ft_lstsize(ctx->a) && nb > ps_lstat(ctx->a, idx)
		&& (idx == 0
			|| ps_lstat(ctx->a, idx - 1) < ps_lstat(ctx->a, idx)))
		++idx;
	return (idx);
}

static void	ps_sort_insert_a(t_ps_ctx *ctx)
{
	int	idx;
	int	k;

	idx = ps_sort_insert_index(ctx);
	if (idx <= 1)
		ps_pa(ctx);
	if (idx == 1)
		ps_sa(ctx);
	if (idx <= 1)
		return ;
	k = 0;
	if (idx < ft_lstsize(ctx->a) - idx)
		while (k++ < idx)
			ps_ra(ctx);
	else
	{
		idx = ft_lstsize(ctx->a) - idx;
		if (idx == 0)
		{
			ps_pa(ctx);
			ps_ra(ctx);
			return ;
		}
		while (k++ < idx)
			ps_rra(ctx);
	}
	ps_pa(ctx);
}

void	ps_sort_five(t_ps_ctx *ctx)
{
	int	minidx;
	int	k;

	while (ft_lstsize(ctx->a) != 3)
		ps_pb(ctx);
	ps_sort_small(ctx);
	if (ft_lstsize(ctx->b) == 2)
		if (ps_lstat(ctx->b, 0) > ps_lstat(ctx->b, 1))
			ps_sb(ctx);
	while (ft_lstsize(ctx->b) != 0)
		ps_sort_insert_a(ctx);
	minidx = ps_where_min(ctx->a);
	k = 0;
	if (minidx < ft_lstsize(ctx->a) - minidx)
		while (k++ < minidx)
			ps_ra(ctx);
	else
	{
		minidx = ft_lstsize(ctx->a) - minidx;
		while (k++ < minidx)
			ps_rra(ctx);
	}
}
