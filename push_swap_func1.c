/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:49:24 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 15:18:57 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_sa(t_ps_ctx *ctx)
{
	t_list	*l;

	ft_putendl_fd("sa", STDOUT_FILENO);
	if (ft_lstsize(ctx->a) <= 1)
		return ;
	l = ctx->a;
	ctx->a = l->next;
	l->next = ctx->a->next;
	ctx->a->next = l;
}

void	ps_sb(t_ps_ctx *ctx)
{
	t_list	*l;

	ft_putendl_fd("sb", STDOUT_FILENO);
	if (ft_lstsize(ctx->b) <= 1)
		return ;
	l = ctx->b;
	ctx->b = l->next;
	l->next = ctx->b->next;
	ctx->b->next = l;
}

void	ps_ss(t_ps_ctx *ctx)
{
	ft_putendl_fd("ss", STDOUT_FILENO);
	ps_sa(ctx);
	ps_sb(ctx);
}

void	ps_pa(t_ps_ctx *ctx)
{
	t_list	*elem;

	ft_putendl_fd("pa", STDOUT_FILENO);
	if (ft_lstsize(ctx->b) == 0)
		return ;
	elem = ctx->b;
	ctx->b = ctx->b->next;
	ft_lstadd_front(&ctx->a, elem);
}

void	ps_pb(t_ps_ctx *ctx)
{
	t_list	*elem;

	ft_putendl_fd("pb", STDOUT_FILENO);
	if (ft_lstsize(ctx->a) == 0)
		return ;
	elem = ctx->a;
	ctx->a = ctx->a->next;
	ft_lstadd_front(&ctx->b, elem);
}
