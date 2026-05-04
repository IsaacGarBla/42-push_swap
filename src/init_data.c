/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:52:02 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 14:52:38 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"

t_status	init_data(t_data *ps)
{
	ps->bench = 0;
	ps->disorder = 0;
	ps->strategy = STG_NONE;
	ps->stack_a = stack_create();
	if (ps->stack_a == NULL)
		return (ERROR);
	ps->stack_b = stack_create();
	if (ps->stack_b == NULL)
	{
		stack_destroy(ps->stack_a);
		return (ERROR);
	}
	return (OK);
}
