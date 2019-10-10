#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *num_to_time_stirng(double time_dec) {
	int hours = (int)time_dec;
	double minutes = time_dec - hours;
	minutes *= 60;
	int m = (int)minutes;
	char *time = (char*)malloc(30);
	char min[10];
	if (hours == 24) {
		hours = 00;
	}
	sprintf(time, "%d", hours);
	strcat(time, ":");
	if (m == 0) {
		strcat(time, "00");
	}
	else {
		sprintf(min, "%d", m);
		strcat(time, min);
	}

	return time;

}
char *date_to_string(int day, int month, int year) {
	char *date = (char*)malloc(300);
	//char *d = (char*)malloc(50);
	char *m = (char*)malloc(50);
	char *y = (char*)malloc(50);
	sprintf(date, "%d", day);
	sprintf(m, "%d", month);
	sprintf(y, "%d", year);
	strcat(date, "/");
	strcat(date, m);
	strcat(date, "/");
	strcat(date, y);
	return date;
}
int day_of_week(int day, int month, int year) {
	static int t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
	year -= month < 3;
	return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

}
int next_month_regulator(int cur_day, int cur_month) {
	if (cur_month == 1 && cur_day == 32 || cur_month == 3 && cur_day == 32 || cur_month == 5 && cur_day == 32 || cur_month == 7 && cur_day == 32 || cur_month == 8 && cur_day == 32 || cur_month == 10 && cur_day == 32 || cur_month == 12 && cur_day == 32) {
		return 1;

	}
	else if (cur_month == 2 && cur_day == 29) {
		return 1;
	}
	else if (cur_month == 4 && cur_day == 31 || cur_month == 6 && cur_day == 31 || cur_month == 9 && cur_day == 31 || cur_month == 11 && cur_day == 31) {
		return 1;
	}
	else {
		return 0;
	}
}
int hour_counting(int entery, int exit) {
	int count = 0, temp = 90, e = entery;
	while (temp != exit) {
		if (e = 24) {
			e = 0;
			count++;
		}
		else {
			e++;
			count++;
			temp = e;
		}
	}
	return count;
}
