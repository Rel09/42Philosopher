/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 03:55:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/26 04:31:32 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int	get_timestamp()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	consolelog(uint8_t mode, int nbr, char *str)
{
	if (mode == FORK)
		printf("[%lli] %i has taken a fork\n", get_timestamp(), nbr);
	else if (mode == EATING)
		printf("[%lli] %i is eating\n", get_timestamp(), nbr);
	else if (mode == SLEEPING)
		printf("[%lli] %i is sleeping\n", get_timestamp(), nbr);
	else if (mode == THINKING)
		printf("[%lli] %i is thinking\n", get_timestamp(), nbr);
	else if (mode == DIED)
		printf("[%lli] %i died\n", get_timestamp(), nbr);
	else
		printf("[%lli] %s\n", get_timestamp(), str);
}

int		errormsg(uint8_t mode)
{
	if (mode == ARGS)
		printf("Error with Arguments\n");
	return (1);
}
