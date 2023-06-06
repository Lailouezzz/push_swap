/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_func.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:45:24 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 15:21:06 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_SORT_FUNC_H
# define PUSH_SWAP_SORT_FUNC_H

void	ps_sort_small(t_ps_ctx *ctx);
void	ps_sort_five(t_ps_ctx *ctx);
void	ps_sort_quick(t_ps_ctx *ctx, int time);

#endif