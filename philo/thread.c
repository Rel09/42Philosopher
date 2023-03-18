/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:57:14 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/18 04:18:27 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Init Thread
static t_bool init_thread(pthread_t **t, int **arr, t_bool *init)
{
	int	i;
	
	*t = malloc(get_args()->nbr_of_philo * sizeof(pthread_t));
	*arr = malloc(get_args()->nbr_of_philo * sizeof(int));
	if (!(*t) || !(*arr))
		return (false);
	i = -1;
	while (++i < get_args()->nbr_of_philo)
	{
		(*arr)[i] = i;
		if (pthread_create(&(*t)[i], 0, &thread_main, &(*arr)[i]))
			return (false);
	}
	*init = true;
	return (true);
}
// Join Thread
static t_bool join_thread(pthread_t **t)
{
	int	i;
	i = 0;
	while (i < get_args()->nbr_of_philo) {
		if (pthread_join((*t)[i++], NULL))
			return (false);
	}
	return true;
}
// Free the Threads
static void free_thread(pthread_t **t, int **arr)
{
	if ((*t))
		free((*t));
	if ((*arr))
		free((*arr));
}
// Init, Join & Free the Threads
pthread_t	**get_thread(uint8_t mode) 
{
	static t_bool		init;
	static pthread_t	*t;
	static int			*arr;

	if (!init)
	{
		if (!init_thread(&t, &arr, &init))
			return (0);
	}
	if (mode == JOIN)
	{
		if (!join_thread(&t))
			return (0);
	}
	else if (mode == FREE)
		free_thread(&t, &arr);
	return (&t);
}
