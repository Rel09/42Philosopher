/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/06 10:12:11 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>// 				printf
# include <string.h>//				memset
# include <stdlib.h>// 				uint8_t
# include <sys/time.h>// 			gettimeofday
# include <pthread.h>//				thread & mutex

// Console Log
enum philo_state {
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	OTHER
};
// Thread State
enum thread_state {
	NONE,
	INIT,
	FREE
};
// Error Log
enum errors {
	ARGS
};

typedef enum _bool {false, true} t_bool;//					bool

typedef struct _args {//									args
	int nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int eat_count;
}	t_args;

pthread_t	**get_thread(uint8_t mode);//						Function holding all Thread
t_args		*get_args(void);//									Get the Arguments
t_bool		arg_parser(int argv, char **argc);// 				Arguments Parser
void		consolelog(uint8_t mode, int nbr, char *str);// 	Console Log
int			errormsg(uint8_t mode);//							Error Logger & Return

#endif
