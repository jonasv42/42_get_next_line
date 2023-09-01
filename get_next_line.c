/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:24 by jvets             #+#    #+#             */
/*   Updated: 2023/08/31 21:39:46 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	return_function(t_list **head, char **result, int r);

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*head;
	char			*result;
	ssize_t			b_read;

	result = NULL;
	b_read = -2;
	while (!result)
	{
		if (head && head->content && head->content[ft_strlen(head->content) - 1] == '\n')
			return_function(&head, &result, 1);
		else if (head && head->content && b_read == 0) // only put line w/o \n in result if eof reached (b_read == 0)
			return_function(&head, &result, 1);
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
			if ((b_read == 0 && !head) || (b_read == 0 && head
					&& *head->content == '\0') || b_read < 0)
			{
				return_function(&head, &result, b_read);
				return (NULL);
			}
		}
	}
	return (result);
}

void	return_function(t_list **head, char **result, int r)
{
	t_list	*aux;

	if (r == 1)
	{
	aux = *head;
	*result = ft_strdup((*head)->content);
	*head = (*head)->next;
	free(aux->content);
	free(aux);
	}
	else if (r == -1 && *head)
	{
		aux = *head;
		while (aux != NULL && (*head)->next != NULL)
		{
			*head = (*head)->next;
			free(aux->content);
			free(aux);
		}
		free(aux->content);
		free(aux);
		*head = NULL;
	}
}
