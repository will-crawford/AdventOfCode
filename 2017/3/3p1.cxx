
#include <cstdlib>
#include <iostream>

int main (int ac, const char **av) {
	if (ac < 2)
		usage();
	long offset;
	const char *tail;
	offset = strtol(av[1], &tail, 10);
	if (*tail != '\0')
		usage();
	long root = sqrt(offset);
			
	return EXIT_SUCCESS;
}

