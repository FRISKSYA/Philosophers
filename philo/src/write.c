/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:38:21 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 18:44:51 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	write_status_debug(t_philo_status status, t_philo *philo,
		long int elapsed)
{
	if (status == TAKE_FIRST_FORK && !finished_simulation(philo->table))
		printf("%6ld %zu has taken the 1* fork [ %d ]\n", elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (status == TAKE_SECOND_FORK && !finished_simulation(philo->table))
		printf("%6ld %zu has taken the 2* fork [ %d ]\n", elapsed, philo->id,
			philo->first_fork->fork_id);
	else if (status == EATING && !finished_simulation(philo->table))
		printf("%6ld %zu is eating [ %ld ]\n", elapsed, philo->id,
			philo->meals_counter);
	else if (status == SLEEPING && !finished_simulation(philo->table))
		printf("%6ld %zu is sleeping\n", elapsed, philo->id);
	else if (status == THINKING && !finished_simulation(philo->table))
		printf("%6ld %zu is thinking\n", elapsed, philo->id);
	else if (status == DIED)
		printf("%6ld %zu died\n", elapsed, philo->id);
}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long int	elapsed;

	elapsed = gettime(MILLISECOND);
	if (philo->full)
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
			&& !finished_simulation(philo->table))
			printf("%-6ld %zu has taken a fork\n", elapsed, philo->id);
		else if (status == EATING && !finished_simulation(philo->table))
			printf("%-6ld %zu is eating\n", elapsed, philo->id);
		else if (status == SLEEPING && !finished_simulation(philo->table))
			printf("%-6ld %zu is sleeping\n", elapsed, philo->id);
		else if (status == THINKING && !finished_simulation(philo->table))
			printf("%-6ld %zu is thiking\n", elapsed, philo->id);
		else if (status == DIED)
			printf("%-6ld %zu died\n", elapsed, philo->id);
		pthread_mutex_unlock(&philo->table->write_mutex);
	}
}
