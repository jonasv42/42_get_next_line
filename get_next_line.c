/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:24 by jvets             #+#    #+#             */
/*   Updated: 2023/08/30 20:23:43 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	delete_first_node(t_list **head);

char	*get_next_line(int fd)
{
	char	*buffer;
	static t_list	*head;
	char	*result;
	ssize_t	b_read;

	result = NULL;
	b_read = -1;
	while (!result)
	{
		if (head && head->content && ft_strlen(head->content) > 0 && head->content[ft_strlen(head->content) - 1] == '\n')
		{
			result = ft_strdup((char *)head->content);
			delete_first_node(&head);
		}
		else if (head && head->content && b_read == 0) // only put line w/o \n in result if eof reached (b_read == 0)
		{
			result = ft_strdup((char *)head->content);
			delete_first_node(&head);
		}
		else
		{
			buffer = malloc(BUFFER_SIZE + 1);
			b_read = read(fd, buffer, BUFFER_SIZE);

			if (b_read > 0)
			{
				buffer[b_read] = '\0';
				buffer_cutter(buffer, &head);
			}
			
			free(buffer);

			if (b_read < 0 || (b_read == 0 && !head) || (b_read == 0 && head && *head->content == '\0'))
				return (NULL);
		}
	}

	return (result);
}

void	delete_first_node(t_list **head)
{
	t_list	*aux;

	aux = *head;
	*head = (*head)->next;
	free(aux->content);
	free(aux);
}