/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:45:43 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 11:20:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "mlx/mlx.h"
# define W 650
# define H 450

void	*mlx;
void	*win;

typedef struct		mouse_s
{
	int				x;
	int				y;
}					mouse_t;

#endif
