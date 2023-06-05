/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:26:53 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/05 15:55:43 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "checker_func_bonus.h"

typedef void	(*t_ps_func)(t_ps_ctx *);

static t_ps_func	checker_inst_to_func(char *inst)
{
	if (ft_strncmp("sa", inst, 3) == 0)
		return (ps_sa);
	if (ft_strncmp("sb", inst, 3) == 0)
		return (ps_sb);
	if (ft_strncmp("ss", inst, 3) == 0)
		return (ps_ss);
	if (ft_strncmp("pa", inst, 3) == 0)
		return (ps_pa);
	if (ft_strncmp("pb", inst, 3) == 0)
		return (ps_pb);
	if (ft_strncmp("ra", inst, 3) == 0)
		return (ps_ra);
	if (ft_strncmp("rb", inst, 3) == 0)
		return (ps_rb);
	if (ft_strncmp("rr", inst, 3) == 0)
		return (ps_rr);
	if (ft_strncmp("rra", inst, 3) == 0)
		return (ps_rra);
	if (ft_strncmp("rrb", inst, 3) == 0)
		return (ps_rrb);
	if (ft_strncmp("rrr", inst, 3) == 0)
		return (ps_rrr);
	return (NULL);
}

static int	ft_getchar(int fd)
{
	ssize_t	ret;
	char	c;

	ret = read(fd, &c, 1);
	if (ret == 1)
		return ((int)c);
	if (ret == 0)
		return (0);
	return (-1);
}

static int	checker_read_instruction(int fd, char *s)
{
	int	ret;

	ret = ft_getchar(fd);
	if (ret <= 0)
		return (ret);
	*(s++) = (char)ret;
	ret = ft_getchar(fd);
	if (ret <= 0)
		return (ret);
	*(s++) = (char)ret;
	ret = ft_getchar(fd);
	if (ret <= 0)
		return (ret);
	*(s++) = (char)ret;
	if (*(s - 1) == '\n')
	{
		*(s - 1) = '\0';
		return (1);
	}
	ret = ft_getchar(fd);
	*s = (char)ret;
	if (ret <= 0 || *s != '\n')
		return (ret);
	*s = '\0';
	return (1);
}

int	checker_execute(int fd, t_ps_ctx *ctx)
{
	char		buffer[4];
	int			ret;
	t_ps_func	func;

	ret = checker_read_instruction(fd, buffer);
	while (ret == 1)
	{
		func = checker_inst_to_func(buffer);
		if (func == NULL)
			return (0);
		func(ctx);
		ret = checker_read_instruction(fd, buffer);
	}
	if (ret == 0)
		return (1);
	return (0);
}
