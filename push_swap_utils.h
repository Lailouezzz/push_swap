/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:19:22 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 11:22:57 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_UTILS_H
# define PUSH_SWAP_UTILS_H

/* Return : 1 if str is entirely a number who fit in a int
 * 		nb is set to the number in str */
int	ft_atoi_error(const char *str, int *nb);

/* Return : 1 if str is entirely a number who fit in a int
 * 		nb is set to the number in str, str is after the number*/
int	ft_atoip_error(const char **str, int *nb);

#endif
