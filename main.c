#include "get_next_line.h"
#include <fcntl.h> // for open and close
#include <stdio.h> // for print

int	main(int argc, char *argv[])
{
	char	*line;
	int 	fd = 1;
	//(void)argc;
	//(void)argv[0][0]; // for stdin
	if (argc != 2) // check amount of args
		return (printf("Wrong input.\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)  // check whether the file was opened properly
		return (printf("Cannot open file.\n"));
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd); // dont forget to close the file
	return (0);
}