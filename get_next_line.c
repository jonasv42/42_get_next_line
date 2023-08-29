/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:24 by jvets             #+#    #+#             */
/*   Updated: 2023/08/29 16:34:11 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	t_list	*head;
	char	*result;
	ssize_t	b_read;

	result = NULL;
	while (!result)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';

		result = "a";
	}

	return ("a");
}