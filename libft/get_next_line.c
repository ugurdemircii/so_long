/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udemirci <udemirci@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:00:29 by udemirci          #+#    #+#             */
/*   Updated: 2025/04/08 17:15:17 by udemirci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(char *str, int fd)
{
	char	*temp;
	int		byte;

	temp = ft_calloc(1, (sizeof(char) * (BUFFER_SIZE + 1)));
	byte = 1;
	while (!new_check(str) && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			if (str)
				free(str);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		str = ft_strjoin_gnl(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_getline(char *s)
{
	int		i;
	char	*arr;

	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			break ;
	if (s[i] == '\n')
		i++;
	arr = ft_calloc(1, sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_cutline(char *str)
{
	char	*cuttedline;
	int		start;
	int		len;
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			break ;
	if (str[i] == '\n')
		i++;
	start = i;
	len = (ft_strlen(str) - start);
	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	cuttedline = ft_substr(str, start, len);
	free (str);
	return (cuttedline);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str || !*str)
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_getline(str);
	str = ft_cutline(str);
	return (line);
}
