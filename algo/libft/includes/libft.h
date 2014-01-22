/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubert <jaubert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:48:55 by jaubert           #+#    #+#             */
/*   Updated: 2014/01/22 15:32:27 by jaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE	1000

# ifndef T_LIST
#  define T_LIST

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# endif

int				ft_isspace(int c);
int				ft_count_digit(int c);
void			ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
ssize_t			ft_putchar(char c);
ssize_t			ft_putstr(const char *str);
ssize_t			ft_putendl(const char *str);
ssize_t			ft_putnbr(int n);
ssize_t			ft_putbase(unsigned int n, char *base);
ssize_t			ft_putchar_fd(char c, int fd);
ssize_t			ft_putstr_fd(const char *s, int fd);
ssize_t			ft_putendl_fd(const char *s, int fd);
ssize_t			ft_putnbr_fd(int n, int fd);
int				ft_count_word(char *str, char c);
int				ft_word_size(char *str, char c);
char			**ft_strsplit(char *s, char c);
int				get_next_line(int const fd, char **line);
void			ft_free_chtab(char **tab);
char			**ft_cpy_chtab(char **ch2);
t_list			*ft_listnew(void *ptr);
void			*gmalloc(size_t size);
int				ft_garb(int flag, void *ptr);
void			gclean(t_list **list);
void			gfree(void *ptr, t_list **list);
void			ft_print_list(t_list *list);

#endif	/* !LIBFT_H */
