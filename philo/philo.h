/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/14 02:45:42 by dpotvin          ###   ########.fr       */
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

// Console Log
enum e_philo_state {
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	OTHER
};
// Thread State
enum e_thread_state {
	INIT,
	FREE,
	JOIN,
	GET
};
// Error Log
enum e_errors {
	ARGS
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
	t_bool lock;
	t_bool fork;
}	t_mutex;

typedef struct _fork {
	t_mutex *fork_one;
	t_mutex *fork_two;
}	t_fork;

// Hold all the Thread
pthread_t	**get_thread(uint8_t mode);
// Hold all the Args
t_args		*get_args(void);
// Hold all the Forks
t_mutex		*get_fork(uint8_t mode, int num);
// Argument Parser
t_bool		arg_parser(int argv, char **argc);
// Console Log
void		consolelog(uint8_t mode, int nbr, char *str);
// Error Msg & Return
int			errormsg(uint8_t mode);
// Get the Mutex Lock
pthread_mutex_t *get_mutex(uint8_t mode);
// Give the Correct fork to the Threads
void	give_fork(t_fork *t, int threadNum);

// The Actual Function passed in all thread
void	*nothing(void* data);


#endif
