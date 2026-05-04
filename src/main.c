/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/04 15:08:57 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "init_data.h"
#include "parse_input.h"
#include "dispatch_strategy.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_data	ps;

	if (argc < 2)
		error_exit();
	if (init_data(&ps) != OK)
		error_exit();
	if (parse_input(&ps, argc, argv) != OK)
		error_exit();
	if (dispatch_strategy(&ps) != OK)
		error_exit();
	free_data(&ps);
	return (OK);
}
