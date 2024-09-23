/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/23 17:54:46 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		free(table);
	return ;
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	if (init_data(&table, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	eat_dinner(table);
	cleanup(table);
	return (EXIT_SUCCESS);
}
