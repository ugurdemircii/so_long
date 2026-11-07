/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:56:58 by udemirci          #+#    #+#             */
/*   Updated: 2024/10/28 15:44:31 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	i;
	size_t	last_index;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	last_index = ft_strlen(s1);
	if (last_index > 0)
	{
		last_index--;
		while (last_index > i && ft_strchr(set, s1[last_index]))
			last_index--;
	}
	if (i > last_index)
		return (ft_substr(s1, i, 0));
	p = ft_substr(s1, i, last_index - i + 1);
	return (p);
}
