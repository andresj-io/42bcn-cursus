/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacome- <ajacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:12:26 by ajacome-          #+#    #+#             */
/*   Updated: 2023/08/01 12:33:34 by ajacome-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>
# include <stdint.h>

typedef enum e_status
{
	err,
	ok,
}	t_status;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Is character  */
int			is_lower(int c);
int			is_upper(int c);

/* Converters */
char		*ft_itoa(int n);
char		*ft_utoa(unsigned int ui);
char		*ft_utox(unsigned int ui);
char		*ft_ltox(unsigned long int num);
char		*ft_lltox(unsigned long long num);

/* Memory operators */
void		ft_bzero(void *s, int n);
void		*ft_calloc(size_t count, size_t size);

/* String Manipulations */
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			ft_toupper(int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_strrev(char *str);
void		ft_strup_iter(unsigned int i, char *c);

/* Write functions */
ssize_t		ft_putchar_fd(char c, int fd);
ssize_t		ft_putstr_fd(char *s, int fd);

/* Printf */
int			ft_printf(const char *format, ...);

/* No specifier */
t_status	pf_write_char(char c, ssize_t *count);
t_status	pf_write_str(char *str, ssize_t *count);

/* Specifiers */
t_status	pf_percent(ssize_t *count);
t_status	pf_char(va_list p_args, ssize_t *count);
t_status	pf_str(va_list p_args, ssize_t *count);
t_status	pf_int(va_list p_args, ssize_t *count);
t_status	pf_unsigned(va_list p_args, ssize_t *count);
t_status	pf_hex_lower(va_list p_args, ssize_t *count);
t_status	pf_hex_upper(va_list p_args, ssize_t *count);
t_status	pf_pointer(va_list p_args, ssize_t *count);

/* Flags */
char		*pf_add_hex_identifier(char *str);

#endif