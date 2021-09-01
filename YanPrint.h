#ifndef YanPrint

#include <stdio.h>
#include <stdlib.h>
void printInt(int i);
void printChar(char ch);
void printString(char* str, int length);
void printIntArr(int* nums, int numsSize);



void printInt(int data) {
	printf("int: %d\n", data);
}

void printChar(char ch) {
	printf("char: %c", ch);
}
void printString(char* str, int length) {
	printf("string: ");
	for (int i = 0; i < length; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}
void printIntArr(int* nums, int numsSize) {
	for (int i = 0; i < numsSize; i++) {
		printf("%d\t", nums[i]);
	}
	printf("\n");
}


#endif // !YanPrint


