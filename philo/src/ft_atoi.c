/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:35 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 16:47:50 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	return (
		c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' '
	);
}

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	is_mi;
	long	result;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
		is_mi = 1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	result = 0;
	while (ft_isdigit(str[index]) && str[index])
	{
		if (is_mi != 1 && result > (LONG_MAX - (str[index] - '0')) / 10)
			return ((int)LONG_MAX);
		else if (is_mi == 1 && - result < (LONG_MIN + (str[index] - '0')) / 10)
			return ((int)LONG_MIN);
		result = 10 * result + (str[index] - '0');
		index++;
	}
	if (is_mi == 1)
		return ((int)-1 * result);
	else
		return ((int)result);
}
