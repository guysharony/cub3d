/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:45:33 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/26 19:09:29 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	clean(char **lst)
{
	int		a;

	a = 0;
	if (lst != NULL)
	{
		while (lst[a] != NULL)
		{
			free(lst[a]);
			lst[a] = NULL;
			a++;
		}
		free(lst);
	}
}
