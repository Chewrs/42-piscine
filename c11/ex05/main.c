/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjunpuan <wjunpuan@student.42bangkok.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:59:17 by wjunpuan          #+#    #+#             */
/*   Updated: 2026/05/28 17:07:09 by wjunpuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_op_index(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '*')
		return (2);
	if (op == '/')
		return (3);
	if (op == '%')
		return (4);
	return (-1);
}

void	init_ops(int (*ops[5])(int, int))
{
	ops[0] = ft_add;
	ops[1] = ft_sub;
	ops[2] = ft_mul;
	ops[3] = ft_div;
	ops[4] = ft_mod;
}

int	check_error(char op, int b)
{
	if (op == '/' && b == 0)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	if (op == '%' && b == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	op;
	int	(*ops[5])(int, int);

	if (argc != 4)
		return (0);
	if (argv[2][1] != '\0')
		return (ft_putstr("0\n"), 0);
	init_ops(ops);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = get_op_index(argv[2][0]);
	if (op == -1)
		ft_putstr("0");
	else if (!check_error(argv[2][0], b))
		ft_putnbr(ops[op](a, b));
	ft_putstr("\n");
	return (0);
}
