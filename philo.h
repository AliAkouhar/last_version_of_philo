/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:46:41 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/25 18:29:30 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "utils/utils.h"

typedef enum e_status{
    EATING,
    SLEEPING,
    THINKING,
    DIED,
    NTHG   
}   t_status;

typedef struct s_philo{
    pthread_t th;
    pthread_t           monitore;
    int     id;
    int     meals_counter;
    int     eat_flag; //1 is eathimg/ 2 is sleeping/ 3 is thinking/ 4 is dieng
    unsigned long long      start;
    unsigned long long      last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t eat_lock;
    pthread_mutex_t sleep_lock;
    pthread_mutex_t think_lock;
    pthread_mutex_t time_lock;
    pthread_mutex_t time;
    pthread_mutex_t message;
    pthread_mutex_t set_status_lock;
    pthread_mutex_t get_status_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t check_lock;
    struct s_data  *data;
    t_status    status;

}   t_philo;

typedef struct s_data{
    t_philo             *philo;
    pthread_mutex_t     meal_lock;
    pthread_mutex_t     *forks;
    pthread_mutex_t     death_lock;
    pthread_mutex_t     finish_lock;
    unsigned long long                t_eat;
    unsigned long long                t_die;
    unsigned long long                t_sleep;
    int                 death_flag;
    int                 n_philo;
    int                 num_meals;
    int                 *arr_time;
    int                 meal_finish;
    pthread_t           meals_monitore;
    pthread_t           death_monitore;
}   t_data;

int     parcing(int ac, char **av);
void    *routine(void *d);
int     ft_init(char **av, t_data *data);
void    *death_func(void *p);
int     ft_create_forks(t_data *data);
int     ft_create_philos(t_data *data);
void    *death_func(void *p);
void    go_to_eat(t_philo *philo);
void    ft_printf(char *str, t_philo *philo);
void    ft_init_philo(t_data *data);
void    *check_death(void *p);
void    *check_meals(void *p);
int    take_a_fork(t_philo *philo);
int is_death(t_philo *philo);
t_status    get_status(t_philo *philo);
void    ft_thinking(t_philo *philo);
void ft_sleeping(t_philo *philo);
int ft_eating(t_philo *philo);
int    take_a_fork(t_philo *philo);
void    ft_printf(char *str, t_philo *philo);
void    set_status(t_philo *philo, t_status status);


#endif