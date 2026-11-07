/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 15:48:30 by udemirci          #+#    #+#             */
/*   Updated: 2024/10/28 20:18:31 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (needle[x] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + x] == needle[x] && (i + x) < len && haystack[i + x])
			x++;
		if (needle[x] == '\0')
			return ((char *)haystack + i);
		i++;
		x = 0;
	}
	return (NULL);
}
