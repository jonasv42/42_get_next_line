/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:15:24 by jvets             #+#    #+#             */
/*   Updated: 2023/09/01 21:03:17 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*head[1024];
	char			*result;
	ssize_t			b_read;

	result = NULL;
	b_read = -2; //as to not get and unitialized variable error regarding line 29
	while (!result)
	{
		//before reading file check if lines lined up to be returned from the previous buffer
		if ((head)[fd] && (head)[fd]->content
			&& (head)[fd]->content[ft_strlen((head)[fd]->content) - 1] == '\n') //if a node contains a full line return it
			return_function(&(head)[fd], &result, 1);
		else if ((head)[fd] && (head)[fd]->content && b_read == 0) //only return node without \n if eof reached
			return_function(&(head)[fd], &result, 1);
		else
		{
			read_file(&b_read, &(head)[fd], fd);
			if ((b_read == 0 && !(head)[fd]) || (b_read == 0 && (head)[fd]
					&& *(head)[fd]->content == '\0') || b_read < 0) //error and end of file handling
			{
				return_function(&(head)[fd], &result, b_read);
				return (NULL);
			}
		}
	}
	return (result);
}

void	read_file(ssize_t *b_read, t_list **head, int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	*b_read = read(fd, buffer, BUFFER_SIZE);
	if (*b_read > 0)
	{
		buffer[*b_read] = '\0';
		buffer_cutter(buffer, &head); //function to cut the buffer into lines
	}
	free(buffer);
}

void	return_function(t_list **head, char **result, int r)
{
	t_list	*aux;

	if (r == 1) //if there is a node, free the node and point head to next
	{
		aux = *head;
		*result = ft_strdup((*head)->content);
		*head = (*head)->next;
		free(aux->content);
		free(aux);
	}
	else if (r == -1 && *head) //if error when reading, free whole list
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

void	buffer_cutter(char *buffer, t_list ***head)
{
	t_cut	cut; //struct used to save lines to conform to the norm
	cut.c = 0;
	cut.offset = 0;
	cut.len = 1;
	while (1)
	{
		if (buffer[cut.c] == '\0') //cuts line or beginning of a line and puts it in a node
		{
			if (buffer[cut.c - 1] != '\n') //as to not create an empty node
				add_node(ft_substr(buffer, cut.offset, cut.len), &head);
			break ;
		}
		if (buffer[cut.c] == '\n') //cuts line and puts it in a node
		{
			cut.c++;
			add_node(ft_substr(buffer, cut.offset, cut.len), &head);
			cut.offset = cut.c--; //weird postdecrement to diminish my else and keep function 25 lines max.
			cut.len = 1;
		}
		else
			cut.len++;
		cut.c++;
	}
}

void	add_node(char *content, t_list ****head)
{
	t_nodes	node; //struct to save lines to conform to the norm

	node.current = ***head;
	while (node.current != NULL && node.current->next != NULL) //find last node
		node.current = node.current->next;
	if (node.current != NULL && node.current->content
		&& node.current->content[ft_strlen(node.current->content) - 1] != '\n')
	//if the last node content doesn't end in \n, join with new content
	{
		node.str = ft_strjoin(node.current->content, content);
		free(node.current->content);
		free(content);
		node.current->content = node.str;
	}
	else //else make a new node
	{
		node.new_node = malloc(sizeof(t_list));
		if (!node.new_node)
			return ;
		node.new_node->content = content;
		node.new_node->next = NULL;
		if (!***head || (***head)->content == NULL) //if no head, make the new node the head
			***head = node.new_node;
		else //else add to back of the list
			node.current->next = node.new_node;
	}
}
