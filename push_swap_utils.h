/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:22 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/17 10:52:26 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

# include "push_swap.h"

/* Return : the difference between the pointer pointed by a and b */
int	ps_lstcmp(t_list *a, t_list *b);

/* Return : 1 if str is entirely a number who fit in a int
 * 		nb is set to the number in str */
int	ft_atoi_error(const char *str, int *nb);

/* Return : 1 if str is entirely a number who fit in a int
 * 		nb is set to the number in str, str is after the number*/
int	ft_atoip_error(const char **str, int *nb);

/* Return : the index of the min of l */
int	ps_where_min(t_list *l);

int	ps_min(t_list *l);
int	ps_max(t_list *l);

/* Return : the index of the first occurence of an element lower than nb */
int	ps_where_lower(t_list *l, int nb);
/* Return : the index of the best occurence of an element lower than nb */
int	ps_where_qlower(t_list *l, int nb);

#endif
