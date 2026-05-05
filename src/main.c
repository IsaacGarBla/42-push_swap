/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 01:30:49 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "init_data.h"
#include "parse_input.h"
#include "dispatch_strategy.h"
#include "utils.h"

void	on2_insertion(t_data *ps);

int	main(int argc, char **argv)
{
	t_data		ps;
	t_status	status;

	if (argc < 2)
		return (OK);
	status = init_data(&ps);
	if (status == OK)
	{
		status = parse_input(&ps, argc, argv);
		if (status == OK)
		{
			// status = dispatch_strategy(&ps);
			ft_printf("Stack A:\n");
			print_stack(ps.stack_a);
			on2_insertion(&ps);
		}
	}
	if (status != OK)
	{
		free_data(&ps);
		error_exit(status);
	}
	ft_printf("Stack A:\n");
	print_stack(ps.stack_a);
	print_stats(&ps);
	free_data(&ps);
	return (OK);
}
