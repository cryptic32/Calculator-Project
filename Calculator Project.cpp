#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "Header.h"
#include <stdio.h>
int main() {
	setlocale(LC_ALL, "");
	int choice;
	while (1) {
		printf("\nВыберите калькулятор\n");
		printf("1. Матричный калькулятор\n");
		printf("2. Калькулятор дробей\n");
		printf("3. Комбинаторика\n");
		printf("4. Многочлены\n");
		printf("5. Теория вероятности и мат. статистика\n");
		printf("6. Гр-ки функций\n");
		printf("0. Exit\n");
		printf("Ваш выбор: \n");
		scanf("%d", &choice);
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			matrixCalc();
			break;

		case 2:
			FractionCalc();
			break;
		case 3:
			combinatoricsCalculator();
			break;

		case 4:
			MnogoCalc();
			break;

		case 5:
			ProbabilityCalc();
		case 6:
			graph(); 

		default:
			break;
		}
	}
}
