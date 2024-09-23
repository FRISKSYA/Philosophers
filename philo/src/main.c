#include "philo.h"

static void *sum_thread(void *arg)
{
	t_test	*box;

	box = (t_test *)arg;
	box->sum++;
	printf("sum : [%d]\n", box->sum);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	*t_array;
	t_test		*test;
	int			index;
	int			i;
	int			th_size;

	if (argc == 1)
		th_size = 3;
	else if (argc == 2)
	{
		th_size = atoi(argv[1]);
		if (th_size <= 0)
		{
			dprintf(STDERR_FILENO, "th_size must be greater than 0.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "argc need less than 2.\n");
		exit(EXIT_FAILURE);
	}
	index = 0;
	t_array = (pthread_t *)malloc(th_size * sizeof(pthread_t));
	test = (t_test *)malloc(sizeof(t_test));
	test->sum = 0;
	test->str = NULL;
	printf("Message from main().\n");
	while (index < th_size)
	{
		i = pthread_create(&(t_array[index]), NULL, sum_thread, test);
		if (i != 0)
			exit(EXIT_FAILURE);
		index++;
	}
	index = 0;
	while (index < th_size)
	{
		i = pthread_join(t_array[index], NULL);
		if (i != 0)
			exit(EXIT_FAILURE);
		index++;
	}
	printf("Threads done.  sum is [%d]\n", test->sum);
	return (EXIT_SUCCESS);
}
