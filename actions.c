/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:05:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/24 19:34:34 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    take_a_fork(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    ft_printf("is taking a left fork\n", philo);
    if (philo->data->n_philo == 1)
    {
        usleep(philo->data->t_die);
        set_status(philo, DIED);
        philo->data->death_flag = 0; //is death
        pthread_mutex_unlock(philo->left_fork);
        return (1);
    }
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_lock(philo->right_fork);
    ft_printf("taking a right fork", philo);
    pthread_mutex_unlock(philo->right_fork);
    return (0);
}

int ft_eating(t_philo *philo)
{
    if (take_a_fork(philo))
        return (1);
    pthread_mutex_lock(&philo->eat_lock);
    set_status(philo, EATING);
    ft_printf("is eating\n", philo);
    if (philo->data->num_meals != -1)
        philo->meals_counter++;
    usleep(philo->data->t_eat);
    philo->expected_time = get_time() + philo->data->t_die;
    pthread_mutex_unlock(&philo->eat_lock);
    return (0);
}

void ft_sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->sleep_lock);
    set_status(philo, SLEEPING);
    ft_printf("is sleeping\n", philo);
    usleep(philo->data->t_sleep);
    pthread_mutex_unlock(&philo->sleep_lock);
}

void    ft_thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->think_lock);
    set_status(philo, THINKING);
    ft_printf("is thinking\n", philo);
    pthread_mutex_unlock(&philo->think_lock);
}
