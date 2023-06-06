/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_issort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 13:31:37 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_issort(t_ps_ctx *ctx)
{
	t_list	*l;

	l = ctx->a;
	while (l->next != NULL)
	{
		if (*((int *)l->content) > *((int *)l->next->content))
			return (0);
		l = l->next;
	}
	return (ft_lstsize(ctx->b) == 0);
}
