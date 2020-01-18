/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:55:20 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/17 11:40:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*joinlst(char **data)
{
	int		a;
	char	*tmp;
	char	*content;

	a = 1;
	content = ft_strnew();
	while (data[a] != NULL)
	{
		tmp = content;
		content = ft_strjoin(tmp, data[a]);
		free(tmp);
		a++;
	}
	return (content);
}

int				ft_lstlength(char **lst)
{
	int		a;

	a = 0;
	while (lst[a] != NULL)
		a++;
	return (a);
}

char			**parsecolor(char *data)
{
	char	**color;

	color = ft_split(data, ',');
	return (color);
}
