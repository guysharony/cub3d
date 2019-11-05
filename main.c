/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:55:26 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 11:48:11 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_key(int key, void *p)
{
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

int		main(void)
{
	if ((mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((win = mlx_new_window(mlx, W, H, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	printf("\n___ Coloring map ___\n");
	ft_fill(win, W, H, 750);
	ft_text(win, W/2, H/2, 0, "Hello World");
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
