/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:52:12 by julberna          #+#    #+#             */
/*   Updated: 2023/10/26 20:19:11 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *nptr);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_printf(const char *str, ...);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
char			**ft_split(const char *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*get_next_line(int fd);
void			ft_bzero(void *s, size_t n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
long int		ft_atol(const char *nptr);

int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));

/*printf utils*/
int				ft_handle_char(va_list args);
int				ft_handle_int(va_list args);
int				ft_handle_lower_hex(va_list args);
int				ft_handle_percent(void);
int				ft_handle_ptr(va_list args);
int				ft_handle_str(va_list args);
int				ft_handle_unsigned_int(va_list args);
int				ft_handle_upper_hex(va_list args);
int				ft_handle_space(va_list args, char specifier);
int				ft_handle_plus(va_list args);
int				ft_handle_octothorpe(char specifier, va_list args);

/*gnl utils*/
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_substr(const char *s, unsigned int start, size_t len);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);

/*extra*/
int				ft_wordcount(char *s, char c);

#endif
