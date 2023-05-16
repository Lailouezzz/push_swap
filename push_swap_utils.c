/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:22:04 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/16 11:30:16 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_utils.h"

int	ft_atoi_error(const char *str, int *nb)
{
	unsigned int	nbr;
	unsigned int	ocheck;
	int				sign;

	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '-' || *str == '+')
		++str;
	nbr = 0;
	while (ft_isdigit(*str) && *str != '\0')
	{
		ocheck = nbr;
		nbr *= 10;
		if (nbr / 10 != ocheck)
			return (0);
		nbr += (*(str++) - '0');
	}
	if (((nbr & (1u << ((sizeof(nbr) * 8) - 1))) != 0
			&& (nbr != (1u << ((sizeof(nbr) * 8) - 1)) || sign == 1))
		|| *str != '\0')
		return (0);
	*nb = (int)nbr * sign;
	return (1);
}

int	ft_atoip_error(const char **str, int *nb)
{
	unsigned int	nbr;
	unsigned int	ocheck;
	int				sign;

	if (**str == '-')
		sign = -1;
	else
		sign = 1;
	if (**str == '-' || **str == '+')
		++(*str);
	nbr = 0;
	while (ft_isdigit(**str) && **str != '\0')
	{
		ocheck = nbr;
		nbr *= 10;
		if (nbr / 10 != ocheck)
			return (0);
		nbr += (*((*str)++) - '0');
	}
	if (((nbr & (1u << ((sizeof(nbr) * 8) - 1))) != 0
			&& (nbr != (1u << ((sizeof(nbr) * 8) - 1)) || sign == 1))
		|| (**str != '\0' && **str != ' '))
		return (0);
	*nb = (int)nbr * sign;
	return (1);
}
