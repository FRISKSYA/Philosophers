/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:52:20 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 15:43:25 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork t_fork;
typedef struct s_table t_table;
typedef struct s_philo t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

typedef struct s_table
{
	long int		philo_nbr;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		nbr_limit_meals;
	long int		start_simulation;
	t_fork			*forks;
	t_philo			*philos;
}					t_table;

typedef struct s_philo
{
	int				id;
	long int		meals_counter;
	bool			full;
	long int		last_meal_time;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thread_id;
	t_table			*table;
}					t_philo;

// main funcs
bool    validate_input(int argc, char **argv);

//utils
bool    print_err(const char *msg);

// dev
# include <string.h>

typedef struct s_test
{
	int				sum;
	char			*str;
	pthread_mutex_t	mutex;
}					t_test;

#endif
