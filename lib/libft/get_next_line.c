/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:25:51 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/06 11:25:45 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_linelen(char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\n' && str[a])
		a++;
	return (a);
}

char		*get_line(char *content)
{
	if (ft_strchr(content, '\n'))
	{
		ft_strcpy(content, ft_strchr(content, '\n') + 1);
		return (content);
	}
	return (NULL);
}

char		*ft_strnew(void)
{
	char	*a;

	if (!(a = (char *)malloc(sizeof(char) * (1))))
		return (NULL);
	a[0] = '\0';
	return (a);
}

int				get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*content;
	int				read_output;
	char			*tmp;

	if ((!content && (content = ft_strnew()) == NULL) ||
	fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	while (!(ft_strchr(content, '\n')) &&
	(read_output = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_output] = '\0';
		tmp = content;
		content = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	*line = ft_substr(content, 0, ft_linelen(content));
	if (get_line(content) == NULL)
	{
		free(content);
		content = NULL;
		return (0);
	}
	return (1);
}
