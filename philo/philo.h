/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:30:44 by dpotvin           #+#    #+#             */
/*   Updated: 2023/03/25 06:28:17 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>//				malloc

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
	DIED
};
// Get Toolkit
enum e_thread_state {
	INIT,
	FREE,
	JOIN,
	GET,
	SET
};
// Console
enum e_console {
	KILL_MUTEX = 10
};
// Error Messages
enum e_errors {
	ARGS,
	THREAD
};
// Bool
typedef enum _bool {
	false, 
	true
}	t_bool;
// Args
typedef struct _args {
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_count;
}	t_args;
// Main Struct of each Thread
typedef struct _fork {
	int						thread_number;
	int						print_number;
	
	int						fork_one_id;
	int						fork_two_id;

	int						eat_count;

	long long int			timer;
	long long int			sub_timer;
	long long int			eat_timer;
	
	uint8_t					state;
}	t_fork;

// The Actual Function passed in all thread
void			*thread_main(void* data);
// Hold all the Thread
pthread_t		**get_thread(uint8_t mode);
// Hold all the Args
t_args			*get_args(void);
// Thread that Listen to Philo's death
t_bool			death_watcher(uint8_t mode);
// Hold all the Forks ( Mutexes )
t_bool			get_fork(uint8_t mode, int f_one,int f_two);
// Argument Parser
t_bool			arg_parser(int argv, char **argc);
// Console Log
void			consolelog(uint8_t mode, int nbr, long long int timestamp);
// Timestamp
long long int	get_timestamp(void);
// Error Msg
int				errormsg(uint8_t mode);
#endif
