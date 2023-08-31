/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:15 by jvets             #+#    #+#             */
/*   Updated: 2023/08/30 16:50:40 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	add_node(char *content, t_list ***head);
void	buffer_cutter(char *buffer, t_list **head);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif