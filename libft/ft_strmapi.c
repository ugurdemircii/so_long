/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:09:45 by udemirci          #+#    #+#             */
/*   Updated: 2024/10/28 20:23:40 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[len] = '\0';
	return (p);
}
