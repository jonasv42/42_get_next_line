#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*to_free;
	
	int		fd;

	fd = open("read_error.txt", O_RDONLY);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(5454);
	printf("%s\n\n", to_free);
	free(to_free);

	fd = open("read_error.txt", O_RDONLY);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	printf("%i\n", fd);
	to_free = get_next_line(fd);
	printf("%s\n\n", to_free);
	free(to_free);
	
	
	return (0);
}