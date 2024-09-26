/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 12:46:06 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	validate_all_digits(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_digit_array(argv[i]))
		{
			printf("Error: Argument %d is not a valid integer.\n", i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	validate_range(int value, int min, int max, const char *err_msg)
{
	if (value < min || value > max)
	{
		printf("%s (valid range: %d - %d)\n", err_msg, min, max);
		return (false);
	}
	return (true);
}

static bool	validate_all_ranges(int argc, char **argv)
{
	int	value;
	int	i;

	value = atoi(argv[1]);
	if (!validate_range(value, 60, MAX_PHILOSOPHERS,
			"Invalid number of philosophers"))
		return (false);
	i = 2;
	while (i <= 4)
	{
		value = atoi(argv[i]);
		if (!validate_range(value, 60, MAX_TIME_IN_MS, "Invalid time setting"))
			return (false);
		i++;
	}
	if (argc == 6)
	{
		value = atoi(argv[5]);
		if (!validate_range(value, 60, MAX_MEALS, "Invalid number of meals"))
			return (false);
	}
	return (true);
}

bool	validate_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (print_err("argc must be 5 or 6"));
	if (!validate_all_digits(argc, argv))
		return (false);
	if (!validate_all_ranges(argc, argv))
		return (false);
	return (true);
}
