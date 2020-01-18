/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:56:09 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/15 12:56:10 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmcpy(char *str)
{
	char	*dst;

	dst = ft_calloc(sizeof(str), ft_strlen(str) + 1);
	ft_strcpy(dst, str);
	return (dst);
}
