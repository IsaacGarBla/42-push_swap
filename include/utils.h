/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didaguil <didaguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:10:53 by didaguil          #+#    #+#             */
/*   Updated: 2026/05/04 15:09:13 by didaguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "data.h"
# include <stdlib.h>
# include <unistd.h>

int			ft_strcmp(const char *s1, const char *s2);
t_status	error_exit(void);
void		free_data(t_data *data);

#endif /* UTILS_H */
