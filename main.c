#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*to_free;
	
	int		fd;

	fd = open("41_with_nl", O_RDONLY);

	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	
	return (0);
}