/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 16:48:52 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: dev
static void	init_data(t_table **table)
{
	if (table)
		return ;
	return ;
}

// TODO: dev
static void	eat_dinner(t_table *table)
{
	if (table)
		return ;
	return ;
}

// TODO: dev
static void	cleanup(t_table *table)
{
	if (table)
		return ;
	return ;
}

int	main(int ac, char **argv)
{
	t_table	*table;

	if (!validate_input(ac, argv))
		return (EXIT_FAILURE);
	init_data(&table);
	eat_dinner(table);
	cleanup(table);
	return (EXIT_SUCCESS);
}
