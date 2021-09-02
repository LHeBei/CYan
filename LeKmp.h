#ifndef LeKmp
#define LeKmp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "YanPrint.h"
int strStr(char* haystack, char* needle);
int kmp(char* pattern, char* text);
int* computeNextArray(char* pattern);

int strStr(char* haystack, char* needle) {
	return kmp(haystack, needle);
}
int kmp(char* text, char* pattern) {
	if (pattern == NULL || pattern == "") return 0;
	int pattern_size = strlen(pattern);
	int text_size = strlen(text);
	int* next = computeNextArray(pattern);
	int i = 0, j = 0;
	while (i < pattern_size && j < text_size) {
		if (text[j] == pattern[i]) {
			j++;
			i++;
		}
		else {
			if (i != 0) {
				i = next[i - 1];
			}
			else {
				j++;
			}
		}
	}
	if (i == pattern_size) return j - i;
	return -1;
	free(next);
}

int* computeNextArray(char* pattern) {
	int pattern_size = strlen(pattern);
	int* next = (int*)calloc(pattern_size, sizeof(int));
	int index = 0;
	for (int i = 1; i < pattern_size;) {
		if (pattern[i] == pattern[index]) {
			next[i++] = ++index;
		}
		else {
			if (index != 0) {
				index = next[index - 1];
			}
			else {
				next[i++] = 0;
			}
		}
	}
	return next;
}
#endif // !LeKmp
