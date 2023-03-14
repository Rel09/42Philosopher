/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadforkmutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:49:53 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/14 02:37:01 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex		*get_fork(uint8_t mode, int num)
{
	static t_mutex	*t;
	static t_bool	init;
	int	i;
	
	if (!init)
	{
		i = 0;
		t = malloc(get_args()->nbr_of_philo * sizeof(t_mutex));
		while (i < get_args()->nbr_of_philo)
			memset(&t[i++], 0, sizeof(t_mutex));
		init = true;
	}
	if (mode == GET)
	{
		if (num <= get_args()->nbr_of_philo)
			return (&t[num]);
		else
			printf("Trying to reach something out of bound\n - Get_Fork");
	}
	else if (mode == FREE) {
		free(t);
	}
	return (0);
}

pthread_t	**get_thread(uint8_t mode) 
{
	static t_bool		init;
	static pthread_t	*t;
	static int			*arr;
	int					i;

	if (!init)
	{
		t = malloc(get_args()->nbr_of_philo * sizeof(pthread_t));
		arr = malloc(get_args()->nbr_of_philo * sizeof(int));
		i = -1;
		while (++i < get_args()->nbr_of_philo)
		{
			arr[i] = i;
			pthread_create(&t[i], 0, &nothing, &arr[i]);
		}
		init = true;
	}
	if (mode == JOIN)
	{
		i = 0;
		while (i < get_args()->nbr_of_philo)
			pthread_join(t[i++], NULL);
	}
	else if (mode == FREE) {
		free(t);
		free(arr);
	}
	return (&t);
}

pthread_mutex_t *get_mutex(uint8_t mode)
{
	static pthread_mutex_t T;
	static t_bool init;

	if (!init)
	{
		pthread_mutex_init(&T, 0);
		init = true;
	}
	if (mode == FREE)
		pthread_mutex_destroy(&T);

	return (&T);
}
