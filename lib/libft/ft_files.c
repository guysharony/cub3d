/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:49:53 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 08:29:01 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_filename(char *adress)
{
	char	*filename;

	filename = ft_strrchr(adress, '/');
	if (filename != NULL)
		return (filename + 1);
	return (adress);
}

char	*get_filetype(char *adress)
{
	char	*filename;
	char	*filetype;

	filename = get_filename(adress);
	filetype = ft_strchr(filename, '.');
	if (filetype != NULL)
		return (filetype + 1);
	return (NULL);
}

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
	ftype = get_filetype(filename);
	if (ftype == NULL)
	{
		ft_error("File is not in the correct format!", filename);
		return (-1);
	}
	if (ft_strcmp(ftype, type) != 0)
	{
		ft_error("File is not in the correct format!", filename);
		return (-1);
	}
	return (1);
}
