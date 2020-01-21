/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:50:26 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/21 14:10:48 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	get_texture_north(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[0] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->north[1], &iw, &ih);
	e->textureD[0] = mlx_get_data_addr(
		e->texture[0],
		&e->textureS[0].bpp,
		&e->textureS[0].sl,
		&e->textureS[0].endian);
}

void	get_texture_south(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[1] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->south[1], &iw, &ih);
	e->textureD[1] = mlx_get_data_addr(
		e->texture[1],
		&e->textureS[1].bpp,
		&e->textureS[1].sl,
		&e->textureS[1].endian);
}

void	get_texture_east(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[2] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->east[1], &iw, &ih);
	e->textureD[2] = mlx_get_data_addr(
		e->texture[2],
		&e->textureS[2].bpp,
		&e->textureS[2].sl,
		&e->textureS[2].endian);
}

void	get_texture_west(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[3] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->west[1], &iw, &ih);
	e->textureD[3] = mlx_get_data_addr(
		e->texture[3],
		&e->textureS[3].bpp,
		&e->textureS[3].sl,
		&e->textureS[3].endian);
}

void	get_texture_sprite(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[4] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->sprite[1], &iw, &ih);
	e->textureD[4] = mlx_get_data_addr(
		e->texture[4],
		&e->textureS[4].bpp,
		&e->textureS[4].sl,
		&e->textureS[4].endian);
}
