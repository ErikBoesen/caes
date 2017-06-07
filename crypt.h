#pragma once
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHALEN 26

char *encode(int shift, char *str) {
	char *end = malloc(strlen(str));
	if (shift < 0) shift = 26 + shift;
	shift %= 26;
	for (int i = 0; i < strlen(str); i++) {
		char c = str[i];
		if (isalpha(c)) {
			if ((c <= 90 && c > 90 - shift) || (c > 122 - shift)) end[i] = c - 26 + shift;
			else end[i] = c + shift;
		} else end[i] = c;
	}
	end[strlen(str)] = '\0';
	return end;
}

char *decode(char *str) {
	int counts[ALPHALEN] = { 0 };

	for (int i = 0; i < strlen(str); i++) {
		char c = str[i];
		if (isalpha(c)) counts[c-(isupper(c) ? 'A' : 'a')]++;
	}

	int tot = 0;
	for (int i = 0; i < ALPHALEN; i++) tot += counts[i];

	int lrgi = 0;
	for (int i = 0; i < ALPHALEN; i++)
		if (counts[i] > counts[lrgi])
			lrgi = i;

	int shift = lrgi - 4;

	return encode(-shift, str);
}
