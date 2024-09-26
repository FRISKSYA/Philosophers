/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:11:16 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 18:41:39 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	gettime(t_time_code time_code)
{
	struct timeval	te;

	if (gettimeofday(&te, NULL))
	{
		print_err("gettimeofday");
		return (-1);
	}
	if (SECOND == time_code)
		return (te.tv_sec + (te.tv_usec / 1e6));
	else if (MILLISECOND == time_code)
		return (te.tv_sec * 1e3 + te.tv_usec / 1e3);
	else if (MICROSECOND == time_code)
		return ((te.tv_sec * 1e6) + te.tv_usec);
	else
	{
		print_err("Wrong time_code");
		return (-1);
	}
}
