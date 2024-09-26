/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:38 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 16:32:45 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*test_thread(void *arg)
{
	t_table	*table;
	size_t	i;

	i = 0;
	table = (t_table *)arg;
	while (i < table->philo_nbr)
	{
		printf("check segv --- 1 ---\n");
		pthread_mutex_lock(&table->forks[i].fork);
		printf("check segv --- lock ---\n");
		// if (table->philos[i].id % 2 == 1)
		// 	table->philos[i].first_fork->fork_id += 1;
		// else
		// 	table->philos[i].first_fork->fork_id *= 1;
		// if (table->philos[i].first_fork->fork_id >= 100)
		// {
		// 	printf("%ld now philos[%d].r_fork is greater than 100.\n", current_timestamp(), (int)i);
		// 	pthread_mutex_unlock(&table->forks[i].fork);
		// 	break ;
		// }
		pthread_mutex_unlock(&table->forks[i].fork);
		i++;
	}
	return (NULL);
}

// static void	*simulate_dinner(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	wait_all_threads(philo->table); // TODO
// 	return (NULL);	
// }

// static void	*eat_thread(void *arg)
// {
// 	t_table	*table;
// 	size_t	i;

// 	i = 0;
// 	table = (t_table *)arg;
// 	while (i < table->philo_nbr)
// 	{
// 		pthread_mutex_lock(&table->forks[i].fork);
// 		if (table->philos[i].id % 2 == 1)
// 			table->philos[i].r_fork->fork_id += 1;
// 		else
// 			table->philos[i].r_fork->fork_id *= 1;
// 		pthread_mutex_unlock(&table->forks[i].fork);
// 		i++;
// 	}
// 	return (NULL);
// }

// TODO: dev
void	eat_dinner(t_table *table)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (index < (int)table->philo_nbr)
	{
		i = pthread_create(&table->philos[index].thread_id, NULL, test_thread, table);
		if (i != 0)
		{
			print_err("pthread_create");
			exit(EXIT_FAILURE);
		}
		index++;
	}
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
	index = 0;
	while (index < (int)table->philo_nbr)
	{
		printf("Threads done. forks[%d].fork_id : [%d]\n", index, table->forks[index].fork_id);
		index++;
	}
	return ;
}
