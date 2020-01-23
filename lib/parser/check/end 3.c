/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:30:13 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/18 13:32:14 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkend(int file)
{
	char	*line;

	while (get_next_line(file, &line))
	{
		if (ft_strlen(line) > 0)
		{
			ft_error("Please remove useless lines after map!", NULL);
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	return (1);
}
