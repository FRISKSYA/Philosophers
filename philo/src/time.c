#include "philo.h"

long long int	current_timestamp(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000LL + te.tv_usec / 1000);
}