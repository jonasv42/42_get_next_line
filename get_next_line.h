/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvets <jvets@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:15 by jvets             #+#    #+#             */
/*   Updated: 2023/08/29 16:25:06 by jvets            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

char	*get_next_line(int fd);

#endif