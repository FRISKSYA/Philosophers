/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:54:33 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 13:28:00 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork(t_table *table)
{
	size_t	i;

	table->forks = (t_fork *)malloc(table->philo_nbr * sizeof(t_fork));
	if (table->forks == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < table->philo_nbr)
	{
		table->forks[i].fork_id = i;
		if (pthread_mutex_init(&table->forks[i].fork, NULL) < 0)
		{
			while (i > 0)
				pthread_mutex_destroy(&table->forks[i--].fork);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	assign_forks(t_philo *philo, t_fork *forks, int philo_pos)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_pos + 1) % philo_nbr];
	philo->second_fork = &forks[philo_pos];
	if (philo->id % 2)
	{
		philo->first_fork = &forks[philo_pos];
		philo->second_fork = &forks[(philo_pos + 1) % philo_nbr];
	}

}

static int	init_philo(t_table *table)
{
	size_t	i;

	table->philos = (t_philo *)malloc(table->philo_nbr * sizeof(t_philo));
	if (table->philos == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_counter = 0;
		table->philos[i].full = false;
		table->philos[i].last_meal_time = 0;
		assign_forks(table->philos, table->forks, i);
		table->philos[i].table = table;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_data(t_table **table, char **argv)
{
	size_t	i;

	*table = (t_table *)malloc(sizeof(t_table));
	if (*table == NULL)
		return (EXIT_FAILURE);
	i = 1;
	(*table)->philo_nbr = ft_atoi(argv[i++]);
	(*table)->time_to_die = ft_atoi(argv[i++]);
	(*table)->time_to_eat = ft_atoi(argv[i++]);
	(*table)->time_to_sleep = ft_atoi(argv[i++]);
	if (argv[i])
		(*table)->nbr_limit_meals = ft_atoi(argv[i]);
	else
		(*table)->nbr_limit_meals = -1;
	(*table)->start_simulation = current_timestamp();
	// FIXME: rm
	printf("%lld begin simulation.\n", (*table)->start_simulation);
	if (init_fork(*table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_philo(*table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
