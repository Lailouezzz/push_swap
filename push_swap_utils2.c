/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:51:09 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/17 10:55:51 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "push_swap_utils.h"

int	ps_max(t_list *l)
{
	int	max;

	if (ft_lstsize(l) == 0)
		return (INT_MIN);
	max = *((int *)l->content);
	l = l->next;
	while (l != NULL)
	{
		if (*((int *)l->content) > max)
			max = *((int *)l->content);
		l = l->next;
	}
	return (max);
}

int	ps_where_lower(t_list *l, int nb)
{
	int	k;

	k = 0;
	while (l != NULL)
	{
		if (*((int *)l->content) <= nb)
			return (k);
		++k;
		l = l->next;
	}
	return (-1);
}

static int	ps_where_last_lower(t_list *l, int nb)
{
	int	k;
	int	idx;

	k = 0;
	idx = -1;
	while (l != NULL)
	{
		if (*((int *)l->content) <= nb)
			idx = k;
		++k;
		l = l->next;
	}
	return (idx);
}

int	ps_where_qlower(t_list *l, int nb)
{
	int	lidx;
	int	fidx;

	lidx = ps_where_last_lower(l, nb);
	fidx = ps_where_lower(l, nb);
	if (ft_lstsize(l) - lidx < fidx)
		return (lidx);
	return (fidx);
}
