#include "assistant_f.h"
#include "salary_calculations.h"
#include "shifts.h"
#include "time_handling.h"
#include "display_features.h"

//start of each salary calculation is static ,it always start at the 16th and ends at the 15th
#define Mstart 16
#define Mend 15
//program mode , AUTO defines that the program will render random hours used for debugging and programing 
// MANUAL defines that the program will recive data from user
#define AUTO

//function which converts all processed data into an CSV file so it can be viewed as a spread sheet in excel 
void convert_current_data_to_csv(shift_a *a, shift_b *b, shift_c *c, int start_year, int start_month, int cur_year, int cur_mounth, double *working_hours, int days_worked, double *entrey, double *exit, int *e_days, double salary, double got_salary)
{

	char w_name[180];
	char *colum_name[14];
	char *month_append;
	char *year_append = int_to_str(cur_year);
	int d = 16, m = start_month, y = start_year, c_temp;
	double s_o_g_w_h = array_sum_d(working_hours, days_worked);
	char *sum_of_A100 = double_to_str(array_sum_d(a->A100, days_worked)), *sum_of_A125 = double_to_str(array_sum_d(a->A125, days_worked)), *sum_of_A150 = double_to_str(array_sum_d(a->A150, days_worked));
	char *sum_of_B122_5 = double_to_str(array_sum_d(b->B122_5, days_worked)), *sum_of_B147_5 = double_to_str(array_sum_d(b->B147_5, days_worked)), *sum_of_B172_5 = double_to_str(array_sum_d(b->B172_5, days_worked));
	char *sum_of_C142_5 = double_to_str(array_sum_d(c->C142_5, days_worked)), *sum_of_C167_5 = double_to_str(array_sum_d(c->C167_5, days_worked)), *sum_of_C192_5 = double_to_str(array_sum_d(c->C192_5, days_worked));
	char *sum_of_global_work_hours = double_to_str(s_o_g_w_h);
	if (start_month + 1 > 12) {
		month_append = int_to_str((start_month + 1)-12);
	}
	else {
		month_append = int_to_str(start_month + 1);
	}
	enter_workers_name_display();
	scanf("%s", &w_name);

	//All the names of the colums 
	colum_name[0] = "Mishmert Gimel 192.5 ";
	colum_name[1] = "Mishmert Gimel 167.5 ";
	colum_name[2] = "Mishmert Gimel 142.5 ";
	colum_name[3] = "Mishmert Bet 172.5 ";
	colum_name[4] = "Mishmert Bet 147.5 ";
	colum_name[5] = "Mishmert Bet 122.5 ";
	colum_name[6] = "Mishmert Alef 150";
	colum_name[7] = "Mishmert Alef 125";
	colum_name[8] = "Mishmert Alef 100";
	colum_name[9] = "Working Hours ";
	colum_name[10] = "Exit Hour ";
	colum_name[11] = "Entery Hour ";
	colum_name[12] = "Date";
	colum_name[13] = "Day";

	//file naming is formated by request in the follwoing order | "worker name"_"month of salary"_"year of claculation".csv
	strcat(w_name, "_");
	strcat(w_name, month_append);
	strcat(w_name, "_");
	strcat(w_name, year_append);
	strcat(w_name, ".csv");
	//

	int i;
	int line = 0;
	char *c3, *c2, *c1, *b3, *b2, *b1, *a3, *a2, *a1;
	char *w_hours, *exit_t, *entery_t, *date, *day;
	double exp_salary = expected_salary(a, b, c, working_hours, days_worked, salary), reminder_of_salary;
	reminder_of_salary = exp_salary - got_salary;
	FILE *new_sheet = fopen(w_name, "w");
	if (!new_sheet) {
		error_message_2();
		return;
	}

	for (i = 0; i < 14; i++) {
		fputs(colum_name[i], new_sheet);
		fputc(',', new_sheet);
	}

	fputc('\n', new_sheet);

	for (i = 0; i < days_worked; i++) {
		/*for (j = 0; j < 14; j++) {

			fputc(',', new_sheet);
		}*/
		c3 = double_to_str(c->C192_5[i]);
		c2 = double_to_str(c->C167_5[i]);
		c1 = double_to_str(c->C142_5[i]);
		b3 = double_to_str(b->B172_5[i]);
		b2 = double_to_str(b->B147_5[i]);
		b1 = double_to_str(b->B122_5[i]);
		a3 = double_to_str(a->A150[i]);
		a2 = double_to_str(a->A125[i]);
		a1 = double_to_str(a->A100[i]);
		w_hours = double_to_str(working_hours[i]);
		exit_t = num_to_time_stirng(exit[i]);
		entery_t = num_to_time_stirng(entrey[i]);
		day = int_to_str(e_days[i]);
		date = date_to_string(d, m, y);

		d++;

		if (next_month_regulator(d, m) == 1) {
			m++;
			if (m > 12) {
				m = 1;
				y++;
				d = 1;
				c_temp = 1;
			}
			else {
				d = 1;
				c_temp = 1;
			}


			fputc('\n', new_sheet);
		}
		fputs(c3, new_sheet);
		fputc(',', new_sheet);
		fputs(c2, new_sheet);
		fputc(',', new_sheet);
		fputs(c1, new_sheet);
		fputc(',', new_sheet);
		fputs(b3, new_sheet);
		fputc(',', new_sheet);
		fputs(b2, new_sheet);
		fputc(',', new_sheet);
		fputs(b1, new_sheet);
		fputc(',', new_sheet);
		fputs(a3, new_sheet);
		fputc(',', new_sheet);
		fputs(a2, new_sheet);
		fputc(',', new_sheet);
		fputs(a1, new_sheet);
		fputc(',', new_sheet);
		fputs(w_hours, new_sheet);
		fputc(',', new_sheet);
		fputs(exit_t, new_sheet);
		fputc(',', new_sheet);
		fputs(entery_t, new_sheet);
		fputc(',', new_sheet);
		fputs(date, new_sheet);
		fputc(',', new_sheet);
		fputs(day, new_sheet);
		fputc(',', new_sheet);
		fputc('\n', new_sheet);

	}

	for (i = 0; i < 10; i++) {
		fputs("---Sum---", new_sheet);
		fputc(',', new_sheet);
	}
	fputc('\n', new_sheet);
	//first data line
	fputs(sum_of_C192_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_C167_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_C142_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_B172_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_B147_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_B122_5, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_A150, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_A125, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_A100, new_sheet);
	fputc(',', new_sheet);
	fputs(sum_of_global_work_hours, new_sheet);
	fputc('\n', new_sheet);
	//seconed data line


	for (i = 0; i < 9; i++) {
		fputs("--Payment--", new_sheet);
		fputc(',', new_sheet);
	}
	fputc('\n', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(c->C192_5, days_worked, 1925, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(c->C167_5, days_worked, 1675, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(c->C142_5, days_worked, 1425, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(b->B172_5, days_worked, 1725, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(b->B147_5, days_worked, 1475, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(b->B122_5, days_worked, 1225, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(a->A150, days_worked, 150, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(a->A125, days_worked, 125, salary)), new_sheet);
	fputc(',', new_sheet);
	fputs(double_to_str(salary_of_spesific_token(a->A100, days_worked, 100, salary)), new_sheet);
	fputc(',', new_sheet);
	fputc('\n', new_sheet);





	for (i = 0; i < 13; i++) {
		fputc(',', new_sheet);
	}
	fputs(double_to_str(exp_salary), new_sheet);
	fputc(',', new_sheet);
	fputs(":Expected Salary", new_sheet);
	fputc('\n', new_sheet);

	for (i = 0; i < 13; i++) {
		fputc(',', new_sheet);
	}
	fputs(double_to_str(got_salary), new_sheet);
	fputc(',', new_sheet);
	fputs(":Salary Received", new_sheet);
	fputc('\n', new_sheet);

	for (i = 0; i < 13; i++) {
		fputc(',', new_sheet);
	}
	fputs(double_to_str(reminder_of_salary), new_sheet);
	fputc(',', new_sheet);
	fputs(":Gap", new_sheet);
	fputc('\n', new_sheet);



	fclose(new_sheet);
	file_created_message();
}
void proccessing_start() {
	srand(time(NULL));
	int c_temp = 0, start_month, start_year, day_f_f;
	int cur_month, cur_year, start_day, i, days_worked = 0;
	int cur_day_date = Mstart;
	double weekly_cap_flag = 0, working_cap_rem = 0, mem = 0, temp = 0, regular_reminder;
	double *entery_hours = (double*)malloc(31 * sizeof(double)), *exit_hours = (double*)malloc(31 * sizeof(double));
	double remainder, *working_hours = (double*)malloc(31 * sizeof(double));
	int days_of_week[31], sh_d;
	int day_o_week_flag = 0, flag_switch = 0;
	double Type_a, Type_b, Type_c;
	double expt_salary, recived_salary, reminder_to_worker, hourly_salary;

	//allocating memory for each shift group struct
	shift_a *a = (shift_a*)malloc(sizeof(shift_a));
	shift_b *b = (shift_b*)malloc(sizeof(shift_a));
	shift_c *c = (shift_c*)malloc(sizeof(shift_a));

	//allocating memory for each shift type inside each one of the shift groups
	allocate_all_shifts(a, b, c);

	enter_month_display();
	scanf_s("%d", &cur_month);
	start_month = cur_month;

	enter_year_display();
	scanf_s("%d", &cur_year);
	start_year = cur_year;
	start_day = day_of_week(16, cur_month, cur_year) + 1;

	for (i = 0; i < 31; i++) {
		printf("\n\nDate :[ %d/%d/%d ]  Day : [%d]\n ", cur_day_date, cur_month, cur_year, start_day);
		days_of_week[i] = start_day;
		day_f_f = start_day;
		start_day++;
		days_worked++;
		if (start_day > 7) {
			start_day = 1;
		}

		cur_day_date++;

		if (next_month_regulator(cur_day_date, cur_month) == 1) {
			cur_month++;
			if (cur_month > 12) {
				cur_month = 1;
				cur_year++;
				cur_day_date = 1;
				c_temp = 1;
			}
			else {
				cur_day_date = 1;
				c_temp = 1;
			}

		}
		if (cur_day_date == 17 && c_temp == 1) {
			days_worked--;
			break;
		}

		printf("\n  [Enter Entry Hour]  :- ");

		#ifdef MANUAL
		scanf_s("%lf", &entery_hours[i]);
		#endif		


		if (entery_hours[i] == 000) {
			entery_hours[i] = 0;
			exit_hours[i] = 0;
			working_hours[i] = 0;
			a->A100[i] = 0;
			a->A125[i] = 0;
			a->A150[i] = 0;
			a->shiftsA[i] = 0;
			b->B122_5[i] = 0;
			b->B147_5[i] = 0;
			b->B172_5[i] = 0;
			c->C142_5[i] = 0;
			c->C167_5[i] = 0;
			c->C192_5[i] = 0;
			c->shiftsC[i] = 0;

		}
		else {
			#ifdef AUTO
			entery_hours[i] = rand() % 24;
			#endif	


			printf("    [Enter Exit Hour]   :- ");

			#ifdef MANUAL
			scanf_s("%lf", &exit_hours[i]);
			#endif			

			#ifdef AUTO
			exit_hours[i] = rand() % 24 + 1;
			#endif



			if (entery_hours[i] > exit_hours[i]) {
				temp = entery_hours[i];
				remainder = 0;
				if (exit_hours[i] == 0) {
					remainder = 24 - exit_hours[i];
				}
				else {

					while (temp != exit_hours[i]) {
						if (temp == 24) {
							temp = 0;
						}
						else {
							remainder++;
							temp++;
						}
					}
				}
			}
			else {
				if (entery_hours[i] - exit_hours[i] < 0) {
					remainder = (entery_hours[i] - exit_hours[i]) * -1;
				}
				else {
					remainder = (entery_hours[i] - exit_hours[i]);
				}
			}

			working_hours[i] = remainder;

			if (day_f_f == 1) {
				flag_switch = 0;
				weekly_cap_flag = 0;
			}
			weekly_cap_flag += working_hours[i];

			if (weekly_cap_flag <= 43) {
				sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
				Type_a = 0;
				Type_b = 0;
				Type_c = 0;



				if (sh_d == 1) {
					a->shiftsA[i] = working_hours[i];
					shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					a->A100[i] = Type_a;
					a->A125[i] = Type_b;
					a->A150[i] = Type_c;
				}
				else if (sh_d == 2) {
					b->shiftsB[i] = working_hours[i];
					shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					b->B122_5[i] = Type_a;
					b->B147_5[i] = Type_b;
					b->B172_5[i] = Type_c;
				}
				else if (sh_d == 3) {
					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}

			}
			else {
				if (flag_switch == 1) {
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}
				else {
					working_cap_rem = weekly_cap_flag - 43;
					regular_reminder = working_hours[i] - working_cap_rem;

					sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;



					if (sh_d == 1) {
						a->shiftsA[i] = working_hours[i];
						shift_A_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						a->A100[i] = Type_a;
						a->A125[i] = Type_b;
						a->A150[i] = Type_c;
					}
					else if (sh_d == 2) {
						b->shiftsB[i] = working_hours[i];
						shift_B_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						b->B122_5[i] = Type_a;
						b->B147_5[i] = Type_b;
						b->B172_5[i] = Type_c;
					}
					else if (sh_d == 3) {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] = Type_a;
						c->C167_5[i] = Type_b;
						c->C192_5[i] = Type_c;
					}

					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					if (sh_d == 3) {
						shift_C_remeinder_hour_divider(working_cap_rem, &Type_b, &Type_c, c, i);
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;

					}
					else {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(working_cap_rem, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] += Type_a;
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;
					}

					flag_switch = 1;
				}
			}
			/*sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
			Type_a = 0;
			Type_b = 0;
			Type_c = 0;

			if (sh_d == 1) {
				a->shiftsA[i] = working_hours[i];
				shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				a->A100[i] = Type_a;
				a->A125[i] = Type_b;
				a->A150[i] = Type_c;
			}
			else if (sh_d == 2) {
				b->shiftsB[i] = working_hours[i];
				shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				b->B122_5[i] = Type_a;
				b->B147_5[i] = Type_b;
				b->B172_5[i] = Type_c;
			}
			else {
				c->shiftsC[i] = working_hours[i];
				shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				c->C142_5[i] = Type_a;
				c->C167_5[i] = Type_b;
				c->C192_5[i] = Type_c;
			}*/




		}
	}


	#ifdef DEBUG
	print_table(a, b, c, working_hours, days_worked, entery_hours, exit_hours);
	#endif

	enter_h_salary_display();
	scanf_s("%lf", &hourly_salary);

	enter_received_salary_display();
	scanf_s("%lf", &recived_salary);

#ifdef DEBUG
	expt_salary = expected_salary(a, b, c, working_hours, days_worked, hourly_salary);
	reminder_to_worker = expt_salary - recived_salary;

	
	printf("\n\t Worker Recived [%0.2lf] ILS\n", recived_salary);
	printf("\n\t Worker Expected Salary Was [%0.2lf] ILS\n", expt_salary);
	printf("\n\t Worker Needs to be payed [%0.2lf] ILS\n", reminder_to_worker);
	

	printf("Dates : 16/%d/%d - 15/%d/%d", start_month, start_year, cur_month, cur_year);
#endif

	convert_current_data_to_csv(a, b, c, start_year, start_month, cur_year, cur_month, working_hours, days_worked, entery_hours, exit_hours, &days_of_week, hourly_salary, recived_salary);

	 
}
int proccessing_start_first_link(int *last_year) {
	srand(time(NULL));
	int c_temp = 0, start_month, start_year, day_f_f;
	int cur_month, cur_year, start_day, i, days_worked = 0;
	int cur_day_date = Mstart;
	double weekly_cap_flag = 0, working_cap_rem = 0, mem = 0, temp = 0, regular_reminder;
	double *entery_hours = (double*)malloc(31 * sizeof(double)), *exit_hours = (double*)malloc(31 * sizeof(double));
	double remainder, *working_hours = (double*)malloc(31 * sizeof(double));
	int days_of_week[31], sh_d;
	int day_o_week_flag = 0, flag_switch = 0;
	double Type_a, Type_b, Type_c;
	double expt_salary, recived_salary, reminder_to_worker, hourly_salary;

	//allocating memory for each shift group struct
	shift_a *a = (shift_a*)malloc(sizeof(shift_a));
	shift_b *b = (shift_b*)malloc(sizeof(shift_a));
	shift_c *c = (shift_c*)malloc(sizeof(shift_a));

	//allocating memory for each shift type inside each one of the shift groups
	allocate_all_shifts(a, b, c);

	enter_month_display();
	scanf_s("%d", &cur_month);
	start_month = cur_month;

	enter_year_display();
	scanf_s("%d", &cur_year);
	start_year = cur_year;
	start_day = day_of_week(16, cur_month, cur_year) + 1;

	for (i = 0; i < 31; i++) {
		printf("\n\nDate :[ %d/%d/%d ]  Day : [%d]\n ", cur_day_date, cur_month, cur_year, start_day);
		days_of_week[i] = start_day;
		day_f_f = start_day;
		start_day++;
		days_worked++;
		if (start_day > 7) {
			start_day = 1;
		}

		cur_day_date++;

		if (next_month_regulator(cur_day_date, cur_month) == 1) {
			cur_month++;
			if (cur_month > 12) {
				cur_month = 1;
				cur_year++;
				cur_day_date = 1;
				c_temp = 1;
			}
			else {
				cur_day_date = 1;
				c_temp = 1;
			}

		}
		if (cur_day_date == 17 && c_temp == 1) {
			days_worked--;
			break;
		}

		printf("\n  [Enter Entry Hour]  :- ");

#ifdef MANUAL
		scanf_s("%lf", &entery_hours[i]);
#endif		


		if (entery_hours[i] == 000) {
			entery_hours[i] = 0;
			exit_hours[i] = 0;
			working_hours[i] = 0;
			a->A100[i] = 0;
			a->A125[i] = 0;
			a->A150[i] = 0;
			a->shiftsA[i] = 0;
			b->B122_5[i] = 0;
			b->B147_5[i] = 0;
			b->B172_5[i] = 0;
			c->C142_5[i] = 0;
			c->C167_5[i] = 0;
			c->C192_5[i] = 0;
			c->shiftsC[i] = 0;

		}
		else {
#ifdef AUTO
			entery_hours[i] = rand() % 24;
#endif	


			printf("    [Enter Exit Hour]   :- ");

#ifdef MANUAL
			scanf_s("%lf", &exit_hours[i]);
#endif			

#ifdef AUTO
			exit_hours[i] = rand() % 24 + 1;
#endif



			if (entery_hours[i] > exit_hours[i]) {
				temp = entery_hours[i];
				remainder = 0;
				if (exit_hours[i] == 0) {
					remainder = 24 - exit_hours[i];
				}
				else {

					while (temp != exit_hours[i]) {
						if (temp == 24) {
							temp = 0;
						}
						else {
							remainder++;
							temp++;
						}
					}
				}
			}
			else {
				if (entery_hours[i] - exit_hours[i] < 0) {
					remainder = (entery_hours[i] - exit_hours[i]) * -1;
				}
				else {
					remainder = (entery_hours[i] - exit_hours[i]);
				}
			}

			working_hours[i] = remainder;

			if (day_f_f == 1) {
				flag_switch = 0;
				weekly_cap_flag = 0;
			}
			weekly_cap_flag += working_hours[i];

			if (weekly_cap_flag <= 43) {
				sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
				Type_a = 0;
				Type_b = 0;
				Type_c = 0;



				if (sh_d == 1) {
					a->shiftsA[i] = working_hours[i];
					shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					a->A100[i] = Type_a;
					a->A125[i] = Type_b;
					a->A150[i] = Type_c;
				}
				else if (sh_d == 2) {
					b->shiftsB[i] = working_hours[i];
					shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					b->B122_5[i] = Type_a;
					b->B147_5[i] = Type_b;
					b->B172_5[i] = Type_c;
				}
				else if (sh_d == 3) {
					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}

			}
			else {
				if (flag_switch == 1) {
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}
				else {
					working_cap_rem = weekly_cap_flag - 43;
					regular_reminder = working_hours[i] - working_cap_rem;

					sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;



					if (sh_d == 1) {
						a->shiftsA[i] = working_hours[i];
						shift_A_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						a->A100[i] = Type_a;
						a->A125[i] = Type_b;
						a->A150[i] = Type_c;
					}
					else if (sh_d == 2) {
						b->shiftsB[i] = working_hours[i];
						shift_B_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						b->B122_5[i] = Type_a;
						b->B147_5[i] = Type_b;
						b->B172_5[i] = Type_c;
					}
					else if (sh_d == 3) {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] = Type_a;
						c->C167_5[i] = Type_b;
						c->C192_5[i] = Type_c;
					}

					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					if (sh_d == 3) {
						shift_C_remeinder_hour_divider(working_cap_rem, &Type_b, &Type_c, c, i);
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;

					}
					else {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(working_cap_rem, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] += Type_a;
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;
					}

					flag_switch = 1;
				}
			}
			/*sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
			Type_a = 0;
			Type_b = 0;
			Type_c = 0;

			if (sh_d == 1) {
				a->shiftsA[i] = working_hours[i];
				shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				a->A100[i] = Type_a;
				a->A125[i] = Type_b;
				a->A150[i] = Type_c;
			}
			else if (sh_d == 2) {
				b->shiftsB[i] = working_hours[i];
				shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				b->B122_5[i] = Type_a;
				b->B147_5[i] = Type_b;
				b->B172_5[i] = Type_c;
			}
			else {
				c->shiftsC[i] = working_hours[i];
				shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				c->C142_5[i] = Type_a;
				c->C167_5[i] = Type_b;
				c->C192_5[i] = Type_c;
			}*/




		}
	}


#ifdef DEBUG
	print_table(a, b, c, working_hours, days_worked, entery_hours, exit_hours);
#endif

	enter_h_salary_display();
	scanf_s("%lf", &hourly_salary);

	enter_received_salary_display();
	scanf_s("%lf", &recived_salary);

#ifdef DEBUG
	expt_salary = expected_salary(a, b, c, working_hours, days_worked, hourly_salary);
	reminder_to_worker = expt_salary - recived_salary;


	printf("\n\t Worker Recived [%0.2lf] ILS\n", recived_salary);
	printf("\n\t Worker Expected Salary Was [%0.2lf] ILS\n", expt_salary);
	printf("\n\t Worker Needs to be payed [%0.2lf] ILS\n", reminder_to_worker);


	printf("Dates : 16/%d/%d - 15/%d/%d", start_month, start_year, cur_month, cur_year);
#endif

	convert_current_data_to_csv(a, b, c, start_year, start_month, cur_year, cur_month, working_hours, days_worked, entery_hours, exit_hours, &days_of_week, hourly_salary, recived_salary);
	(*last_year) = cur_year;
	return cur_month;
}
int proccessing_start_linked(int last_month ,int *last_year) {
	srand(time(NULL));
	int c_temp = 0, start_month, start_year, day_f_f;
	int cur_month, cur_year, start_day, i, days_worked = 0;
	int cur_day_date = Mstart;
	double weekly_cap_flag = 0, working_cap_rem = 0, mem = 0, temp = 0, regular_reminder;
	double *entery_hours = (double*)malloc(31 * sizeof(double)), *exit_hours = (double*)malloc(31 * sizeof(double));
	double remainder, *working_hours = (double*)malloc(31 * sizeof(double));
	int days_of_week[31], sh_d;
	int day_o_week_flag = 0, flag_switch = 0;
	double Type_a, Type_b, Type_c;
	double expt_salary, recived_salary, reminder_to_worker, hourly_salary;

	//allocating memory for each shift group struct
	shift_a *a = (shift_a*)malloc(sizeof(shift_a));
	shift_b *b = (shift_b*)malloc(sizeof(shift_a));
	shift_c *c = (shift_c*)malloc(sizeof(shift_a));

	//allocating memory for each shift type inside each one of the shift groups
	allocate_all_shifts(a, b, c);

	//enter_month_display();
	//scanf_s("%d", &cur_month);
	cur_month = last_month;
	start_month = cur_month;

	//enter_year_display();
	//scanf_s("%d", &cur_year);
	cur_year = *last_year;
	start_year = cur_year;
	start_day = day_of_week(16, cur_month, cur_year) + 1;

	for (i = 0; i < 31; i++) {
		printf("\n\nDate :[ %d/%d/%d ]  Day : [%d]\n ", cur_day_date, cur_month, cur_year, start_day);
		days_of_week[i] = start_day;
		day_f_f = start_day;
		start_day++;
		days_worked++;
		if (start_day > 7) {
			start_day = 1;
		}

		cur_day_date++;

		if (next_month_regulator(cur_day_date, cur_month) == 1) {
			cur_month++;
			if (cur_month > 12) {
				cur_month = 1;
				cur_year++;
				cur_day_date = 1;
				c_temp = 1;
			}
			else {
				cur_day_date = 1;
				c_temp = 1;
			}

		}
		if (cur_day_date == 17 && c_temp == 1) {
			days_worked--;
			break;
		}

		printf("\n  [Enter Entry Hour]  :- ");

#ifdef MANUAL
		scanf_s("%lf", &entery_hours[i]);
#endif		


		if (entery_hours[i] == 000) {
			entery_hours[i] = 0;
			exit_hours[i] = 0;
			working_hours[i] = 0;
			a->A100[i] = 0;
			a->A125[i] = 0;
			a->A150[i] = 0;
			a->shiftsA[i] = 0;
			b->B122_5[i] = 0;
			b->B147_5[i] = 0;
			b->B172_5[i] = 0;
			c->C142_5[i] = 0;
			c->C167_5[i] = 0;
			c->C192_5[i] = 0;
			c->shiftsC[i] = 0;

		}
		else {
#ifdef AUTO
			entery_hours[i] = rand() % 24;
#endif	


			printf("    [Enter Exit Hour]   :- ");

#ifdef MANUAL
			scanf_s("%lf", &exit_hours[i]);
#endif			

#ifdef AUTO
			exit_hours[i] = rand() % 24 + 1;
#endif



			if (entery_hours[i] > exit_hours[i]) {
				temp = entery_hours[i];
				remainder = 0;
				if (exit_hours[i] == 0) {
					remainder = 24 - exit_hours[i];
				}
				else {

					while (temp != exit_hours[i]) {
						if (temp == 24) {
							temp = 0;
						}
						else {
							remainder++;
							temp++;
						}
					}
				}
			}
			else {
				if (entery_hours[i] - exit_hours[i] < 0) {
					remainder = (entery_hours[i] - exit_hours[i]) * -1;
				}
				else {
					remainder = (entery_hours[i] - exit_hours[i]);
				}
			}

			working_hours[i] = remainder;

			if (day_f_f == 1) {
				flag_switch = 0;
				weekly_cap_flag = 0;
			}
			weekly_cap_flag += working_hours[i];

			if (weekly_cap_flag <= 43) {
				sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
				Type_a = 0;
				Type_b = 0;
				Type_c = 0;



				if (sh_d == 1) {
					a->shiftsA[i] = working_hours[i];
					shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					a->A100[i] = Type_a;
					a->A125[i] = Type_b;
					a->A150[i] = Type_c;
				}
				else if (sh_d == 2) {
					b->shiftsB[i] = working_hours[i];
					shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					b->B122_5[i] = Type_a;
					b->B147_5[i] = Type_b;
					b->B172_5[i] = Type_c;
				}
				else if (sh_d == 3) {
					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}

			}
			else {
				if (flag_switch == 1) {
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					c->shiftsC[i] = working_hours[i];
					shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
					c->C142_5[i] = Type_a;
					c->C167_5[i] = Type_b;
					c->C192_5[i] = Type_c;
				}
				else {
					working_cap_rem = weekly_cap_flag - 43;
					regular_reminder = working_hours[i] - working_cap_rem;

					sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
					Type_a = 0;
					Type_b = 0;
					Type_c = 0;



					if (sh_d == 1) {
						a->shiftsA[i] = working_hours[i];
						shift_A_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						a->A100[i] = Type_a;
						a->A125[i] = Type_b;
						a->A150[i] = Type_c;
					}
					else if (sh_d == 2) {
						b->shiftsB[i] = working_hours[i];
						shift_B_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						b->B122_5[i] = Type_a;
						b->B147_5[i] = Type_b;
						b->B172_5[i] = Type_c;
					}
					else if (sh_d == 3) {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(regular_reminder, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] = Type_a;
						c->C167_5[i] = Type_b;
						c->C192_5[i] = Type_c;
					}

					Type_a = 0;
					Type_b = 0;
					Type_c = 0;

					if (sh_d == 3) {
						shift_C_remeinder_hour_divider(working_cap_rem, &Type_b, &Type_c, c, i);
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;

					}
					else {
						c->shiftsC[i] = working_hours[i];
						shift_C_hour_divider(working_cap_rem, &Type_a, &Type_b, &Type_c);
						c->C142_5[i] += Type_a;
						c->C167_5[i] += Type_b;
						c->C192_5[i] += Type_c;
					}

					flag_switch = 1;
				}
			}
			/*sh_d = shift_regulator(working_hours[i], entery_hours[i], exit_hours[i]);
			Type_a = 0;
			Type_b = 0;
			Type_c = 0;

			if (sh_d == 1) {
				a->shiftsA[i] = working_hours[i];
				shift_A_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				a->A100[i] = Type_a;
				a->A125[i] = Type_b;
				a->A150[i] = Type_c;
			}
			else if (sh_d == 2) {
				b->shiftsB[i] = working_hours[i];
				shift_B_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				b->B122_5[i] = Type_a;
				b->B147_5[i] = Type_b;
				b->B172_5[i] = Type_c;
			}
			else {
				c->shiftsC[i] = working_hours[i];
				shift_C_hour_divider(working_hours[i], &Type_a, &Type_b, &Type_c);
				c->C142_5[i] = Type_a;
				c->C167_5[i] = Type_b;
				c->C192_5[i] = Type_c;
			}*/




		}
	}


#ifdef DEBUG
	print_table(a, b, c, working_hours, days_worked, entery_hours, exit_hours);
#endif

	enter_h_salary_display();
	scanf_s("%lf", &hourly_salary);

	enter_received_salary_display();
	scanf_s("%lf", &recived_salary);

#ifdef DEBUG
	expt_salary = expected_salary(a, b, c, working_hours, days_worked, hourly_salary);
	reminder_to_worker = expt_salary - recived_salary;


	printf("\n\t Worker Recived [%0.2lf] ILS\n", recived_salary);
	printf("\n\t Worker Expected Salary Was [%0.2lf] ILS\n", expt_salary);
	printf("\n\t Worker Needs to be payed [%0.2lf] ILS\n", reminder_to_worker);


	printf("Dates : 16/%d/%d - 15/%d/%d", start_month, start_year, cur_month, cur_year);
#endif

	convert_current_data_to_csv(a, b, c, start_year, start_month, cur_year, cur_month, working_hours, days_worked, entery_hours, exit_hours, &days_of_week, hourly_salary, recived_salary);
	(*last_year) = cur_year;
	return cur_month;
}


void main() {
	greeting_menu();
	int choice,flag,start_month,cur_month=0,last_year=0;
	do
	{
		choice_menu();
		scanf_s("%d", &choice);


		switch (choice)
		{
		case(-1):
			break;
		case(1):
			proccessing_start();
			choice = -1;
			break;
		case(2):
			start_month = proccessing_start_first_link(&last_year) - 1;
			cur_month = start_month + 1;
			while (cur_month != start_month) {
				cur_month = proccessing_start_linked(cur_month,&last_year);
			}
			choice = -1;
			break;
		default:
			error_message();
			break;
		}

	} while (choice != -1);

	exit_message();
}
