#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int coef = 1, n, sign = 1, i;
double x, y, term = 0;

void t_sin(int i) {
	if (i == 1) {
		y = x;
		term = x;
	}
	else {
		term *= -1 * x * x / ((2 * i - 2) * (2 * i - 1));
		y += term;
	}
}

void t_cos(int i) {
	if (i == 1) {
		y = 1;
		term = 1;
	}
	else {
		term *= -1 * x * x / ((2 * i - 3) * (2 * i - 2));
		y += term;
	}
}

void t_exp(int i) {
	if (i == 1) {
		y = 1;
	}else {
		if (i == 2) {
			y = 1 + x;
			term = x;
		}else {
			term *= x / (i - 1);
			y += term;
		}
	}
}

void t_sqrt(int i) {
	if (i == 1) {
		y = 1;
	}
	else {
		if (i == 2) {
			y = 1 + x / 2;
			term = x / 2; 
		}
		else {
			term *= x * (0.5 - i + 2) / (i - 1);
			y += term;
		}
	}
}

void t_ln(int i) {
	if (i == 1) {
		y = x;	
		term = x;
	}
	else {
		term *= -1 * x;
		y += term / i;
	}
}


void main() {
	int mode = 0, choice = 0, next = 1, measure = 0;
	double aim, accuracy;
	double (*math) (double) = 0;	//count aim
	void (*teilor) (int) = 0;		//count y

	while (next) {
		system("cls");
		printf("Choose the function:\n");
		printf("1 sin\n");
		printf("2 cos\n");
		printf("3 exp\n");
		printf("4 sqrt(1+x)\n");
		printf("5 ln(1+x)\n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			teilor = t_sin;
			math = sin;
			break;
		case 2:
			teilor = t_cos;
			math = cos;
			break;
		case 3:
			teilor = t_exp;
			math = exp;
			break;
		case 4:
			teilor = t_sqrt;
			math = sqrt;
			break;
		case 5:
			teilor = t_ln;
			math = log;
			break;
		default:
			continue;
		}

		printf("\nEnter X = ");
		scanf_s("%lf", &x);

		switch (choice) {
		case 1:
		case 2:
			printf("\nRad (0) or deg (not 0)? ");
			scanf_s("%d", &measure);
			if (measure)
				x = x / 180 * M_PI;	//DEG TO RAD
			aim = math(x); 
			x = fmod(x, 2 * M_PI);
			break;
		case 4:
		case 5:
			if (x <= -1) {
				printf("\nWRONG ENTER\n");
				system("pause");
				continue;
			}
			aim = math(1 + x);
			break;
		default:
			aim = math(x);
		}

		printf("\nChoose mode (1, 2): ");
		scanf_s("%d", &mode);

		switch (mode) {
		case 1:
			printf("\nAccuracy (>=10^-6): ");
			scanf_s("%lf", &accuracy);
			printf("\nNumber of terms (1-1000): ");
			scanf_s("%d", &n);
			printf("\n");

			for (i = 1; i <= n; i++) {
				teilor(i);
				if (fabs(y - aim) <= accuracy)
					break;
			}
			if (i > n)
				i--;
			accuracy = fabs(y - aim);
			printf("\nAim: %lf", aim);
			printf("\nResult: %lf", y);
			printf("\nAccuracy: %lf", accuracy);
			printf("\nNumber of terms: %d", i);
			break;

		case 2:
			printf("\nNumber of experiments (1-25): ");
			scanf_s("%d", &n);
			printf("\nAim: %lf", aim);
			printf("\n N %11c Result %9c Accuracy", ' ', ' ');
			for (i = 1; i <= n; i++) {
				teilor(i);
				printf("\n%2d: %17.7lf  %17.7lf", i, y, fabs(y - aim));
			}
			break;
		}
		printf("\nContinue? (not 0): ");
		scanf_s("%d", &next);
	}
	system("pause");
}
