/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadforkmutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:49:53 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/16 01:23:41 by dpotvin          ###   ########.fr       */
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
		if (!t)
			return (0);
		while (i < get_args()->nbr_of_philo)
			memset(&t[i++], 0, sizeof(t_mutex));
		init = true;
	}
	if (mode == GET)
	{
		if (num <= get_args()->nbr_of_philo)
			return (&t[num]);
		else {
			printf("Trying to reach something out of bound - This should never happens\n - Get_Fork");
			return (0);
		}
	}
	else if (mode == FREE)
	{
		if (t)
			free(t);
	}
	return (t);
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
		if (!t || !arr)
			return (0);
		i = -1;
		while (++i < get_args()->nbr_of_philo)
		{
			arr[i] = i;
			if (pthread_create(&t[i], 0, &nothing, &arr[i]))
				return (0);
		}
		init = true;
	}
	if (mode == JOIN)
	{
		i = 0;
		while (i < get_args()->nbr_of_philo) {
			if (pthread_join(t[i++], NULL))
				return (0);
		}
	}
	else if (mode == FREE)
	{
		if (t)
			free(t);
		if (arr)
			free(arr);
	}
	return (&t);
}
