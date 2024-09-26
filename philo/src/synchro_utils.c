/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:49:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 19:55:20 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->ready_all_threads))
		;
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->first_fork->fork);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	pthread_mutex_lock(&philo->second_fork->fork);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo->philo_mutex, &philo->last_meal_time, gettime(MILLISECOND));
	philo->meals_counter++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->nbr_limit_meals > 0
		&& philo->meals_counter == (size_t)philo->table->nbr_limit_meals)
		set_bool(&philo->philo_mutex, &philo->full, true);
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
	return ;
}

// TODO
static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
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
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}
