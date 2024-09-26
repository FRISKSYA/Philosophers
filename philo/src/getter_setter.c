/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:14:47 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 17:29:57 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

void	set_long(pthread_mutex_t *mutex, long int *dest, long int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long int	get_long(pthread_mutex_t *mutex, long int *value)
{
	long int	ret;

	pthread_mutex_lock(mutex);
	ret = *value;
	pthread_mutex_unlock(mutex);
	return (ret);
}

bool	finished_simulation(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}