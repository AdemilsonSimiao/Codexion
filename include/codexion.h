/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc2 <pc2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:42:44 by pc2               #+#    #+#             */
/*   Updated: 2026/10/30 16:57:41 by pc2              ###   ########.fr       */
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

typedef struct s_request
{
	int		coder_id;
	long	key;
}	t_request;

typedef struct s_heap
{
	t_request	*items;
	int			size;
	int			capacity;
}	t_heap;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	int				dongle_data;
	long			dongle_cooldown;
	t_heap			queue;
	long			next_ticket;
}	t_dongle;

typedef struct s_data	t_data;
typedef struct s_coder	t_coder;

struct s_coder
{
	int			id;
	pthread_t	thread;
	int			compile_count;
	long		compile_start;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_config	*config;
	t_data		*data;
};

struct s_data
{
	t_config		config;
	t_dongle		*dongles;
	t_coder			*coders;
	pthread_t		monitor;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	state_mutex;
	int				stop;
	long			start_time;

};

int			negative_validation(int validate);
int			ft_isdigit(char c);
int			number_validation(char *str);
int			fifo_edf_validation(char *str);
int			args_validation(int argc, char **argv);
void		fill_config(t_config *config, char **argv);
long		get_time_ms(void);
void		smart_sleep(long ms);
void		log_state(t_data *data, int id, const char *msg);
int			init_dongles(t_data *data);
int			init_coders(t_data *data);
int			init_data(t_data *data, char **argv);
void		destroy_dongles(t_dongle *dongles, int count);
void		destroy_shared(t_data *data);
void		cleanup_all(t_data *data);
void		*coder_routine(void *arg);
void		simulation(t_data *data);
void		do_compile(t_coder *coder);
void		do_debug(t_coder *coder);
void		do_refactor(t_coder *coder);
void		take_dongle(t_coder *coder, t_dongle *dongle);
void		drop_dongle(t_coder *coder, t_dongle *dongle);
void		drop_dongles(t_coder *coder);
int			is_done(t_coder *coder);
int			is_burned_out(t_coder *coder);
int			all_done(t_data *data);
int			find_burned_out(t_data *data);
void		*monitor_routine(void *arg);
int			is_stopped(t_data *data);
int			heap_init(t_heap *heap, int capacity);
void		heap_destroy(t_heap *heap);
int			request_before(t_request *a, t_request *b);
int			heap_push(t_heap *heap, t_request request);
int			heap_pop(t_heap *heap, t_request *out);
t_request	*heap_peek(t_heap *heap);
int			take_dongles(t_coder *coder);
long		deadline_of(t_coder *coder);
void		request_dongle(t_coder *coder, t_dongle *dongle, long deadline);
int			dongle_ready(t_dongle *dongle);
int			blocked_by_neighbor(t_coder *coder, t_dongle *dongle);
int			is_free(t_dongle *dongle);
void		lock_pair(t_dongle *first, t_dongle *second);
void		unlock_pair(t_dongle *first, t_dongle *second);
int			try_take(t_coder *coder, t_dongle *first, t_dongle *second);
void		heap_remove(t_heap *heap, int coder_id);

#endif
