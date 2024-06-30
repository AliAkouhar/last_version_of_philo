/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:10:56 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/30 11:21:30 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
    if (philo->id % 2 == 0)
        ft_usleep((philo->data->t_eat - 20));
    while (get_value(philo->data) && get_status(philo) != DIED)
    {
        if (get_status(philo) == DIED)
            break ;
        if (ft_eating(philo))
            break ;
        if (get_status(philo) == DIED)
            break ;
        if (ft_sleeping(philo))
            break ;
        if (get_status(philo) == DIED)
            break ;
        if (ft_thinking(philo))
            break ;
    }
    return (NULL);
}
