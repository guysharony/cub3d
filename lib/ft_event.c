/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:51:39 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/07 08:13:12 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_event(t_env e, void *p)
{
	mlx_key_hook(e.win, ft_key, p);
}

int		ft_key(int key, void *p)
{
	(void)p;
	if (key == 123)
		printf("Left\n");
	else if (key == 124)
		printf("Right\n");
	else if (key == 125)
		printf("Down\n");
	else if (key == 126)
		printf("Up\n");
	else if (key == 53)
		exit(0);
	return (0);
}
