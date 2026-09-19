#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE  50ULL << 30
int main() {
	char *alloc = malloc((unsigned long)SIZE);
	if (!alloc) {
		printf("[err]: poor");
		return 1;
	}
	memset(alloc, 0, (unsigned long)SIZE);
	return 0;
}
