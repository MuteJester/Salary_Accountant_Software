#pragma once
#include <stdio.h>
#include <Windows.h>

#define X_CORD 70
#define Y_CORD 10

void greeting_menu() {
	int i, j, flag = 0;
	printf("\n");
	for (i = 0; i < 24; i++) {
		printf(" ");
	}
	for (i = 0; i < 70; i++) {
		printf("\xb2");
	}
	for (i = 0; i < 14; i++) {
		printf("\n");
		for (j = 0; j < 95; j++) {
			if (j == 24) {
				printf("\xb2");
			}
			else if (j == 30 && flag < 1) {
				printf("Salary Accounting Softwere");
				j = 55;
				flag = 1;
			}
			else if (j == 93) {
				printf("\xb2");

			}
			else if (i == 5 && flag < 2 && j == 27) {
				printf("Monthly work hours calculated and exported into excel format");
				j = 86;
				flag = 2;
			}
			else if (i == 7 && flag < 3 && j == 27) {
				printf("all calculations done by experienced accountant guide lines");
				j = 85;
				flag = 3;
			}
			else if (i == 13 && flag < 4 && j == 79) {
				printf("By:Thomas.k");
				j = 89;
				flag = 4;
			}
			else {
				printf(" ");
			}
		}
	}
	printf("\n");
	for (i = 0; i < 24; i++) {
		printf(" ");
	}
	for (i = 0; i < 70; i++) {
		printf("\xb2");
	}
	Sleep(2000);
	system("@cls||clear");

}
void choice_menu() {
	int i, j, flag = 0, m;
	for (i = 0; i < 59; i++) {
		if (i == 10 || i == 58) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 6; i++) {
		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |         Please Choose Operation Mod           |");
				flag = 1;
			}
			else if (i == 1 && flag < 2 && j >9) {

				for (m = 0; m < 59; m++) {
					if (m == 10 || m == 58) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 2;
			}
			else if (i == 2 && flag < 3 && j >9) {
				printf("          | 1 | Input Of Working Hours Of A Single Month  |");
				flag = 3;
			}
			else if (i == 3 && flag < 4 && j > 9) {
				for (m = 0; m < 59; m++) {
					if (m == 10 || m == 58) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 4;
			}
			else if (i == 4 && flag < 5 && j > 9) {
				printf("          | 2 | Input Of Working Hours Of A Single Month  |");
				flag = 5;
			}
			else if (i == 5 && flag < 6 && j > 9) {
				for (m = 0; m < 59; m++) {
					if (m == 10 || m == 58) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n");
	printf("                      [Your Choice is]:-  ");
}
void error_message() {
	printf("\n\n");
	int i, j, flag = 0, m;
	for (i = 0; i < 59; i++) {
		if (i == 10 || i == 58) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 6; i++) {
		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Invalid Input! Please Choose A Valid Input  |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < 59; m++) {
					if (m == 10 || m == 58) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
}
void error_message_2() {
	printf("\n\n");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD; i++) {
		if (i == Y_CORD || i == X_CORD - 1) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 6; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |            Unexpected Error In Creating File             |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD; m++) {
					if (m == 10 || m == X_CORD - 1) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
}
void exit_message() {
	system("@cls||clear");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD; i++) {
		if (i == Y_CORD || i == X_CORD - 1) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 6; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Program Terminated This Window Will Close In 3 Secondes|");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD; m++) {
					if (m == 10 || m == X_CORD) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	Sleep(3000);
}
void enter_month_display() {
	system("@cls||clear");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD-14; i++) {
		if (i == Y_CORD || i == X_CORD - 15) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 2; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Please Enter The Month Of Calculation    |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD-14; m++) {
					if (m == 10 || m == X_CORD-15) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n                    Month:- ");
}
void enter_year_display() {
	printf("\n\n");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD - 14; i++) {
		if (i == Y_CORD || i == X_CORD - 15) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 2; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Please Enter The Year Of Calculation      |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD - 14; m++) {
					if (m == 10 || m == X_CORD - 15) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n                     Year:- ");
}
void enter_h_salary_display() {
	system("@cls||clear");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD - 14; i++) {
		if (i == Y_CORD || i == X_CORD - 15) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 2; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Please Enter The Workers Hourly Salary   |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD - 14; m++) {
					if (m == 10 || m == X_CORD - 15) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n                 Hourly Salary:- ");
}
void enter_received_salary_display() {
	printf("\n\n");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD+2; i++) {
		if (i == Y_CORD || i == X_CORD +1) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 2; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |  Please Enter How Much Did The Worker Receive That Month   |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD +2; m++) {
					if (m == 10 || m == X_CORD +1) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n                Worker Received:- ");
}
void enter_workers_name_display() {
	printf("\n\n");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD + 20; i++) {
		if (i == Y_CORD || i == X_CORD + 19) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 2; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |   Please Enter The Name Of The Worker , The File Will Be Saved Accordingly   |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD + 20; m++) {
					if (m == 10 || m == X_CORD + 10) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	printf("\n                Worker's Name:- ");
}
void file_created_message() {
	system("@cls||clear");
	int i, j, flag = 0, m;
	for (i = 0; i < X_CORD + 12; i++) {
		if (i == Y_CORD || i == X_CORD + 11) {
			printf("+");
		}
		else if (i < 10) {
			printf(" ");
		}
		else {
			printf("=");
		}
	}
	for (i = 0; i < 6; i++) {

		printf("\n");
		for (j = 0; j < 59; j++) {
			if (i == 0 && flag < 1 && j >9) {
				printf("          |  File Was Successfully Created And Saved At Programs Exe Loacation   |");
				flag = 1;
			}
			else if (i == 1 && flag < 6 && j > 9) {
				for (m = 0; m < X_CORD + 12; m++) {
					if (m == 10 || m == X_CORD + 11) {
						printf("+");
					}
					else if (m < 10) {
						printf(" ");
					}
					else {
						printf("=");
					}
				}
				flag = 6;
			}
		}

	}
	Sleep(1500);
}
