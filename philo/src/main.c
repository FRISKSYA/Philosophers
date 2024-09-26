/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfukuhar <kfukuhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:53:23 by kfukuhar          #+#    #+#             */
/*   Updated: 2024/09/26 18:47:00 by kfukuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	if (init_data(&table, argv) == EXIT_FAILURE)
	{
		cleanup(table);
		print_err("malloc");
		return (EXIT_FAILURE);
	}
	eat_dinner(table);
	cleanup(table);
	return (EXIT_SUCCESS);
}
