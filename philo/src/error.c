/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:39:59 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 16:47:37 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	print_err(const char *msg)
{
	if (msg == NULL)
		return (true);
	printf("Error: %s\n", msg);
	return (false);
}
