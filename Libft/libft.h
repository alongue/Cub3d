/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:21:36 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 12:21:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_abs(int nb);
char			*ft_appendstr(char *s, char c);
int				ft_atoi(const char *str);
double			ft_atod_base(const char *str, const char *base);
long			ft_atol_base(const char *str, const char *base);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_convert_basel(const char *nbr,
const char *base_from, const char *base_to);
char			*ft_ctos(char c);
int				free_ret(int myret, ...);
int				ft_free_ret(int ret, void **a1, void **a2, void **a3);
size_t			ft_get_nbchar(const char *str, int c);
size_t			ft_get_nbprint(const char *str);
size_t			ft_get_nbspace(const char *str);
int				ft_getpos(const char *str, int c, int num);
int				ft_getposn(const char *str, int c, int num, int start);
size_t			ft_intlen(int n);
int				ft_isalnum(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isonlychar(const char *main_str, const char *str);
int				ft_isprint(int c);
int				ft_isspace(int c);
char			*ft_itoa(int n);
int				ft_is_in_a_row(char *str, int c);
char			*ft_ltoa_base(long n, const char *base);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1a, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memseti(void *b, int c, size_t len);
double			ft_pow(double nb, double power);
long			ft_powl(long nb, long power);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			*ft_putstrret_fd(char *s, void *ret, int fd);
int				ft_putstrreti_fd(char *s, int ret, int fd);
void			*ft_realloc(void **ptr, size_t size, size_t oldsize, int dofree);
char			*ft_rmchar(const char *str, int c);
double			ft_round(double nb);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *pre, char *suf);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
const char *needle, size_t len);
int				ft_strstrpart(char *str, size_t start, char *cmp);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_swap(void **a, void **b);
int				ft_tolower(int c);
int				ft_toupper(int c);
struct			s_list
{
	void			*content;
	struct s_list	*next;
};
typedef struct s_list	t_list;
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *));

#endif
