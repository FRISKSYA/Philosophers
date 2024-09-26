/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:29:38 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 23:55:17 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_dinner(t_table *table)
{
	int	i;
	int	index;
	
	if (table->nbr_limit_meals == 0)
		return ;
	else if (1 == table->philo_nbr)
		return ;// TODO:
	i = 0;
	index = 0;
	table->start_simulation = gettime(MILLISECOND);
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
	return ;
}
