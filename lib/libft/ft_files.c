/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:49:53 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:52:28 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isftype(char *filename, char *type)
{
	char	*ftype;
	char	buffer[32];
	int		filedesc;

	filedesc = open(filename, O_RDONLY);
	if (read(filedesc, buffer, 0) < 0)
	{
		ft_error("File can't be found!", filename);
		return (-1);
	}
	ftype = ft_strrchr(filename, '.') + 1;
	if (ft_strcmp(ftype, type) != 0)
	{
		ft_error("File is not in the correct format!", filename);
		return (-1);
	}
	return (1);
}
