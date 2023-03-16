/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/16 01:37:25 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>

# include <stdio.h>// 				printf
# include <string.h>//				memset
# include <stdlib.h>// 				uint8_t
# include <sys/time.h>// 			gettimeofday
# include <pthread.h>//				thread & mutex

// Console Log && Philo State
enum e_philo_state {
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	OTHER
};
// Get Toolkit
enum e_thread_state {
	INIT,
	FREE,
	JOIN,
	GET
};
// Error Messages
enum e_errors {
	ARGS,
	THREAD
};
// Bool
typedef enum _bool {false, true}	t_bool;
// Args
typedef struct _args {
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_count;
}	t_args;
typedef struct _mutex {
	t_bool test;
	t_bool test2;
}	t_mutex;
// Main Struct of each Thread
typedef struct _fork {
	int				thread_number;
	long long int	timer;
	uint8_t			state;
	t_mutex 		*fork_one;
	t_mutex 		*fork_two;
}	t_fork;

// The Actual Function passed in all thread
void	*nothing(void* data);
// Hold all the Thread
pthread_t	**get_thread(uint8_t mode);
// Hold all the Args
t_args		*get_args(void);
// Hold all the Forks
t_mutex		*get_fork(uint8_t mode, int num);
// Give the Correct fork to the Threads
void		give_fork(t_fork *t, int threadNum);
// Argument Parser
t_bool		arg_parser(int argv, char **argc);
// Console Log
void		consolelog(uint8_t mode, int nbr);
// Error Msg
int			errormsg(uint8_t mode);
#endif
