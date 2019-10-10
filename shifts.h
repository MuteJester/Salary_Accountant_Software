#pragma once
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct Shift_A {
	double *shiftsA;
	double *A100;
	double *A125;
	double *A150;
}shift_a;
typedef struct Shift_B {
	double *shiftsB;
	double *B122_5;
	double *B147_5;
	double *B172_5;

}shift_b;
typedef struct Shift_C {
	double *shiftsC;
	double *C142_5;
	double *C167_5;
	double *C192_5;
}shift_c;

int shift_regulator(double hours_worked, double entery_hour, double exit_hour) {
	double condition_c = 0;
	int flag = 0;
	if (entery_hour + hours_worked >= 24) {
		condition_c = (entery_hour + hours_worked) - 24;
		flag = 1;
	}
	else {
		condition_c = entery_hour + hours_worked;
	}

	if (entery_hour >= 14 && entery_hour <= 22 && hours_worked > 7.5 &&entery_hour + hours_worked < 24) {
		return 2;
	}
	else if (hours_worked >= 6.5 && flag == 1 || hours_worked >= 18 && entery_hour >= 4 || entery_hour + hours_worked >= 22 && hours_worked >= 6.5) {
		return 3;
	}
	else {
		return 1;
	}
}
void shift_A_hour_divider(double work_hours, double *first, double *second, double *third) {
	double hours = work_hours;
	if (hours <= 8.5) {
		(*first) = hours;
		return;
	}
	else if (hours > 8.5) {
		(*first) = 8.5;
		hours -= 8.5;
		if (hours <= 2) {
			(*second) = hours;
			return;
		}
		else {
			(*second) = 2;
			hours -= 2;
			(*third) = hours;
			return;
		}
	}

}
void shift_B_hour_divider(double work_hours, double *first, double *second, double *third) {
	double hours = work_hours;
	if (hours <= 7.5) {
		(*first) = hours;
		return;
	}
	else if (hours > 7.5) {
		(*first) = 7.5;
		hours -= 7.5;
		if (hours <= 2) {
			(*second) = hours;
			return;
		}
		else {
			(*second) = 2;
			hours -= 2;
			(*third) = hours;
			return;
		}
	}

}
void shift_C_hour_divider(double work_hours, double *first, double *second, double *third) {
	double hours = work_hours;
	if (hours <= 6.5) {
		(*first) = hours;
		return;
	}
	else if (hours > 6.5) {
		(*first) = 6.5;
		hours -= 6.5;
		if (hours <= 2) {
			(*second) = hours;
			return;
		}
		else {
			(*second) = 2;
			hours -= 2;
			(*third) = hours;
			return;
		}
	}

}
void shift_C_remeinder_hour_divider(double work_hours, double *second, double *third, shift_c *c, int index) {
	double hours = work_hours;
	double temp;
	if (c->C167_5[index] < 2) {
		temp = 2 - c->C167_5[index];
		(*second) = temp;
		hours -= temp;
		(*third) = hours;
		return;
	}
	else if (c->C167_5[index] == 2) {
		(*third) = hours;
		return;
	}

}
void allocate_all_shifts(shift_a *a, shift_b *b, shift_c *c) {
	a->shiftsA = (double*)calloc(31, sizeof(double));
	b->shiftsB = (double*)calloc(31, sizeof(double));
	c->shiftsC = (double*)calloc(31, sizeof(double));
	a->A100 = (double*)calloc(31, sizeof(double));
	a->A125 = (double*)calloc(31, sizeof(double));
	a->A150 = (double*)calloc(31, sizeof(double));
	b->B122_5 = (double*)calloc(31, sizeof(double));
	b->B147_5 = (double*)calloc(31, sizeof(double));
	b->B172_5 = (double*)calloc(31, sizeof(double));
	c->C142_5 = (double*)calloc(31, sizeof(double));
	c->C167_5 = (double*)calloc(31, sizeof(double));
	c->C192_5 = (double*)calloc(31, sizeof(double));
}
