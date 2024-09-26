/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:49:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 17:32:45 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->ready_all_threads))
		;
}

void	*simulate_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	while (!finished_simulation(philo->table))
	{
		if (philo->full)
			break ;
		// eat(philo); // TODO
		// thinking(philo); // TODO
	}
	return (NULL);
}
