/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_tag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 00:53:27 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/27 05:13:54 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int handle_tag(t_tag *tag)
{
	if (tag->type == 's' || tag->type == 'S' || tag->type == 'C')
		return (handle_string(tag));
	else if (tag->type == 'i' || tag->type == 'd' || tag->type == 'D')
	{
		return (handle_int(tag));
	}
	else if (tag->type == 'o')
		return (handle_oct(tag));
	else if (tag->type == 'x' || tag->type == 'X')
	{
		if (tag->type == 'X')
			tag->cap = 1;
		return (handle_hex(tag));
	}
	else if (tag->type == 'c')
		return (handle_char(tag));
	else if (tag->type == '%')
		return (handle_percent(tag));
	else if (tag->type == 'u' || tag->type == 'U')
		return (handle_unsigned(tag));
	return (0);
}
