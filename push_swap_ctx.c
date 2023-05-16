/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ctx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:34:28 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 11:34:57 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_utils.h"
#include "push_swap.h"

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
	return (ctx);
}
