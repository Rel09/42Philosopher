/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:03:58 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/29 21:50:46 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Init the list of mutexes
static t_bool	init_mutexes(pthread_mutex_t **t, t_bool **b, t_bool *swtch)
{
	int	i;

	i = 0;
	(*t) = malloc(get_args()->nbr_of_philo * sizeof(pthread_mutex_t));
	(*b) = malloc(get_args()->nbr_of_philo * sizeof(t_bool));
	if (!(*t) || !(*b))
		return (false);
	while (i < get_args()->nbr_of_philo)
	{
		if (pthread_mutex_init(&(*t)[i++], 0))
			return (false);
	}
	memset((*b), 0, get_args()->nbr_of_philo * sizeof(t_bool));
	*swtch = true;
	return (true);
}

// Check if both fork are free. If so - Return true
static t_bool	is_forkpair_free(int f_one, int f_two, pthread_mutex_t **t,
		t_bool **b)
{
	t_bool	ret;

	pthread_mutex_lock(&(*t)[f_one]);
	pthread_mutex_lock(&(*t)[f_two]);
	ret = false;
	if (!(*b)[f_one] && !(*b)[f_two])
	{
		(*b)[f_one] = true;
		(*b)[f_two] = true;
		ret = true;
	}
	pthread_mutex_unlock(&(*t)[f_one]);
	pthread_mutex_unlock(&(*t)[f_two]);
	return (ret);
}

// Release both Fork
static void	free_forkpair(int f_one, int f_two, pthread_mutex_t **t, t_bool **b)
{
	pthread_mutex_lock(&(*t)[f_one]);
	pthread_mutex_lock(&(*t)[f_two]);
	(*b)[f_one] = false;
	(*b)[f_two] = false;
	pthread_mutex_unlock(&(*t)[f_one]);
	pthread_mutex_unlock(&(*t)[f_two]);
}

// Free the Forks
static void	free_all(pthread_mutex_t **t, t_bool **b)
{
	int	i;

	if ((*t))
	{
		i = 0;
		while (i < get_args()->nbr_of_philo)
			pthread_mutex_destroy(&(*t)[i++]);
		free(*t);
	}
	if ((*b))
		free((*b));
}

// Main Fork Function
t_bool	get_fork(uint8_t mode, int f_one, int f_two)
{
	static t_bool			init;
	static pthread_mutex_t	*t;
	static t_bool			*list;

	if (!init)
		return (init_mutexes(&t, &list, &init));
	if (mode == GET)
		return (is_forkpair_free(f_one, f_two, &t, &list));
	else if (mode == SET)
		free_forkpair(f_one, f_two, &t, &list);
	else if (mode == FREE)
		free_all(&t, &list);
	return (true);
}
