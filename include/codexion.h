/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:42:44 by pc2               #+#    #+#             */
/*   Updated: 2026/10/28 15:51:50 by pc2              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_config
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;

}	t_config;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				dongle_data;
	long			dongle_cooldown;
}	t_dongle;

typedef struct s_coder
{
	int			id;
	pthread_t	thread;
	int			compile_count;
	long		compile_start;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_config	*config;

}	t_coder;

typedef struct s_data
{
	t_config		config;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_t		monitor;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	stop_mutex;
	int				stop;
	long			start_time;

}	t_data;

int		negative_validation(int validate);
int		ft_isdigit(char c);
int		number_validation(char *str);
int		fifo_edf_validation(char *str);
int		args_validation(int argc, char **argv);
void	fill_config(t_config *config, char **argv);
long	get_time_ms(void);
void	smart_sleep(long ms);
void	log_state(t_data *data, int id, const char *msg);
int		init_dongles(t_data *data);
int		init_coders(t_data *data);
int		init_data(t_data *data, char **argv);
void	destroy_dongles(t_dongle *dongles, int count);

#endif
