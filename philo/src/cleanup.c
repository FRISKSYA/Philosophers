/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:15:48 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 14:00:10 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_table *table)
{
	size_t	i;

	i = 0;
	if (table && table->forks)
	{
		i = table->philo_nbr - 1;
		while (i > 0)
			pthread_mutex_destroy(&table->forks[i--].fork);
		free(table->forks);
	}
	pthread_mutex_destroy(&table->table_mutex);
	if (table && table->philos)
		free(table->philos);
	if (table)
		free(table);
	return ;
}
