/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:54:46 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:54:47 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	int		a;

	a = 0;
	while (str[a])
	{
		ft_putchar_fd(fd, str[a]);
		a++;
	}
}
