/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:16:19 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 13:31:23 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_ps_ctx {
	t_list	*a;
	t_list	*b;
}	t_ps_ctx;

void		ps_sort(t_ps_ctx *ctx);

/* Return : a t_ps_ctx where the list a is initialized or NULL if error */
t_ps_ctx	ps_init_ctx(char **strs, int nstr);

/* Return : 1 if stack A is sorted */
int			ps_issort(t_ps_ctx *ctx);

#endif
