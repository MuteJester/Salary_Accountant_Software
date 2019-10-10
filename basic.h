#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int array_sum(int *arr, int size) {
	int i, sum = 0;
	for (i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
char *int_to_str(int num) {
	int temp = num;
	char *str = (char*)malloc(300);
	sprintf(str, "%d", temp);
	return str;
}
char *double_to_str(double num) {
	int whole = (int)num;
	double frac = num - whole;
	frac *= 100;
	int f_i = (int)frac;
	char *num_w = (char*)malloc(300);
	char min[90];
	sprintf(num_w, "%d", whole);
	strcat(num_w, ".");
	sprintf(min, "%d", f_i);
	strcat(num_w, min);

	return num_w;
}
double array_sum_d(double *arr, int size) {
	int i;
	double sum = 0;
	for (i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum;
}
void print_array(int *arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d\n ", arr[i]);
	}
}
