#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
//dev
#include <string.h>

typedef struct s_test
{
	int				sum;
	char			*str;
	pthread_mutex_t	mutex;
}				t_test;

#endif
