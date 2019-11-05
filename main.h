/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 08:45:43 by gsharony          #+#    #+#             */
/*   Updated: 2019/11/05 12:08:02 by gsharony         ###   ########.fr       */
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

void	ft_fill(void *win, int w, int h, int color);
void	ft_text(void *win, int w, int h, int color, char *str);
void	ft_event(void *win, void *p);
int		ft_key(int key, void *p);
int		ft_color(int r, int g, int b);

#endif
