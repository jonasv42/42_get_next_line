/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:15 by jvets             #+#    #+#             */
/*   Updated: 2023/08/31 22:03:57 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cut
{
	ssize_t	c;
	ssize_t	offset;
	int		len;
}	t_cut;

typedef struct s_nodes
{
	t_list	*new_node;
	t_list	*current;
	char	*str;
}	t_nodes;

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	add_node(char *content, t_list ***head);
void	buffer_cutter(char *buffer, t_list **head);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

#endif