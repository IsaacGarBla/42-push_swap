/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarcia- <igarcia-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:24:02 by igarcia-          #+#    #+#             */
/*   Updated: 2026/05/06 01:27:01 by igarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_input.h"

static bool	add_number(t_stack *stack, int value)
{
	t_stack_node	*node;

	node = stack_node_create(value);
	if (node == NULL)
		return (false);
	else
		stack_push(stack, node);
	return (true);
}

static t_status	parse_numbers(t_data *ps, char *str)
{
	char		**numbers;
	int			i;
	int			value;
	t_status	status;

	i = 0;
	status = OK;
	numbers = ft_split_full(str, " ");
	while (numbers[i] && status == OK)
	{
		if (!is_valid_int(numbers[i], &value))
			status = UNRECOGNIZED_ARGUMENT;
		else if (stack_locate(ps->stack_a, value) != -1)
			status = DUPLICATE_NUMBER;
		else if (!add_number(ps->stack_a, value))
			status = MEMORY_ERROR;
		i++;
	}
	free_split(numbers);
	return (status);
}

static t_status	parse_strategy(t_data *ps, char *str)
{
	t_strategy	strategy;

	strategy = STG_NONE;
	if (ft_strcmp(str, STR_STG_SIMPLE) == 0)
		strategy = STG_SIMPLE;
	else if (ft_strcmp(str, STR_STG_MEDIUM) == 0)
		strategy = STG_MEDIUM;
	else if (ft_strcmp(str, STR_STG_COMPLEX) == 0)
		strategy = STG_COMPLEX;
	else if (ft_strcmp(str, STR_STG_ADAPTIVE) == 0)
		strategy = STG_ADAPTIVE;
	if (strategy != STG_NONE)
	{
		if (ps->strategy != STG_NONE)
			return (DUPLICATE_STRATEGY);
		ps->strategy = strategy;
		return (OK);
	}
	return (NO_STRATEGY);
}

static t_status	parse_benchmark(t_data *ps, char *str)
{
	if (ft_strcmp(str, STR_BENCHMARK) == 0)
	{
		if (ps->bench == true)
			return (DUBLICATE_BENCHMARK);
		ps->bench = true;
		return (OK);
	}
	return (NO_BENCHMARK);
}

int	parse_input(t_data *ps, int argc, char **argv)
{
	int			i;
	t_status	status;

	i = 1;
	status = OK;
	while (i < argc && status == OK)
	{
		status = parse_strategy(ps, argv[i]);
		if (status == NO_STRATEGY)
		{
			status = parse_benchmark(ps, argv[i]);
			if (status == NO_BENCHMARK)
				status = parse_numbers(ps, argv[i]);
		}
		if (status != OK)
			return (status);
		i++;
	}
	ps->disorder = stack_compute_disorder(ps->stack_a);
	return ((status && ps->stack_a->len > 0)
		+ STACK_EMPTY * (ps->stack_a->len == 0));
}
