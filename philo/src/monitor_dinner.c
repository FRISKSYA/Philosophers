/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:20:46 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/28 19:21:16 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increase_long(pthread_mutex_t *mutex, long int *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

static bool	all_thread_running(pthread_mutex_t *mutex, long int *threads,
		long int philo_nbr)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(mutex);
	if (*threads == philo_nbr)
		ret = true;
	pthread_mutex_unlock(mutex);
	return (ret);
}

static bool	philo_died(t_philo *philo)
{
	long int	elapsed;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	if (elapsed > philo->table->time_to_die / 1e3)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	while (!all_thread_running(&table->table_mutex,
			&table->threads_runnning_nbr, table->philo_nbr))
		;
	while (!finished_simulation(table))
	{
		i = 0;
		while (i < (int)table->philo_nbr && !finished_simulation(table))
		{
			if (philo_died(&table->philos[i]))
			{
				set_bool(&table->table_mutex, &table->end_simulation, true);
				write_status(DIED, &table->philos[i], DEBUG_MODE);
			}
			i++;
		}
	}
	return (NULL);
}
