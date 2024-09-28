/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:38 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/28 15:09:05 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: if elapsed time_to_die, auto die the philo.
static void	*lone_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	increase_long(&philo->table->table_mutex,
		&philo->table->threads_runnning_nbr);
	// TODO: Need to end_simulation
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!finished_simulation(philo->table))
		usleep(200);
	return (NULL);
}

// TODO: rm exit funcs
void	eat_dinner(t_table *table)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (table->nbr_limit_meals == 0)
		return ;
	else if (1 == table->philo_nbr)
		pthread_create(&table->philos[0].thread_id, NULL, lone_philo,
			&table->philos[0]);
	else
	{
		while (index < (int)table->philo_nbr)
		{
			i = pthread_create(&table->philos[index].thread_id, NULL,
					simulate_dinner, &table->philos[index]);
			if (i != 0)
			{
				print_err("pthread_create");
				exit(EXIT_FAILURE);
			}
			index++;
		}
	}
	if (pthread_create(&table->monitor, NULL, monitor_dinner, table) != 0)
	{
		print_err("pthread_create");
		exit(EXIT_FAILURE);
	}
	table->start_simulation = gettime(MILLISECOND);
	set_bool(&table->table_mutex, &table->ready_all_threads, true);
	index = 0;
	while (index < (int)table->philo_nbr)
	{
		i = pthread_join(table->philos[index].thread_id, NULL);
		if (i != 0)
		{
			print_err("pthread_join");
			exit(EXIT_FAILURE);
		}
		index++;
	}
	set_bool(&table->table_mutex, &table->end_simulation, true);
	if (pthread_join(table->monitor, NULL) != 0)
	{
		print_err("pthread_join");
		exit(EXIT_FAILURE);
	}
}
