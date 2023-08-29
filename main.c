#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;

	fd = open("test", O_RDONLY);

	get_next_line(fd);
	
	return (0);
}