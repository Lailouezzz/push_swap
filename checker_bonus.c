/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:50:08 by ale-boud          #+#    #+#             */
/*   Updated: 2023/06/06 14:36:08 by ale-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker_bonus.h"
#include "push_swap.h"

static int	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	execute_error(void)
{
	ft_putstr_fd("Invalid instruction list\n", STDERR_FILENO);
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
	if (checker_execute(STDIN_FILENO, &ctx) == 0)
		return (execute_error());
	if (ps_issort(&ctx) == 1)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_lstclear(&ctx.a, free);
	ft_lstclear(&ctx.b, free);
}
