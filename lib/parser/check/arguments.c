/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 09:36:16 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/16 09:48:56 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int		checkargnum(char **arg, int nb)
{
	if (ft_lstlength(arg) != nb)
	{
		ft_error_param(arg[0], nb);
		return (-1);
	}
	return (1);
}
