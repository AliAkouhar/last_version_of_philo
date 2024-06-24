/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:09:18 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/24 19:30:33 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status    get_status(t_philo *philo)
{
    t_status status;
    
    pthread_mutex_lock(&philo->set_status_lock);
    status = philo->status;
    pthread_mutex_unlock(&philo->set_status_lock);
    return (status);
}
void    set_status(t_philo *philo, t_status status)
{
    pthread_mutex_lock(&philo->get_status_lock);
    if (status == DIED)
        philo->data->death_flag = 0;
    philo->status = status;
    pthread_mutex_unlock(&philo->get_status_lock);
}

void    ft_printf(char *str, t_philo *philo)
{
    pthread_mutex_lock(&philo->write_lock);
    printf("%llu   %i %s", (get_time() - philo->start), philo->id, str);
    pthread_mutex_unlock(&philo->write_lock);
}