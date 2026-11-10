# get_next_line

*This project was created as part of the 42 curriculum by pzavada.*

## Description
The goal of get_next_line (GNL) is to provide a reliable way to read text from a file or standard input until a newline character (\n) or the end of the file (EOF) is reached.

Key Learning Objectives are:
- Static Variables: Understanding persistent memory across multiple function calls.
- Memory Management: Handling dynamic allocation on the heap and ensuring zero memory leaks.
- Buffer Manipulation: Managing data flow using a variable BUFFER_SIZE defined at compile time.

## Instructions

### 1, Create a simple main function
**Example `main.c`:**
```c

#include <fcntl.h> // for open and close
#include <stdio.h> // for print
#include "path/to/get_next_line.h"

int	main(int argc, char *argv[])
{
	char	*line;
	int 	fd;

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
```
### 2, Compilation

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_test_bin  
./gnl_test_bin  path/to/archive
 - size of the buffer can be left out


## Implementation

The function follows relatively simple logic:
The program first reads form the file descriptor into a temporary buffer. This data is then appended to a static variable (stash) while the current length of the stash is kept track of. -> Then the buffer is searched for the \n delimiter and the return value of read is checked for EOF. -> Once a newline or EOF is found, the stash is returned. -> The static stash is updated to keep only the remaining "overflow" characters for the next function call.

Separating the initial read into a buffer allows for faster delimiter searching before appending to the stash. Additionally, by tracking the stash's length throughout the process, we eliminate the overhead of recalculating it in every helper function call.

## Resources

Main sources for this project were StackOverflow and the youtube channels Jacob Sorber and Portfolio Courses.
A huge help was also the gnlTester by Tripouille!

Implementation logic was debugged and optimized with the help of AI to ensure edge cases and memory leaks were addressed.
