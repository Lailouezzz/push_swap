/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:11:46 by ale-boud          #+#    #+#             */
/*   Updated: 2023/05/17 08:32:21 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_ps_ctx	ctx;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ctx = ps_init_ctx(argv + 1, argc - 1);
	if (ctx.a == NULL)
		return (error());
	ps_sort(&ctx);
	ft_lstclear(&ctx.a, free);
	ft_lstclear(&ctx.b, free);
	return (EXIT_SUCCESS);
}
