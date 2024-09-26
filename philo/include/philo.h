/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:52:20 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 18:24:03 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// validate args
# define MAX_PHILOSOPHERS 10000
# define MAX_TIME_IN_MS 1800000
# define MAX_MEALS 5000

// for gettime
typedef enum s_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time_code;

// for write_status
typedef enum s_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philo_status;

# define DEBUG_MODE 0

typedef struct s_fork	t_fork;
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	size_t				id;
	size_t				meals_counter;
	bool				full;
	long int			last_meal_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	pthread_mutex_t		philo_mutex;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	size_t				philo_nbr;
	long int			time_to_die;
	long int			time_to_eat;
	long int			time_to_sleep;
	int					nbr_limit_meals;
	long int			start_simulation;
	bool				end_simulation;
	bool				ready_all_threads;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		write_mutex;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

// main funcs
bool					validate_input(int argc, char **argv);
int						init_data(t_table **table, char **argv);
void					eat_dinner(t_table *table);
void					cleanup(t_table *table);

// pthread
void					*simulate_dinner(void *data);

// utils
bool					print_err(const char *msg);
void					precise_usleep(long int usec, t_table *table);
int						ft_isdigit(int i);
int						ft_atoi(const char *str);
bool					is_digit_array(char *str);
long int				gettime(t_time_code time_code);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_long(pthread_mutex_t *mutex, long int *dest,
							long int value);
long int				get_long(pthread_mutex_t *mutex, long int *value);
bool					finished_simulation(t_table *table);
void					write_status(t_philo_status status, t_philo *philo,
							bool debug);

#endif
