/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedecomb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:00:14 by fedecomb          #+#    #+#             */
/*   Updated: 2018/12/07 17:49:59 by fedecomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define CP(c, x, y) (c >= x && c <= y)
# define VD1(c) (c == ' ' || c == '\n' || c == '\t')
# define VD2(c) (c == '\v' || c == '\a' || c == '\b' || c == '\r'|| c == '\f')
# define VD(c) (VD1(c) || VD2(c))

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 20000

typedef struct	s_tsl
{
	double			t;
	double			s;
	double			l;
}				t_tsl;

typedef struct	s_rvb
{
	double			r;
	double			v;
	double			b;
}				t_rvb;

typedef struct	s_line
{
	char			*str;
	int				nbr;
	struct s_line	*next;
}				t_line;

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putnbr(int n);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,\
		size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle,\
		size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src,\
		int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src,\
		size_t n);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
char			*ft_strnew(size_t size);
size_t			ft_strlcat(char*dst, const char *src, size_t size);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
t_list			*ft_create_elem(void *content);
int				get_next_line(const int fd, char **line);
int				ft_nbr_mots(char const *s, char c);
char			*ft_cut_line(char *str, int len);
t_rvb			ft_tsl_to_rvb(t_tsl tsl);

#endif
