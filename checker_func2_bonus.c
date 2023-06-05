/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_func2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:25:57 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 14:09:23 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_ra(t_ps_ctx *ctx)
{
	t_list	*l;

	if (ft_lstsize(ctx->a) <= 1)
		return ;
	ft_lstlast(ctx->a)->next = ctx->a;
	l = ctx->a->next;
	ctx->a->next = NULL;
	ctx->a = l;
}

void	ps_rb(t_ps_ctx *ctx)
{
	t_list	*l;

	if (ft_lstsize(ctx->b) <= 1)
		return ;
	ft_lstlast(ctx->b)->next = ctx->b;
	l = ctx->b->next;
	ctx->b->next = NULL;
	ctx->b = l;
}

void	ps_rr(t_ps_ctx *ctx)
{
	ps_ra(ctx);
	ps_rb(ctx);
}

void	ps_rra(t_ps_ctx *ctx)
{
	t_list	*l;
	t_list	*ll;

	if (ft_lstsize(ctx->a) <= 1)
		return ;
	l = ft_lstlast(ctx->a);
	ll = ctx->a;
	while (ll->next->next != NULL)
		ll = ll->next;
	l->next = ctx->a;
	ll->next = NULL;
	ctx->a = l;
}

void	ps_rrb(t_ps_ctx *ctx)
{
	t_list	*l;
	t_list	*ll;

	if (ft_lstsize(ctx->b) <= 1)
		return ;
	l = ft_lstlast(ctx->b);
	ll = ctx->b;
	while (ll->next->next != NULL)
		ll = ll->next;
	l->next = ctx->b;
	ll->next = NULL;
	ctx->b = l;
}
