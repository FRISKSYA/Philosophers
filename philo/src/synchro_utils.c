/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:49:18 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 16:53:35 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void wait_all_threads(t_table *table)
{
    while (!get_bool(&table->table_mutex, &table->ready_all_threads))
    ;
}

void	*simulate_dinner(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table); // TODO
	return (NULL);
}
