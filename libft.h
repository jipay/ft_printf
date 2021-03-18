/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdidier <jdidier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:20:16 by jdidier           #+#    #+#             */
/*   Updated: 2020/10/18 00:28:32 by jdidier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_fmt
{
	int		minus;
	int		zero;
	int		point;
	int		min_w;
	int		prcsn;
	int		ret;
	char	conv;
}				t_fmt;

void			*ft_memset(void *s, int c, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long int n, int fd);
int				ft_printf(const char *format, ...);
t_fmt			*ft_init_fmt();
int				ft_isflag(int c, t_fmt *fmt);
void			ft_checkminw(char **format, t_fmt *fmt, va_list ad);
void			ft_checkprcsn(char **format, t_fmt *fmt, va_list ad);
int				ft_isconv(int c);
char			*ft_itoa_base(unsigned long long n, char *base);
int				ft_parse_c(t_fmt *fmt, int c);
int				ft_parse_s(t_fmt *fmt, va_list ad);
int				ft_parse_d(t_fmt *fmt, int arg_d);
int				ft_parse_u(t_fmt *fmt, unsigned int arg_u);
int				ft_parse_p(t_fmt *fmt, unsigned long int arg_p);
char			*ft_init_arg_u(t_fmt *fmt, unsigned int arg_u);
char			*ft_init_result_c(t_fmt *fmt);
char			*ft_init_result_s(int width);
char			*ft_init_result_d(t_fmt *fmt, int width, int i);
char			*ft_init_result_p(t_fmt *fmt, int width);
char			*ft_init_result_u(t_fmt *fmt, int width);
void			ft_display_result(char *result, char *arg, t_fmt *fmt);

#endif
