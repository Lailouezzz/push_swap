/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:22:04 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/17 10:51:17 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
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

int	ps_lstcmp(t_list *a, t_list *b)
{
	return (*((int *)a->content) - *((int *)b->content));
}

int	ps_where_min(t_list *l)
{
	int		k;
	int		minidx;
	t_list	*min;

	minidx = 0;
	min = l;
	k = 0;
	while (l != NULL)
	{
		if (ps_lstcmp(l, min) < 0)
		{
			minidx = k;
			min = l;
		}
		++k;
		l = l->next;
	}
	return (minidx);
}

int	ps_min(t_list *l)
{
	int	min;

	if (ft_lstsize(l) == 0)
		return (INT_MIN);
	min = *((int *)l->content);
	l = l->next;
	while (l != NULL)
	{
		if (*((int *)l->content) < min)
			min = *((int *)l->content);
		l = l->next;
	}
	return (min);
}
