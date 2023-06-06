/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ctx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:34:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 19:22:11 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_utils.h"
#include "push_swap.h"

static int	ps_lstat(t_list *l, int idx)
{
	while (idx-- != 0)
		l = l->next;
	return (*((int *)l->content));
}

static int	ps_init_nb_occ(t_list *l, int nb)
{
	int	k;
	int	nbocc;

	k = 0;
	nbocc = 0;
	while (k < ft_lstsize(l))
	{
		if (ps_lstat(l, k) == nb)
			++nbocc;
		++k;
	}
	return (nbocc);
}

static int	ps_init_dup(t_list *l)
{
	int	k;

	k = 0;
	while (k < ft_lstsize(l))
	{
		if (ps_init_nb_occ(l, ps_lstat(l, k)) >= 2)
			return (0);
		++k;
	}
	return (1);
}

static t_ps_ctx	ps_init_ctx_one(const char *str)
{
	t_ps_ctx	ctx;
	int			*nb;

	ctx.a = NULL;
	ctx.b = NULL;
	while (*str != '\0')
	{
		nb = malloc(sizeof(*nb));
		if (ft_atoip_error(&str, nb) != 1)
		{
			free(nb);
			ft_lstclear(&ctx.a, free);
			break ;
		}
		ft_lstadd_back(&ctx.a, ft_lstnew(nb));
		while (*str == ' ')
			++str;
	}
	return (ctx);
}

t_ps_ctx	ps_init_ctx(char **strs, int nstr)
{
	t_ps_ctx	ctx;
	int			k;
	int			*nb;

	if (nstr == 1)
		return (ps_init_ctx_one(*strs));
	ctx.a = NULL;
	ctx.b = NULL;
	k = 0;
	while (k < nstr)
	{
		nb = malloc(sizeof(*nb));
		if (ft_atoi_error(strs[k], nb) != 1)
		{
			free(nb);
			ft_lstclear(&ctx.a, free);
			break ;
		}
		ft_lstadd_back(&ctx.a, ft_lstnew(nb));
		++k;
	}
	if (ps_init_dup(ctx.a) == 0)
		ft_lstclear(&ctx.a, free);
	return (ctx);
}
