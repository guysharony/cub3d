/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:44:33 by gsharony          #+#    #+#             */
/*   Updated: 2020/01/23 11:10:38 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib.h"

# define BUFFER_SIZE 32

typedef struct			s_bitmap
{
	unsigned char		header[54];
	unsigned int		pi;
	unsigned int		pa;
	int					width;
	int					height;
}						t_bitmap;

typedef struct			s_data
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
}						t_data;

void		ft_putstr_fd(int fd, char *str);
void		ft_putnbr_fd(int fd, int nb);
void		ft_putchar_fd(int fd, char c);

void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char *str);

void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);

char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strnew(void);

int			get_next_line(int fd, char **line);
char		*ft_strmcpy(char *str);
int			ft_error(char *str, char *param);
int			ft_error_line(char *str, int line);
int			ft_error_redefined(int command);
int			ft_error_param(char *command, int nb);

char		**ft_split(char const *s, char c);
int			jumpto(int file, int commands);
int			jumpempty(int commands, char *map);
int			new_jumpto(char *file, int line);
char		*jumpto_map(int file);
int			ft_includes(char c, char *str);
int			ft_strincludes(char *str1, char *str2);
int			ft_isftype(char *filename, char *type);
int			ft_isnumber(char *nb);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		clean(char **lst);
char		**parsecolor(char *data);
int			ispresent(char *data, char *commands);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_lstlength(char **lst);

int			abs(int x);
int			bitmap(char *fn, int w, int h, int **data);
int			**malloc_buf(int x, int y);
t_data		**malloc_buf_data(int x, int y);
void		clear_buf_data(t_data ***buf, int h);

#endif
