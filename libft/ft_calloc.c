/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihakoby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:35:20 by sihakoby          #+#    #+#             */
/*   Updated: 2025/02/09 12:09:34 by sihakoby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count == 0 || size == 0)
		return (malloc(0));
	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, count * size);
	return (c);
}
