/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/02/28 15:26:22 by dpotvin          ###   ########.fr       */
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
# define FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# define OTHER 5
// Error Log
# define ARGS 0
// Thread
# define NONE 0
# define INIT 1
# define FREE 6

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
