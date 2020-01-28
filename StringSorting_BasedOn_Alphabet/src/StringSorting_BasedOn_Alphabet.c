/*
 ============================================================================
 Name        : StringSorting_BasedOn_Alphabet.c
 Author      : Shivam Palaskar
 Version     :
 Copyright   : Open source
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getStringArray(char[], char*, int);
void printArray(char*, int, int);
int getLength(char[]);

int main(void) {
	char arr[100] = { "abc,aabc,aaabc,aaaabc" };
	char string1[100];
	strcpy(string1, arr);
	int len = getLength(string1);
	strcpy(string1, arr);
	char string[len][20];
	getStringArray(string1, string, 20);
	printf("\n Array Before Sorting : ");
	printArray(string, len, 20);
	//bubbleSort(string, len,20);
	char temp[20];
	int cmp;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i - 1); j++) {
			for (int k = 0; k < 20; k++) {
				if (string[j][k] != string[j + 1][k]) {
					cmp = k;
					break;
				}
			}
			if (string[j][cmp] > string[j + 1][cmp]) {
				strcpy(temp, string[j + 1]);
				strcpy(string[j + 1], string[j]);
				strcpy(string[j], temp);
			}
		}
	}
	printf("\n Array After Bubble sort : ");
	printArray(string, len, 20);
	return EXIT_SUCCESS;
}

void getStringArray(char string1[], char *string, int size) {
	char* token = strtok(string1, ",");
	int i = 0;
	while (token != NULL) {
		strcpy((string + i * size), token);
		token = strtok(NULL, ",");
		i++;
	}
}

int getLength(char string1[]) {
	char* token = strtok(string1, ",");
	int len = 0;
	while (token != NULL) {
		len++;
		token = strtok(NULL, ",");
	}
	return len;
}
void bubbleSort(int *string, int len, int size) {
	char temp[size];
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i - 1); j++) {
			if ((string + j * size) > (string + (j + 1) * size)) {
				strcpy(temp, (string + (j + 1) * size));
				strcpy((string + (j + 1) * size), (string + j * size));
				strcpy((string + j * size), temp);
			}
		}
	}
}

void printArray(char *string, int len, int size) {
	for (int i = 0; i < len; i++) {
		printf("%s ", (string + i * size));
	}
}

