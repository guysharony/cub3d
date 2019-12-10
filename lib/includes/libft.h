#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "../lib.h"

# define BUFFER_SIZE 32

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
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);

int			get_next_line(int fd, char **line);
char		*ft_strmcpy(char *str);
void		ft_error(char *str);

#endif
