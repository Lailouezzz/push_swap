/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_issort_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:46:01 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 16:19:12 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	checker_issort(t_ps_ctx *ctx)
{
	t_list	*l;

	l = ctx->a;
	while (l->next != NULL)
	{
		if (*((int *)l->content) > *((int *)l->next->content))
			return (0);
		l = l->next;
	}
	return (1);
}
