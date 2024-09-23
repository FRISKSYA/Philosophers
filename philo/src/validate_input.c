/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 17:01:03 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_input(int argc, char **argv)
{
	size_t	i;

	if (argc < 5 || argc > 6)
	{
		return (print_err("argc must be 5 or 6"));
	}
	i = 1;
	if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > MAX_PHILOSOPHERS)
		return (print_err("too much philos"));
	i++;
	while (i < 4)
	{
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > MAX_TIME_IN_MS)
			return (print_err("invalid time setting"));
		i++;
	}
	if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > MAX_MEALS)
		return (print_err("invalid meals."));
	return (true);
}
