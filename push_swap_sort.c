/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:47:26 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 15:22:02 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_func.h"
#include "push_swap_utils.h"

void	ps_sort(t_ps_ctx *ctx)
{
	t_list	*top;

	while (ft_lstsize(ctx->a) != 0)
	{
		top = ctx->a;
		while (ft_lstsize(ctx->b) != 0 && ps_lstcmp(ctx->b, top) > 0)
			ps_pa(ctx);
		ps_pb(ctx);
	}
}
