/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:25 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 15:08:50 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0'
		&& (unsigned char) s1[i] == (unsigned char) s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

void	free_data(t_data *data)
{
	if (data->stack_a != NULL)
		stack_destroy(data->stack_a);
	if (data->stack_b != NULL)
		stack_destroy(data->stack_b);
}

t_status	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(ERROR);
}
