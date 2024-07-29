/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:48:27 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/27 09:54:30 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
# include <limits.h>


long	ft_atol(char *str);
unsigned long long get_time(void);
int    ft_usleep(size_t milliseconds);

#endif