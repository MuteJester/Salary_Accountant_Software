#pragma once
#include "shifts.h"
#include "assistant_f.h"
#include "time_handling.h"
double expected_salary(shift_a *a, shift_b *b, shift_c *c, double *working_hours, int working_days, double hourly_salary) {
	double sum_of_working_hours = array_sum_d(working_hours, working_days);
	double calculated_salary;

	double sum_of_A100 = array_sum_d(a->A100, working_days), sum_of_A1250 = array_sum_d(a->A125, working_days), sum_of_A150 = array_sum_d(a->A150, working_days);
	double sum_of_B122_5 = array_sum_d(b->B122_5, working_days), sum_of_B147_5 = array_sum_d(b->B147_5, working_days), sum_of_B172_5 = array_sum_d(b->B172_5, working_days);
	double sum_of_C142_5 = array_sum_d(c->C142_5, working_days), sum_of_C167_5 = array_sum_d(c->C167_5, working_days), sum_of_C192_5 = array_sum_d(c->C192_5, working_days);
	if (sum_of_A100 + sum_of_A1250 + sum_of_A150 + sum_of_B122_5 + sum_of_B147_5 + sum_of_B172_5 + sum_of_C167_5 + sum_of_C142_5 + sum_of_C192_5 != sum_of_working_hours) {
		printf("\n\t\tError Occured Aborting Calculation! %0.2lf | %0.2lf \n", sum_of_working_hours, sum_of_A100 + sum_of_A1250 + sum_of_A150 + sum_of_B122_5 + sum_of_B147_5 + sum_of_B172_5 + sum_of_C167_5 + sum_of_C142_5 + sum_of_C192_5);

	}
	calculated_salary = (sum_of_A100 *hourly_salary) + (sum_of_A1250 *1.25*hourly_salary) + (sum_of_A150 *1.5 * hourly_salary);
	calculated_salary = calculated_salary + (sum_of_B122_5 *1.225*hourly_salary) + (sum_of_B147_5 * 1.475 *hourly_salary) + (sum_of_B172_5 * 1.725 *hourly_salary);
	calculated_salary = calculated_salary + (sum_of_C142_5 * 1.425 *hourly_salary) + (sum_of_C167_5 * 1.675 *hourly_salary) + (sum_of_C192_5 * 1.925*hourly_salary);

	return calculated_salary;
}
double salary_of_spesific_token(double *token_shifts, int days_worked, int token_type, double hourly_salary) {
	double salary = 0;
	switch (token_type)
	{
	case(100):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary;
		return salary;
	case(125):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.25;
		return salary;
	case(150):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.5;
		return salary;
	case(1225):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.225;
		return salary;
	case(1475):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary *1.475;
		return salary;
	case(1725):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.725;
		return salary;
	case(1425):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.425;
		return salary;
	case(1675):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.675;
		return salary;
	case(1925):
		salary = array_sum_d(token_shifts, days_worked) * hourly_salary * 1.925;
		return salary;
	}
}
void print_table(shift_a *a, shift_b *b, shift_c *c, double *working_hours, int size, double *entrey, double *exit) {
	int i;
	printf("\n");
	char *ent_time = NULL;
	char *ex_time = NULL;
	for (i = 0; i < 100; i++) {
		printf("\xB0");
	}
	printf("\n\n\n[Gimel 192.5] [Gimel 167.5] [Gimel 142.5] [Bet 172.5] [Bet 147.5] [Bet 122.5] [Alef 150] [Alef 125] [Alef 100]  [Hours Worked] [Exit Hour] [Entery Hour]\n\n");
	for (i = 0; i < size; i++) {
		ent_time = num_to_time_stirng(entrey[i]);
		ex_time = num_to_time_stirng(exit[i]);
		printf("  %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.1lf \t %0.2lf \t |%s| \t |%s|\n", c->C192_5[i], c->C167_5[i], c->C142_5[i], b->B172_5[i], b->B147_5[i], b->B122_5[i], a->A150[i], a->A125[i], a->A100[i], working_hours[i], ex_time, ent_time);
	}

}
