/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvasseur <bvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:08:12 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 16:31:18 by bvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*name;
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_abs(int nb);
int					ft_atoi_base(char *str, char *base);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
size_t				ft_countc(char *str, char c);
char				**ft_free_map(char **map, size_t len);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itob(unsigned long n, const char *base);
int					ft_lennum(long nb);
char				**ft_mapcpy(char **original, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_mod(int nb, int mod);
size_t				ft_numbers_of_lines(char *path);
size_t				ft_power(int a, int b);
int					ft_printf(const char *s, ...);
void				ft_putchar_fd(char c, int fd);
int					ft_putchar(int c);
void				ft_putendl_fd(char const *s, int fd);
int					ft_putendl(char const *s);
int					ft_put_malloc_free(char *s, void (*del)(void *));
void				ft_putnbr_fd(int n, int fd);
int					ft_putnbr(int n);
int					ft_putnbru(unsigned long n);
int					ft_putptr(unsigned long ptr);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putstr(char const *s);
int					ft_rrand(int init, unsigned int seed, unsigned int min,
						unsigned int max);
void				ft_srand(unsigned int seed);
int					ft_rand(int a, int b);

char				**ft_split(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int to_find);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlentc(const char *str, char c);
size_t				ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strncpy(char *dest, const char *src, size_t size);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
char				*ft_strrchr(const char *str, int to_find);
char				*ft_strtrim(char const *s1, char const *charset);
char				*ft_substr(char const *s, unsigned int start, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*get_next_line(int fd);

t_list				*ft_lst_getindex(t_list *lst, size_t index);
t_list				*ft_lst_getel(t_list *lst, char *name);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(char *name, void *content);
size_t				ft_lstsize(t_list *lst);

#endif
