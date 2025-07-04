/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:59:33 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/07 11:31:36 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (src == dst || len == 0)
		return (dst);
	if (s < d && s + len > d)
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	}
	else
	{
		while (len--)
		{
			*d = *s;
			s++;
			d++;
		}
	}
	return (dst);
}
