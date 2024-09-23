/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:54:33 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 18:22:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: fill values
static int	init_fork(t_table *table)
{
	table->forks = (t_fork *)malloc(table->philo_nbr * sizeof(t_fork));
	if (table->forks == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_philo(t_table *table)
{
	table->philos = (t_philo *)malloc(table->philo_nbr * sizeof(t_philo));
	if (table->philos == NULL)
		return (EXIT_FAILURE);
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
		(*table)->nbr_limit_meals = 0;
	if (init_fork(*table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_philo(*table) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
