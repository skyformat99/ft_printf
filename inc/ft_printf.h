/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:43:10 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/17 23:38:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct			s_tag
{
	char		pad;
	int			l_just;
	int			init_width;
	int         min_width;
	int         max_width;
	int         precision;
	char        type;
	int			header;
	int			hash;
	int			cap;
	int			sign;
	void		*arg;
	int			space;
	int			neg;
}						t_tag;

int		ft_printf(const char *format, ...);
int		process_tag(const char *fmt, void *c);
int		handle_tag(t_tag *tag);
int		count_handle(const char *fmt);
int		handle_hex(const t_tag *tag);
int		is_percent(const char *fmt, int i);
int 	is_type(char type);
int		is_flag(const char flag);
int		handle_oct(const t_tag *tag);
int		handle_int(const t_tag *tag);
int		handle_char(const t_tag *tag);
int		handle_string(const t_tag *tag);
int		handle_percent(const t_tag *tag);
t_tag	*init_tag(const char *fmt, void *c);
int   	next_point(const char *fmt, int i);
char	get_type(const char *tag);
char	*scan_flag(const char *fmt);
int		get_width(const char *fmt);
char	*create_width(const t_tag *tag, int init_len);
char	*join_width(char *base, char *width, int l_just);


#endif