/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:45 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 10:05:13 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int i)
{
	return (i >= '0' && i <= '9');
}

bool	is_digit_array(char *str)
{
	while (str && *str)
	{
		if (ft_isdigit(*str) == 0)
			return (false);
		str++;
	}
	return (true);
}

// int	main(void)
// {
// 	if (is_digit_array("01234"))
// 		printf("It's good!.\n");
// 	else
// 		printf("Error.\n");
// 	return (0);
// }