/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:03:58 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/18 04:06:36 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// Init the list of mutexes
static t_bool init_mutexes(pthread_mutex_t **t, t_bool **b, t_bool *swtch)
{
		int	i;
		
		i = 0;
		*t = malloc(get_args()->nbr_of_philo * sizeof(pthread_mutex_t));
		*b = malloc(get_args()->nbr_of_philo * sizeof(t_bool));
		if (!(*t) || !(*b))
			return (false);
		while (i < get_args()->nbr_of_philo)
		{
			if (pthread_mutex_init(&(*t)[i++], 0))
				return (false);
		}
		memset(*b, 0 , get_args()->nbr_of_philo * sizeof(t_bool));
		*swtch = true;
		return (true);
}	
// Check if both fork are free. If so - Return true
static t_bool	is_forkpair_free(int fork_one, pthread_mutex_t **t, t_bool **b)
{
		int	fork_two;
		t_bool ret;
		
		if (fork_one == get_args()->nbr_of_philo - 1)
			fork_two = 0;
		else
			fork_two = fork_one + 1;

		ret = false;
		pthread_mutex_lock(&(*t)[fork_one]);
		pthread_mutex_lock(&(*t)[fork_two]);
		if (!(*b)[fork_one] && !(*b)[fork_two])
		{
				(*b)[fork_one] = true;
				(*b)[fork_two] = true;
				ret = true;
		}
		pthread_mutex_unlock(&(*t)[fork_one]);
		pthread_mutex_unlock(&(*t)[fork_two]);
		return ret;
}
// Release both Fork
static void	free_forkpair(int fork_one, pthread_mutex_t **t, t_bool **b)
{
	int fork_two;
	
	if (fork_one == get_args()->nbr_of_philo - 1)
			fork_two = 0;
		else
			fork_two = fork_one + 1;
			
		pthread_mutex_lock(&(*t)[fork_one]);
		pthread_mutex_lock(&(*t)[fork_two]);
		(*b)[fork_one] = false;
		(*b)[fork_two] = false;
		pthread_mutex_unlock(&(*t)[fork_one]);
		pthread_mutex_unlock(&(*t)[fork_two]);
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
		free(t);
	}
	if ((*b)) 
		free((*b));	
}
// Main Fork Function
t_bool		get_fork(uint8_t mode, int num)
{
	static t_bool			init;
	static pthread_mutex_t	*t;
	static t_bool			*list;

	if (!init)
		init_mutexes(&t, &list, &init);
	if (mode == GET)
		return (is_forkpair_free(num, &t, &list));
	else if (mode == SET)
		free_forkpair(num, &t, &list);
	else if (mode == FREE)
		free_all(&t, &list);
	return (true);
}
