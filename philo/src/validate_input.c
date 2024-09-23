/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 17:13:28 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	validate_range(int value, int min, int max, const char *err_msg)
{
	if (value < min || value > max)
	{
		printf("%s (valid range: %d - %d)\n", err_msg, min, max);
		return (false);
	}
	return (true);
}

bool	validate_input(int argc, char **argv)
{
	int		value;
	size_t	i;

	if (argc < 5 || argc > 6)
		return (print_err("argc must be 5 or 6"));
	i = 1;
	value = 0;
	value = ft_atoi(argv[i++]);
	if (!validate_range(value, 1, MAX_PHILOSOPHERS,
			"Invalid number of philosophers"))
		return (false);
	while (i <= 4)
	{
		value = ft_atoi(argv[i++]);
		if (!validate_range(value, 1, MAX_TIME_IN_MS, "Invalid time setting"))
			return (false);
	}
	if (argc == 6)
	{
		value = ft_atoi(argv[5]);
		if (!validate_range(value, 1, MAX_MEALS, "Invalid number of meals"))
			return (false);
	}
	return (true);
}
