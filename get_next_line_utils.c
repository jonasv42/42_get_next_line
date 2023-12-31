/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:22:14 by jvets             #+#    #+#             */
/*   Updated: 2023/08/31 22:21:18 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	buffer;
	char	*str;
	size_t	i;

	buffer = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(buffer);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void	*start_after_string(char **substr)
{
	*substr = malloc(1);
	if (!*substr)
		return (NULL);
	(*substr)[0] = '\0';
	return (*substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	buffer;

	buffer = ft_strlen(s);
	if (start > buffer)
		return (start_after_string(&substr));
	buffer -= start;
	if (buffer < len)
		buffer++;
	else
		buffer = len + 1;
	substr = malloc(buffer);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

char	*ft_strdup(const char *s)
{
	int		str_len;
	char	*str;

	str_len = ft_strlen(s);
	str = malloc(str_len + 1);
	if (!str)
		return (NULL);
	while (str_len >= 0)
	{
		str[str_len] = s[str_len];
		str_len--;
	}
	return (str);
}
