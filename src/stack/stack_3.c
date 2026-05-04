/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:15:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 15:24:52 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stack_locate(t_stack *stack, int value)
{
	int				pos;
	t_stack_node	*curr;

	pos = 0;
	curr = stack->first;
	while (curr != NULL)
	{
		if (curr->value == value)
			return (pos);
		curr = curr->next;
		pos++;
	}
	return (0);
}

int ft_stack_locate_next(t_stack *stack, int value)
{
	int				curr_pos;
	int				pos;
	int				max_value_found;
	t_stack_node	*curr;

	curr_pos = 0;
	pos = 0;
	max_value_found = __INT_MAX__;
	curr = stack->first;
	while (curr != NULL)
	{
		if (curr->value > value && curr->value < max_value_found)
		{
			pos = curr_pos;
			max_value_found = curr->value;
		}
		if (max_value_found == value + 1)
			break ;
		curr = curr->next;
		curr_pos++;
	}
	return (pos);
}
