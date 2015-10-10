/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/05 14:59:44 by vroche            #+#    #+#             */
/*   Updated: 2014/11/05 19:28:18 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*s;

	s = dst;
	while (n > 0 && ((*dst++ = *src++) != '\0'))
	{
		n--;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		n--;
	}
	return (s);
}
