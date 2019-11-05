/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 12:17:11 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(void)
{
	if ((mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((win = mlx_new_window(mlx, W, H, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	printf("\n___ Coloring map ___\n");
	ft_fill(win, W, H, ft_color(255, 0, 0));
	ft_text(win, W/2, H/2, 0, "Hello World");
	ft_event(win, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
