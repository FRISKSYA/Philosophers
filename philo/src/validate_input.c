/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:34:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 16:47:24 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	validate_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		return (print_err("argc must be 5 or 6"));
	}
	if (argv)
		return (print_err("debug"));
	return (true);
}
