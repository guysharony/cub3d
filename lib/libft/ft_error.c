/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:48:20 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 11:00:56 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_error(char *str, char *param)
{
	ft_putstr("Error\n");
	if (param != NULL)
	{
		ft_putstr("[");
		ft_putstr(param);
		ft_putstr("]: ");
	}
	ft_putstr(str);
	ft_putstr("\n");
	return (1);
}

int		ft_error_line(char *str, char *param, int line)
{
	ft_putstr("Error\n");
	if (param != NULL)
	{
		ft_putstr("[");
		ft_putstr(param);
		ft_putstr("]: ");
	}
	ft_putstr(str);
	ft_putstr(" on ");
	if (ft_strcmp(param, "MAP") == 0)
		ft_putstr("map ");
	ft_putstr("line ");
	ft_putnbr(line);
	ft_putstr("\n");
	return (1);
}

int		ft_error_param(char *command, int nb)
{
	ft_putstr("Error\n");
	ft_putstr("[");
	ft_putstr(command);
	ft_putstr("]: ");
	ft_putnbr(nb);
	if (nb == 1)
		ft_putstr(" parameter is expected!");
	else
		ft_putstr(" parameters are expected!");
	ft_putstr("\n");
	return (1);
}

int		ft_error_redefined(int command)
{
	ft_putstr("Error\n");
	if (command == 0)
		ft_putstr("Resolution is defined few times in the file!");
	if (command == 1)
		ft_putstr("Wall's north texture is defined few times in the file!");
	if (command == 2)
		ft_putstr("Wall's south texture is defined few times in the file!");
	if (command == 3)
		ft_putstr("Wall's west texture is defined few times in the file!");
	if (command == 4)
		ft_putstr("Wall's east texture is defined few times in the file!");
	if (command == 5)
		ft_putstr("Sprite's texture is defined few times in the file!");
	if (command == 6)
		ft_putstr("Floor's color is defined few times in the file!");
	if (command == 7)
		ft_putstr("Ceiling's color is defined few times in the file!");
	ft_putstr("\n");
	return (-1);
}
