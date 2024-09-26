/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:38 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 17:30:18 by kfukuhar         ###   ########.fr       */
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
		pthread_mutex_unlock(&table->forks[i].fork);
		i++;
	}
	return (NULL);
}

// TODO: dev
void	eat_dinner(t_table *table)
{
	int	i;
	int	index;

	if (table->nbr_limit_meals == 0)
		return ;
	else if (1 == table->philo_nbr)
		return ; // TODO:
	i = 0;
	index = 0;
	while (index < (int)table->philo_nbr)
	{
		i = pthread_create(&table->philos[index].thread_id, NULL, test_thread,
				table);
		if (i != 0)
		{
			print_err("pthread_create");
			exit(EXIT_FAILURE);
		}
		index++;
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
	index = 0;
	while (index < (int)table->philo_nbr)
	{
		printf("Threads done. forks[%d].fork_id : [%d]\n", index,
			table->forks[index].fork_id);
		index++;
	}
	return ;
}
