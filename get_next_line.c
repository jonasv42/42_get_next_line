/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:24 by jvets             #+#    #+#             */
/*   Updated: 2023/08/29 19:56:55 by jvets            ###   ########.fr       */
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
	b_read = 1;
	while (!result && (b_read > 0 || (head && head->content)))
	{
		if (head && ((char *)head->content)[ft_strlen((char *)head->content) - 1] == '\n')
		{
			result = ft_strdup((char *)head->content);
			delete_first_node(&head);
		}
		else if (b_read == 0 && head && head->content)
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