#include "philo.h"

static void	*printf_thread(void *arg)
{
	char	*s;

	s = (char *)arg;
	printf("%s\n", s);
	return ((void *)strlen(s));
}

int	main(void)
{
	pthread_t	t1;
	void		*res;
	int			i;

	i = pthread_create(&t1, NULL, printf_thread, "Hello this is thread.");
	if (i != 0)
		exit(EXIT_FAILURE);
	printf("Message from main().\n");
	i = pthread_join(t1, &res);
	if (i != 0)
		exit(EXIT_FAILURE);
	printf("Thread returned %ld\n", (long)res);
	return (EXIT_SUCCESS);
}
