#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;

	fd = open("41_no_nl", O_RDONLY);

	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	printf("%s\n\n", get_next_line(fd));
	
	return (0);
}