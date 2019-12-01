/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libg.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:34:46 by gsharony          #+#    #+#             */
/*   Updated: 2019/12/01 11:54:08 by guysharon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBG_H
# define LIBG_H

# define BUFFER_SIZE 32
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		get_next_line(int fd, char **line);
char	*get_line(char *content);
int		ft_linelen(char *str);
char	**get_file(char *name);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(int fd, char *str);

#endif
