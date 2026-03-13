#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *c);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *str, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
int					ft_printf(const char *tipo, ...);
int					ft_putchar(int c);
int					ft_putstr(const char *str);
int					ft_hexconv(unsigned long ptr, char a);
int					ft_print_pointer(unsigned long ptr);
int					ft_printnbr(int n);
int					ft_print_u(unsigned int a);
int					ft_print_hex(unsigned long n, char c);
char				*get_next_line(int fd);
size_t				ft_len(const char *buffer);
char				*ft_strjoin_get(char *line, char *buffer);
void				*ft_memcpy_get(void *dest, const void *src, size_t n);
char				*ft_substr_get(char const *s, unsigned int start,
						size_t len);
char				*ft_check_error_get(int n, char *nline, char *buffer);
int					ft_isspace(int c);
int					ft_ispipe(int c);
int					ft_is_word_char(int c);
int					ft_is_redir(int c);
int					ft_is_op(int c);
int					ft_oplen(char *op, int i);
int					ft_is_quote(int c);
int					ft_is_acceptable(int c);
void				*free_array(char **s);

#endif