/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:41:24 by hehuang           #+#    #+#             */
/*   Updated: 2017/05/20 03:07:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_int(const t_tag *tag)
{
	char	*num;
	char	*ret;
	int		init_len;
	char	*width;
	int		len;

	num = precision_itoa(tag, 10, 0);
	init_len = ft_strlen(num);
	width = create_width(tag, init_len);
	if (width)
	{
		if (tag->l_just)
			ret = ft_strjoin(num, width);
		else
			ret = ft_strjoin(width, num);
		ft_putstr(ret);
		len = ft_strlen(ret);
		printf("ret is: |%s|\n", ret);
		free(num);
		free(ret);
		return (len);
	}
	ft_putstr(num);
	free(num);
	return (init_len);
}
