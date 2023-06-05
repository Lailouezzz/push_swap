/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:56:18 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 14:26:25 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

/* Return : 1 if all instructions is executed successfully
			0 if error while reading in fd */
int	checker_execute(int fd, t_ps_ctx *ctx);

/* Return : 1 if stack A is sorted */
int	checker_issort(t_ps_ctx *ctx);

#endif