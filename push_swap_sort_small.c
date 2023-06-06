/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:42:07 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 15:02:42 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_func.h"
#include "push_swap_utils.h"

static int	ps_lstat(t_list *l, int idx)
{
	while (idx-- != 0)
		l = l->next;
	return (*((int *)l->content));
}

void	ps_sort_small(t_ps_ctx *ctx)
{
	if (ps_lstat(ctx->a, 0) > ps_lstat(ctx->a, 1)
		&& ps_lstat(ctx->a, 1) > ps_lstat(ctx->a, 2))
	{
		ps_ra(ctx);
		ps_sa(ctx);
	}
	else if (ps_lstat(ctx->a, 0) > ps_lstat(ctx->a, 1)
		&& ps_lstat(ctx->a, 1) < ps_lstat(ctx->a, 2))
	{
		if (ps_lstat(ctx->a, 2) < ps_lstat(ctx->a, 0))
			ps_ra(ctx);
		else
			ps_sa(ctx);
	}
	else if (ps_lstat(ctx->a, 0) < ps_lstat(ctx->a, 1)
		&& ps_lstat(ctx->a, 1) > ps_lstat(ctx->a, 2))
	{
		if (ps_lstat(ctx->a, 2) > ps_lstat(ctx->a, 0))
		{
			ps_rra(ctx);
			ps_sa(ctx);
		}
		else
			ps_rra(ctx);
	}
}
