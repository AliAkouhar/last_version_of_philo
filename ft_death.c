/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:43:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/27 17:23:33 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* int     check_all(t_data *data)
{
    while (1337)
    {
        if (data->death_flag == 0)
            return (1);
    }
    return (0);
} */

int is_death(t_philo *philo)
{
    pthread_mutex_lock(&philo->check_lock);
    if (get_status(philo) == DIED)
    {
        philo->data->death_flag = 0;
        pthread_mutex_unlock(&philo->check_lock);
        return (1);
    }
    else if (get_status(philo) != EATING && (get_time() - philo->last_meal >= philo->data->t_die))
    {
        //printf("%llu ------------ex %llu\n", get_time(), philo->expected_time - get_time());
        //printf("is maat\n");
        // printf("time to die %llu\n", get_time() - philo->last_meal);
        // printf("time to die %llu\n", philo->data->t_die);
        set_status(philo, DIED);
        philo->data->death_flag = 0;
        //go_kill_all(philo->data);
        pthread_mutex_unlock(&philo->check_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->check_lock);
    return (0);
}

void    go_kill_all(t_data *data)
{
    int i;

    i = -1;
    data->death_flag = 0;
    while (++i < data->n_philo)
        set_status(&data->philo[i], DIED);
}

void    *check_death(void *p)
{
    t_data  *data;
    int     i;

    data = (t_data *)p;
    i = 0;
    while (i < data->n_philo && data->n_philo != 1)
    {
        if (is_death(&data->philo[i]))
        {
            ft_printf("is died\n", &data->philo[i]);
            go_kill_all(data);
            data->death_flag = 0;
            break ;  
        }
        i++;
        if (i == data->n_philo)
            i = 0;
        usleep(1000);
    }    
    return (NULL);
}

void    *check_meals(void   *p)
{
    t_data  *data;
    int     i;
    int     count;
    
    data = (t_data *)p;
    i = 0;
    count = 0;
    while (i < data->n_philo)
    {
        if (data->philo[i].meals_counter >= (long)data->num_meals)
            count++;
        i++;
        if (count == data->n_philo)
        {
            printf("compliting meals\n");
            // go_kill_all(data);
            data->death_flag = 0;
            break ;
        }
        if (i == data->n_philo)
        {
            i = 0;
            count = 0;
        }
        usleep(1000);
    }
    return (NULL);
}