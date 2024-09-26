/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:52:20 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 12:21:21 by kfukuhar         ###   ########.fr       */
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
// dev
# include <string.h>

// validate args
# define MAX_PHILOSOPHERS 10000
# define MAX_TIME_IN_MS 1800000
# define MAX_MEALS 5000

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
	long long int		last_meal_time;
	t_fork				*l_fork;
	t_fork				*r_fork;
	pthread_t			thread_id;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	size_t				philo_nbr;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	int					nbr_limit_meals;
	long long int		start_simulation;
	bool				end_simulation;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

// main funcs
bool					validate_input(int argc, char **argv);
int						init_data(t_table **table, char **argv);
void					eat_dinner(t_table *table);
void					cleanup(t_table *table);
// utils
bool					print_err(const char *msg);
int						ft_isdigit(int i);
int						ft_atoi(const char *str);
bool					is_digit_array(char *str);
long long int			current_timestamp(void);

typedef struct s_test
{
	int					sum;
	char				*str;
	pthread_mutex_t		mutex;
}						t_test;

#endif
