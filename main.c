/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:53:46 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/30 09:55:40 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data  data;
    
    if (parcing(ac, av))
        return (1);
    if (ft_init(av, &data))
        return (1);
    // ft_free_all(&data);
    return (0);
}

//daba khasek tmchi tkml routine t3tih forks w ymchi yakel matnsatch ttl 3la l code l9dim cuz ghatfkr fin drti forks imta kayhzhom