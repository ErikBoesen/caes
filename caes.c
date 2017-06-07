#include <stdio.h>
#include <string.h>
#include "crypt.h"
#include "io.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("usage: \n    caes <-e|-d> [args...]\n");
		return 1;
	}
	if (strcmp(argv[1], "-e") == 0) {
		if (argc != 4) {
	 		printf("usage:\n    caes -e <file> <shift>\n");
			return 1;
		}
		write(argv[2], encode(atoi(argv[3]), read(argv[2])));
	} else if (strcmp(argv[1], "-d") == 0) {
		if (argc != 3) {
			printf("usage:\n    caes -d <file>\n");
			return 1;
		}
		write(argv[2], decode(read(argv[2])));
	} else {
		printf("usage: \n    caes <-e|-d> [args...]\n");
		return 1;
	}
	return 0;
}
