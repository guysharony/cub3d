/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:59:41 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:59:42 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*getmap_line(char *line, int length)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	str = malloc(sizeof(char *) * (length + 1));
	while (line[a])
	{
		if (line[a] != ' ')
		{
			str[b] = line[a];
			b++;
		}
		a++;
	}
	str[b] = '\0';
	return (str);
}
