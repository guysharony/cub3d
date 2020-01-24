/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:50:26 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/24 07:57:02 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	get_texture_north(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[0] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->north[1], &iw, &ih);
	e->textured[0] = mlx_get_data_addr(
		e->texture[0],
		&e->textures[0].bpp,
		&e->textures[0].sl,
		&e->textures[0].endian);
	e->textures[0].size.x = iw;
	e->textures[0].size.y = ih;
}

void	get_texture_south(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[1] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->south[1], &iw, &ih);
	e->textured[1] = mlx_get_data_addr(
		e->texture[1],
		&e->textures[1].bpp,
		&e->textures[1].sl,
		&e->textures[1].endian);
	e->textures[1].size.x = iw;
	e->textures[1].size.y = ih;
}

void	get_texture_east(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[2] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->east[1], &iw, &ih);
	e->textured[2] = mlx_get_data_addr(
		e->texture[2],
		&e->textures[2].bpp,
		&e->textures[2].sl,
		&e->textures[2].endian);
	e->textures[2].size.x = iw;
	e->textures[2].size.y = ih;
}

void	get_texture_west(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[3] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->west[1], &iw, &ih);
	e->textured[3] = mlx_get_data_addr(
		e->texture[3],
		&e->textures[3].bpp,
		&e->textures[3].sl,
		&e->textures[3].endian);
	e->textures[3].size.x = iw;
	e->textures[3].size.y = ih;
}

void	get_texture_sprite(t_env *e)
{
	int		iw;
	int		ih;

	e->texture[4] = mlx_xpm_file_to_image(e->mlx,
			e->game->wall->sprite[1], &iw, &ih);
	e->textured[4] = mlx_get_data_addr(
		e->texture[4],
		&e->textures[4].bpp,
		&e->textures[4].sl,
		&e->textures[4].endian);
	e->textures[4].size.x = iw;
	e->textures[4].size.y = ih;
}
