#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <SDL.h>
#include <malloc.h>
#include <math.h>	
#include "Header.h"
#include <iostream>
using namespace std;
	void PrintMatrix(float** matrix, int m, int n)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%5.2f ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	void SummaMatrices()
	{
		int m, n;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		float** matrix2 = (float**)malloc(sizeof(*matrix2) * m);
		float** result = (float**)malloc(sizeof(*result) * m);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
			matrix2[i] = (float*)malloc(sizeof(**matrix2) * n);
			result[i] = (float*)malloc(sizeof(**result) * n);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, n, m);
		printf("Введите элементы матрицы2:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix2[%d][%d] = ", i, j);
				scanf_s("%f", &matrix2[i][j]);
			}
		}
		PrintMatrix(matrix2, n, m);
		printf("\n\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		printf("результат:\n");
		PrintMatrix(result, n, m);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
			free(matrix2[i]);
			free(result[i]);
		}
		free(matrix1);
		free(matrix2);
		free(result);

	}
	void DeductMatrice()
	{
		int m, n;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		float** matrix2 = (float**)malloc(sizeof(*matrix2) * m);
		float** result = (float**)malloc(sizeof(*result) * m);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
			matrix2[i] = (float*)malloc(sizeof(**matrix2) * n);
			result[i] = (float*)malloc(sizeof(**result) * n);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, n, m);
		printf("Введите элементы матрицы2:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix2[%d][%d] = ", i, j);
				scanf_s("%f", &matrix2[i][j]);
			}
		}
		PrintMatrix(matrix2, n, m);
		printf("\n\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				result[i][j] = matrix1[i][j] - matrix2[i][j];
			}
		}
		printf("результат:\n");
		PrintMatrix(result, n, m);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
			free(matrix2[i]);
			free(result[i]);
		}
		free(matrix1);
		free(matrix2);
		free(result);
	}
	void MatrixMultiplication()
	{
		while (1) {
			int m, n, choice1 = 1, m1, n1;
			do {
				printf("\nВведите размер матриц:\n");
				printf("Количество строк матрицы 1 (m): ");
				scanf_s("%d", &m);
				printf("Количество столбцов матрицы 1 (n): ");
				scanf_s("%d", &n);
				printf("\n");
				printf("Количество строк матрицы 2 (m1): ");
				scanf_s("%d", &m1);
				printf("Количество столбцов матрицы 2 (n1): ");
				scanf_s("%d", &n1);
				if (n != m1) {
					printf("\nОперация умножения двух матриц выполнима только в том случае, если число столбцов в первом сомножителе равно числу строк во втором!\n");
					printf("1 - Ввести размеры заново\n2 - Выйти в меню\n");
					scanf_s("%d", &choice1);
					if (choice1 == 2) {
						break;
					}
				}
			} while (n != m1);
			if (choice1 == 2) { break; }
			if (choice1 == 2) {
				break;
			}
			float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
			float** matrix2 = (float**)malloc(sizeof(*matrix2) * m1);
			float** result = (float**)malloc(sizeof(*result) * m);
			for (int i = 0; i < m; i++) {
				matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
			}
			for (int i = 0; i < m1; i++) {
				matrix2[i] = (float*)malloc(sizeof(**matrix2) * n1);
			}
			for (int i = 0; i < m; i++) {
				result[i] = (float*)malloc(sizeof(**result) * n1);
			}
			printf("Введите элементы матрицы 1:\n");
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					printf("matrix1[%d][%d] = ", i, j);
					scanf_s("%f", &matrix1[i][j]);
				}
			}
			printf("Матрица 1:\n");
			PrintMatrix(matrix1, m, n);
			printf("Введите элементы матрицы 2:\n");
			for (int i = 0; i < m1; i++) {
				for (int j = 0; j < n1; j++) {
					printf("matrix2[%d][%d] = ", i, j);
					scanf_s("%f", &matrix2[i][j]);
				}
			}
			printf("Матрица 2:\n");
			PrintMatrix(matrix2, m1, n1);
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n1; j++) {
					result[i][j] = 0;
					for (int k = 0; k < n; k++) {
						result[i][j] += matrix1[i][k] * matrix2[k][j];
					}
				}
			}
			printf("\nРезультат умножения:\n");
			PrintMatrix(result, m, n1);
			for (int i = 0; i < m; i++) {
				free(matrix1[i]);
			}
			for (int i = 0; i < m1; i++) {
				free(matrix2[i]);
			}
			for (int i = 0; i < m; i++) {
				free(result[i]);
			}
			free(matrix1);
			free(matrix2);
			free(result);
			break;
		}
	}
	void MultiplyingMatricesbyaNumber()
	{
		int m, n;
		float chislo;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, m, n);
		printf("введите число\n");
		scanf_s("%f", &chislo);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix1[i][j] = matrix1[i][j] * chislo;
			}
		}
		printf("результат: \n");
		PrintMatrix(matrix1, m, n);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
		}
		free(matrix1);
	}
	void AddingAMatrixWithANumber()
	{
		int m, n;
		float chislo;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, m, n);
		printf("введите число\n");
		scanf_s("%f", &chislo);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix1[i][j] = matrix1[i][j] + chislo;
			}
		}
		printf("результат: \n");
		PrintMatrix(matrix1, m, n);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
		}
		free(matrix1);
	}
	void SubtractingNumbersFromTheMatrix()
	{
		int m, n;
		float chislo;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, m, n);
		printf("введите число\n");
		scanf_s("%f", &chislo);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				matrix1[i][j] = matrix1[i][j] - chislo;
			}
		}
		printf("результат: \n");
		PrintMatrix(matrix1, m, n);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
		}
		free(matrix1);
	}
	void MatrixTransposition()
	{
		int m, n;
		printf("\nвведите размер матриц\n");
		printf("кол-во строк(m): ");
		scanf_s("%d", &m);
		printf("кол-во столбцов(n): ");
		scanf_s("%d", &n);
		float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
		float** result = (float**)malloc(sizeof(*result) * n);
		for (int i = 0; i < m; i++) {
			matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
		}
		for (int i = 0; i < n; i++) {
			result[i] = (float*)malloc(sizeof(**result) * m);
		}
		printf("Введите элементы матрицы1:\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("matrix1[%d][%d] = ", i, j);
				scanf_s("%f", &matrix1[i][j]);
			}
		}
		PrintMatrix(matrix1, m, n);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) {
				result[j][i] = matrix1[i][j];
			}
		}
		printf("результат: \n");
		PrintMatrix(result, n, m);
		for (int i = 0; i < m; i++) {
			free(matrix1[i]);
		}
		for (int i = 0; i < n; i++) {
			free(result[i]);
		}
		free(matrix1);
		free(result);
	}
	void InverseMatrix()
	{
		while (1) {
			int m, n, chislo = 0;
			printf("\nвведите размер матриц\n");
			do {
				printf("кол-во строк(m): ");
				scanf_s("%d", &m);
				printf("кол-во столбцов(n): ");
				scanf_s("%d", &n);
				if (m != n) {
					printf("\nопределитель матрицы можно найти только у квадратной матрицы, т.е. m = n\n");
					do {
						printf("1 - ввести размеры заного\n2 - выйти\n");
						printf("ваш выбор: ");
						scanf_s("%d", &chislo);
						if (chislo == 2) { break; }
					} while (chislo > 2 || chislo < 1);
					if (chislo == 2) {
						break;
					}
				}
				if ((m > 3 && n > 3) || (m < 1 && n < 1)) {
					printf("\nэто калькулятор в котором можно посчитать определитель только матриц 1-го, 2-го или 3 - го порядка.\nвведите размер еще раз!\n");
				}
			} while (m != n || (m > 3 && n > 3) || (m < 1 && n < 1));
			if (chislo == 2) { break; }
			float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
			for (int i = 0; i < m; i++) {
				matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
			}
			printf("Введите элементы матрицы1:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("matrix1[%d][%d] = ", i, j);
					scanf_s("%f", &matrix1[i][j]);
				}
			}
			PrintMatrix(matrix1, m, n);
			if (m == 1 && n == 1)
			{
				if (matrix1[0][0] == 0) {
					printf("\nМатрица не является обратимой!\n");
				}
				else {
					float inverse = 1 / matrix1[0][0];
					printf("\nОбратная матрица:\n");
					printf("%5.2f\n", inverse);
				}
			}
			if (m == 2 && n == 2)
			{
				int determinant = matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
				if (determinant == 0) {
					printf("\nМатрица не является обратимой!\n");
				}
				float** inverse = (float**)malloc(sizeof(*inverse) * m);
				for (int i = 0; i < n; i++) {
					inverse[i] = (float*)malloc(sizeof(**inverse) * n);
				}
				inverse[0][0] = matrix1[1][1] / determinant;
				inverse[0][1] = -matrix1[0][1] / determinant;
				inverse[1][0] = -matrix1[1][0] / determinant;
				inverse[1][1] = matrix1[0][0] / determinant;
				printf("\nрезультат: \n");
				PrintMatrix(inverse, m, n);
			}
			if (m == 3 && n == 3)
			{
				float determinant = matrix1[0][0] * matrix1[1][1] * matrix1[2][2] + matrix1[0][1] * matrix1[1][2] * matrix1[2][0] + matrix1[0][2] * matrix1[1][0] * matrix1[2][1] - matrix1[0][2] * matrix1[1][1] * matrix1[2][0] - matrix1[0][1] * matrix1[1][0] * matrix1[2][2] - matrix1[0][0] * matrix1[1][2] * matrix1[2][1];
				if (determinant == 0) {
					printf("\nМатрица не является обратимой!\n");
					return;
				}
				float** inverse = (float**)malloc(sizeof(*inverse) * m);
				for (int i = 0; i < n; i++) {
					inverse[i] = (float*)malloc(sizeof(*inverse) * n);
				}
				inverse[0][0] = (matrix1[1][1] * matrix1[2][2] - matrix1[1][2] * matrix1[2][1]) / determinant;
				inverse[0][1] = (matrix1[0][2] * matrix1[2][1] - matrix1[0][1] * matrix1[2][2]) / determinant;
				inverse[0][2] = (matrix1[0][1] * matrix1[1][2] - matrix1[0][2] * matrix1[1][1]) / determinant;
				inverse[1][0] = (matrix1[1][2] * matrix1[2][0] - matrix1[1][0] * matrix1[2][2]) / determinant;
				inverse[1][1] = (matrix1[0][0] * matrix1[2][2] - matrix1[0][2] * matrix1[2][0]) / determinant;
				inverse[1][2] = (matrix1[0][2] * matrix1[1][0] - matrix1[0][0] * matrix1[1][2]) / determinant;
				inverse[2][0] = (matrix1[1][0] * matrix1[2][1] - matrix1[1][1] * matrix1[2][0]) / determinant;
				inverse[2][1] = (matrix1[0][1] * matrix1[2][0] - matrix1[0][0] * matrix1[2][1]) / determinant;
				inverse[2][2] = (matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0]) / determinant;
				printf("\nОбратная матрица:\n");
				PrintMatrix(inverse, m, n);
			}
			break;
		}

	}
	void DeterminantOfTheMatrix()
	{
		while (1) {
			int m, n, chislo = 0;
			printf("\nвведите размер матриц\n");
			do {
				printf("кол-во строк(m): ");
				scanf_s("%d", &m);
				printf("кол-во столбцов(n): ");
				scanf_s("%d", &n);
				if (m != n) {
					printf("\nопределитель матрицы можно найти только у квадратной матрицы, т.е. m = n\n");
					do {
						printf("1 - ввести размеры заного\n2 - выйти\n");
						printf("ваш выбор: ");
						scanf_s("%d", &chislo);
					} while (chislo > 2 || chislo < 1);
					if (chislo == 2) {
						break;
					}
				}
				if ((m > 3 && n > 3) || (m < 1 && n < 1)) {
					printf("\nэто калькулятор в котором можно посчитать определитель только матриц 1-го, 2-го или 3 - го порядка.\nвведите размер еще раз!\n");
				}
			} while (m != n || (m > 3 && n > 3) || (m < 1 && n < 1));
			if (chislo == 2) {
				break;
			}
			float** matrix1 = (float**)malloc(sizeof(*matrix1) * m);
			for (int i = 0; i < m; i++) {
				matrix1[i] = (float*)malloc(sizeof(**matrix1) * n);
			}
			printf("Введите элементы матрицы1:\n");
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("matrix1[%d][%d] = ", i, j);
					scanf_s("%f", &matrix1[i][j]);
				}
			}
			PrintMatrix(matrix1, m, n);
			if (n == 1 && m == 1) {
				float determinant = matrix1[0][0];
				printf("\nОпределитель матрицы: %f\n", determinant);
			}
			if (n == 2 && m == 2) {
				float determinant = matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
				printf("\nОпределитель матрицы: %f\n", determinant);
			}
			if (m == 3 && n == 3) {
				float determinant = matrix1[0][0] * matrix1[1][1] * matrix1[2][2] + matrix1[0][1] * matrix1[1][2] * matrix1[2][0] + matrix1[0][2] * matrix1[1][0] * matrix1[2][1] - matrix1[0][2] * matrix1[1][1] * matrix1[2][0] - matrix1[0][1] * matrix1[1][0] * matrix1[2][2] - matrix1[0][0] * matrix1[1][2] * matrix1[2][1];
				printf("\nОпределитель матрицы: %f\n", determinant);
			}
			break;
		}
	}
	void matrixCalc()
	{
		while (1) {
			int choice;
			setlocale(LC_ALL, "");
			printf("\nКАЛЬКУЛЯТОР МАТРИЦ\n");
			printf("1 - сложение матриц\n");
			printf("2 - вычитание матриц\n");
			printf("3 - умножение матриц\n");
			printf("4 - умножение матрицы на число\n");
			printf("5 - сложение матрицы с числом\n");
			printf("6 - вычитание из матрицы числа\n");
			printf("7 - транспонирование матрицы\n");
			printf("8 - обратная матрица(2-го,3-го порядка)\n");
			printf("9 - определитель(2-го,3-го порядка)\n");
			printf("0 - выйти\n");
			printf("ваш выбор: ");
			scanf_s("%d", &choice);
			if (choice == 0) { break; }
			switch (choice)
			{
			case 1:
				SummaMatrices();
				break;
			case 2:
				DeductMatrice();
				break;
			case 3:
				MatrixMultiplication();
				break;
			case 4:
				MultiplyingMatricesbyaNumber();
				break;
			case 5:
				AddingAMatrixWithANumber();
				break;
			case 6:
				SubtractingNumbersFromTheMatrix();
				break;
			case 7:
				MatrixTransposition();
				break;
			case 8:
				InverseMatrix();
				break;
			case 9:
				DeterminantOfTheMatrix();
				break;

			default:
				break;
			}
		}
	}




	typedef struct {
		int numerator;
		int denominator;
	} Fraction;

	
	int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	
	void simplifyFraction(Fraction* fraction) {
		int gcdValue = gcd(fraction->numerator, fraction->denominator);
		fraction->numerator /= gcdValue;
		fraction->denominator /= gcdValue;
	}

	
	Fraction addFractions(Fraction f1, Fraction f2) {
		Fraction result;
		result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		result.denominator = f1.denominator * f2.denominator;
		simplifyFraction(&result);
		return result;
	}

	
	Fraction subtractFractions(Fraction f1, Fraction f2) {
		Fraction result;
		result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		result.denominator = f1.denominator * f2.denominator;
		simplifyFraction(&result);
		return result;
	}

	
	Fraction multiplyFractions(Fraction f1, Fraction f2) {
		Fraction result;
		result.numerator = f1.numerator * f2.numerator;
		result.denominator = f1.denominator * f2.denominator;
		simplifyFraction(&result);
		return result;
	}

	
	Fraction divideFractions(Fraction f1, Fraction f2) {
		Fraction result;
		result.numerator = f1.numerator * f2.denominator;
		result.denominator = f1.denominator * f2.numerator;
		simplifyFraction(&result);
		return result;
	}

	
	int compareFractions(Fraction f1, Fraction f2) {
		int numerator1 = f1.numerator * f2.denominator;
		int numerator2 = f2.numerator * f1.denominator;
		if (numerator1 == numerator2)
			return 0;
		else if (numerator1 > numerator2)
			return 1;
		else
			return -1;
	}

	
	float fractionToDecimal(Fraction fraction) {
		return (float)fraction.numerator / fraction.denominator;
	}

	void FractionCalc() {
		Fraction f1, f2;
		int choice;
		while (1) {

			printf("\nВыберите операцию:\n");
			printf("1. Сложение\n");
			printf("2. Вычитание\n");
			printf("3. Умножение\n");
			printf("4. Деление\n");
			printf("5. Сравнение\n");
			printf("6. Сокращение\n");
			printf("7. Представление в виде десятичной дроби\n");
			printf("0. Exit\n");
			printf("Введите номер операции: ");
			scanf("%d", &choice);


			Fraction result;
			if(choice == 0) break;
			printf("Введите первую дробь (числитель знаменатель): ");
			scanf("%d %d", &f1.numerator, &f1.denominator);

			printf("Введите вторую дробь (числитель знаменатель): ");
			scanf("%d %d", &f2.numerator, &f2.denominator);
			switch (choice) {
			case 1:
				result = addFractions(f1, f2);
				printf("Сумма дробей: %d/%d\n", result.numerator, result.denominator);
				break;
			case 2:
				result = subtractFractions(f1, f2);
				printf("Разность дробей: %d/%d\n", result.numerator, result.denominator);
				break;
			case 3:
				result = multiplyFractions(f1, f2);
				printf("Произведение дробей: %d/%d\n", result.numerator, result.denominator);
				break;
			case 4:
				result = divideFractions(f1, f2);
				printf("Частное дробей: %d/%d\n", result.numerator, result.denominator);
				break;
			case 5:
				if (compareFractions(f1, f2) == 0)
					printf("Дроби равны\n");
				else if (compareFractions(f1, f2) > 0)

					printf("Первая дробь больше второй\n");
				else
					printf("Вторая дробь больше первой\n");
				break;
			case 6:
				simplifyFraction(&f1);
				printf("Первая дробь после сокращения: %d/%d\n", f1.numerator, f1.denominator);

				simplifyFraction(&f2);
				printf("Вторая дробь после сокращения: %d/%d\n", f2.numerator, f2.denominator);
				break;
			case 7:
				printf("Десятичная запись первой дроби: %.2f\n", fractionToDecimal(f1));
				printf("Десятичная запись второй дроби: %.2f\n", fractionToDecimal(f2));
				break;
			default:
				printf("Ошибка! Некорректный ввод.\n");
			}
		}
		
	}

	int factorial(int n) {
		int result = 1;
		for (int i = 2; i <= n; i++) {
			result *= i;
		}
		return result;
	}

	void combinatoricsCalculator() {
		int choice;
		int n, k;
		while (1) {
			printf("=== Калькулятор комбинаторики ===\n");
			printf("Выберите действие:\n");
			printf("1. Размещение с повторениями\n");
			printf("2. Размещение без повторений\n");
			printf("3. Сочетание с повторениями\n");
			printf("4. Сочетание без повторений\n");
			printf("5. Перестановки\n");
			printf("0. Exit\n");
			scanf("%d", &choice);
			if (choice == 0) break;
			switch (choice) {
			case 1:
				printf("Введите n и k через пробел: ");
				scanf("%d %d", &n, &k);
				if (n < 0 || k < 0) {
					printf("Неверные значения! n и k должны быть положительными целыми числами.\n");
				}
				else {
					printf("Результат: %.0f\n", pow(n, k));
				}
				break;
			case 2:
				printf("Введите n и k через пробел: ");
				scanf("%d %d", &n, &k);
				if (n < 0 || k < 0) {
					printf("Неверные значения! n и k должны быть положительными целыми числами.\n");
				}
				else {
					printf("Результат: %d\n", factorial(n) / factorial(n - k));
				}
				break;
			case 3:
				printf("Введите n и k через пробел: ");
				scanf("%d %d", &n, &k);
				if (n < 0 || k < 0) {
					printf("Неверные значения! n и k должны быть положительными целыми числами.\n");
				}
				else {
					int result = 1;
					result *= factorial(n + k - 1);
					result /= (factorial(k) * factorial(n - 1));
					printf("Результат: %d\n", result);
				}
				break;
			case 4:
				printf("Введите n и k через пробел: ");
				scanf("%d %d", &n, &k);
				if (n < 0 || k < 0) {
					printf("Неверные значения! n и k должны быть положительными целыми числами.\n");
				}
				else {
					int result = 1;
					result *= factorial(n);
					result /= (factorial(k) * factorial(n - k));
					printf("Результат: %d\n", result);
				}
				break;
			case 5:
				printf("Введите n: ");
				scanf("%d", &n);
				if (n < 0) {
					printf("Неверное значение! n должно быть положительным целым числом.\n");
				}
				else {
					int result = factorial(n);
					printf("Результат: %d\n", result);
				}
				break;
			default:
				printf("Неверный выбор!\n");
				break;
			}
		}
	}

	void subtractPolynomials(float* poly1, int degree1, float* poly2, int degree2, float* result) {
		int diffDegree = degree1;
		if (degree2 > diffDegree) {
			diffDegree = degree2;
		} 

		for (int i = 0; i <= diffDegree; i++) {
			if (i <= degree1) {
				result[i] += poly1[i];
			}
			if (i <= degree2) {
				result[i] -= poly2[i];
			}
		}
	}
	void addPolynomials(float* poly1, int degree1, float* poly2, int degree2, float* result) {
		int sumDegree = degree1; 
		if (degree2 > degree1) {
			sumDegree = degree2; 
		}

		for (int i = 0; i <= sumDegree; i++) {
			if (i <= degree1) {
				result[i] += poly1[i];
			}
			if (i <= degree2) {
				result[i] += poly2[i];
			}
		}
	}
	void multiplyPolynomials(float* poly1, int degree1, float* poly2, int degree2, float* result) {
		int productDegree = degree1 + degree2;

		
		for (int i = 0; i <= productDegree; i++) {
			result[i] = 0.0;
		}

		for (int i = 0; i <= degree1; i++) {
			for (int j = 0; j <= degree2; j++) {
				int resultDegree = i + j;  
				result[productDegree - resultDegree] += poly1[i] * poly2[j];  
			}
		}
	}


	void multiplyPolynomialByNumber(float* poly, int degree, float number) {
		for (int i = 0; i <= degree; i++) {
			poly[i] *= number;
		}
	}
	void differentiatePolynomial(float* poly, int degree) {
		for (int i = 1; i <= degree; i++) {
			poly[i - 1] = i * poly[i];
		}
		poly[degree] = 0;  
	}
	void dividePolynomials(float* dividend, int degreeDividend, float* divisor, int degreeDivisor, float* quotient, int* degreeQuotient, float* remainder, int* degreeRemainder) {
		*degreeQuotient = degreeDividend - degreeDivisor;

		for (int i = degreeDividend; i >= degreeDivisor; i--) {
			float factor = dividend[i] / divisor[degreeDivisor];
			quotient[i - degreeDivisor] = factor;

			for (int j = degreeDivisor; j >= 0; j--) {
				dividend[i - degreeDivisor + j] -= factor * divisor[j];
			}
		}

		*degreeRemainder = degreeDivisor - 1;
		for (int i = 0; i <= *degreeRemainder; i++) {
			remainder[i] = dividend[i];
		}
	}
	void task1() {
		float* poly1;
		float* poly2;
		float* result;
		int degree1 = 0;
		int degree2 = 0;

		printf("\nВведите степень первого многочлена: ");
		scanf_s("%d", &degree1);
		poly1 = (float*)malloc(sizeof(*poly1) * (degree1 + 1));
		printf("Введите коэффициенты первого многочлена:\n");
		for (int i = 0; i <= degree1; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly1[i]);
		}

		printf("\nВведите степень второго многочлена: ");
		scanf_s("%d", &degree2);
		poly2 = (float*)malloc(sizeof(*poly2) * (degree2 + 1));
		printf("Введите коэффициенты второго многочлена:\n");
		for (int i = 0; i <= degree2; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly2[i]);
		}

		int sumDegree = degree1;
		if (degree2 > degree1) {
			sumDegree = degree2;
		}
		result = (float*)malloc(sizeof(*result) * (sumDegree + 1));


		for (int i = 0; i <= sumDegree; i++) {
			result[i] = 0.0;
		}

		addPolynomials(poly1, degree1, poly2, degree2, result);

		printf("\nРезультат сложения многочленов:\n");
		for (int i = 0; i <= sumDegree; i++) {
			printf("%.2f * x^%d", result[i], i);
			if (i < sumDegree) {
				printf(" + ");
			}
		}
		printf("\n");

		free(poly1);
		free(poly2);
		free(result);
	}
	void task2() {
		float* poly1;
		float* poly2;
		float* result;
		int degree1 = 0;
		int degree2 = 0;

		printf("\nВведите степень первого многочлена: ");
		scanf_s("%d", &degree1);
		poly1 = (float*)malloc(sizeof(*poly1) * (degree1 + 1));
		printf("Введите коэффициенты первого многочлена:\n");
		for (int i = 0; i <= degree1; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly1[i]);
		}

		printf("\nВведите степень второго многочлена: ");
		scanf_s("%d", &degree2);
		poly2 = (float*)malloc(sizeof(*poly2) * (degree2 + 1));
		printf("Введите коэффициенты второго многочлена:\n");
		for (int i = 0; i <= degree2; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly2[i]);
		}

		int diffDegree = degree1;
		if (degree2 > diffDegree) {
			diffDegree = degree2;
		}
		result = (float*)malloc(sizeof(*result) * (diffDegree + 1));

		for (int i = 0; i <= diffDegree; i++) {
			result[i] = 0.0;
		}

		subtractPolynomials(poly1, degree1, poly2, degree2, result);

		printf("\nРезультат вычитания многочленов:\n");
		for (int i = 0; i <= diffDegree; i++) {
			printf("%.2f * x^%d", result[i], i);
			if (i < diffDegree) {
				printf(" + ");
			}
		}
		printf("\n");

		free(poly1);
		free(poly2);
		free(result);
	}
	void task3() {
		float* poly1;
		float* poly2;
		float* result;
		int degree1 = 0;
		int degree2 = 0;

		printf("\nВведите степень первого многочлена: ");
		while (scanf_s("%d", &degree1) != 1 || degree1 < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		poly1 = (float*)malloc(sizeof(float) * (degree1 + 1));

		printf("Введите коэффициенты первого многочлена:\n");
		for (int i = 0; i <= degree1; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly1[i]);
		}

		printf("\nВведите степень второго многочлена: ");
		while (scanf_s("%d", &degree2) != 1 || degree2 < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		poly2 = (float*)malloc(sizeof(float) * (degree2 + 1));

		printf("Введите коэффициенты второго многочлена:\n");
		for (int i = 0; i <= degree2; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly2[i]);
		}

		int productDegree = degree1 + degree2;
		result = (float*)malloc(sizeof(float) * (productDegree + 1));

		
		for (int i = 0; i <= productDegree; i++) {
			result[i] = 0.0;
		}

		multiplyPolynomials(poly1, degree1, poly2, degree2, result);

		printf("\nРезультат умножения многочленов:\n");
		for (int i = productDegree; i >= 0; i--) {
			printf("%.2f * x^%d", result[i], i);
			if (i > 0) {
				printf(" + ");
			}
		}
		printf("\n");

		free(poly1);
		free(poly2);
		free(result);
	}

	void task4() {
		float* poly;
		int degree = 0;
		float number = 0;

		printf("\nВведите степень многочлена: ");
		while (scanf_s("%d", &degree) != 1 || degree < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		poly = (float*)malloc(sizeof(float) * (degree + 1));

		printf("Введите коэффициенты многочлена:\n");
		for (int i = 0; i <= degree; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly[i]);
		}

		printf("Введите число для умножения: ");
		scanf_s("%f", &number);

		multiplyPolynomialByNumber(poly, degree, number);

		printf("\nРезультат умножения многочлена на число:\n");
		for (int i = degree; i >= 0; i--) {
			printf("%.2f * x^%d", poly[i], i);
			if (i > 0) {
				printf(" + ");
			}
		}
		printf("\n");

		free(poly);
	}

	void task5() {
		float* poly;
		int degree = 0;

		printf("\nВведите степень многочлена: ");
		while (scanf_s("%d", &degree) != 1 || degree < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		poly = (float*)malloc(sizeof(float) * (degree + 1));

		printf("Введите коэффициенты многочлена:\n");
		for (int i = 0; i <= degree; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &poly[i]);
		}

		differentiatePolynomial(poly, degree);

		printf("\nРезультат вычисления производной от многочлена:\n");
		for (int i = degree - 1; i >= 0; i--) {
			printf("%.2f * x^%d", poly[i], i);
			if (i > 0) {
				printf(" + ");
			}
		}
		printf("\n");

		free(poly);
	}

	void task6() {
		float* dividend;
		float* divisor;
		float* quotient;
		float* remainder;
		int degreeDividend = 0;
		int degreeDivisor = 0;
		int degreeQuotient = 0;
		int degreeRemainder = 0;

		printf("\nВведите степень делимого многочлена: ");
		while (scanf_s("%d", &degreeDividend) != 1 || degreeDividend < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		dividend = (float*)malloc(sizeof(float) * (degreeDividend + 1));

		printf("Введите коэффициенты делимого многочлена:\n");
		for (int i = 0; i <= degreeDividend; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &dividend[i]);
		}

		printf("\nВведите степень делителя: ");
		while (scanf_s("%d", &degreeDivisor) != 1 || degreeDivisor < 0) {
			printf("Ошибка ввода. Введите целое неотрицательное число: ");
			while (getchar() != '\n'); 
		}

		divisor = (float*)malloc(sizeof(float) * (degreeDivisor + 1));

		printf("Введите коэффициенты делителя:\n");
		for (int i = 0; i <= degreeDivisor; i++) {
			printf("Коэффициент для x^%d: ", i);
			scanf_s("%f", &divisor[i]);
		}

		quotient = (float*)malloc(sizeof(float) * (degreeDividend - degreeDivisor + 1));
		remainder = (float*)malloc(sizeof(float) * (degreeDivisor));

		dividePolynomials(dividend, degreeDividend, divisor, degreeDivisor, quotient, &degreeQuotient, remainder, &degreeRemainder);

		printf("\nРезультат деления многочленов:\n");
		printf("Частное:\n");
		for (int i = degreeQuotient; i >= 0; i--) {
			printf("%.2f * x^%d", quotient[i], i);
			if (i > 0) {
				printf(" + ");
			}
		}
		printf("\n");
		printf("Остаток:\n");
		for (int i = degreeRemainder - 1; i >= 0; i--) {
			printf("%.2f * x^%d", remainder[i], i);
			if (i > 0) {
				printf(" + ");
			}
		}
		printf("\n");

		free(dividend);
		free(divisor);
		free(quotient);
		free(remainder);
	}

	int getUserChoice() {
		int choice = 0;
		printf("\nВыберите задание:\n");
		printf("1. Сложение многочленов\n");
		printf("2. Вычитание многочленов\n");
		printf("3. Умножение многочленов\n");
		printf("4. Умножение многочлена на число\n");
		printf("5. Вычисление производной многочлена\n");
		printf("6. Деление многочленов\n");
		printf("0. Выход\n");

		while (scanf_s("%d", &choice) != 1 || choice < 0 || choice > 6) {
			printf("Ошибка ввода. Введите число от 0 до 6: ");
			while (getchar() != '\n'); 
		}

		return choice;
	}

	void MnogoCalc() {
		setlocale(LC_ALL, "Russian");

		int choice = -1;
		while (choice != 0) {
			choice = getUserChoice();

			switch (choice) {
			case 0:
				printf("Выход из программы.\n");
				break;
			case 1:
				task1();
				break;
			case 2:
				task2();
				break;
			case 3:
				task3();
				break;
			case 4:
				task4();
				break;
			case 5:
				task5();
				break;
			case 6:
				task6();
				break;
			default:
				printf("Некорректный выбор. Попробуйте снова.\n");
				break;
			}
		}
	}

	double calculateProbability(int m, int n) {
		return (double)m / (double)n;
	}

	double calculateVariance(int values[], int size, double mean) {
		double variance = 0.0;
		for (int i = 0; i < size; i++) {
			variance += pow((values[i] - mean), 2);
		}
		return variance / size;
	}

	double calculateMean(int values[], int size) {
		double sum = 0.0;
		for (int i = 0; i < size; i++) {
			sum += values[i];
		}
		return sum / size;
	}

	void ProbabilityCalc() {
		int choice;
		int m, n;
		int values[100];
		int size;
		double mean, variance;

		do {
			std::cout << "Выберите операцию:" << std::endl;
			std::cout << "1. Вычислить вероятность m/n" << std::endl;
			std::cout << "2. Вычислить дисперсию для дискретного распределения величин" << std::endl;
			std::cout << "3. Вычислить математическое ожидание для дискретного распределения величин" << std::endl;
			std::cout << "4. Выйти" << std::endl;
			std::cout << "Ваш выбор: ";
			std::cin >> choice;

			switch (choice) {
			case 1:
				std::cout << "Введите значения для m и n: ";
				std::cin >> m >> n;
				std::cout << "Вероятность m/n равна: " << calculateProbability(m, n) << std::endl;
				break;
			case 2:
				std::cout << "Введите количество значений: ";
				std::cin >> size;
				std::cout << "Введите значения через пробел: ";
				for (int i = 0; i < size; i++) {
					std::cin >> values[i];
				}
				mean = calculateMean(values, size);
				variance = calculateVariance(values, size, mean);
				std::cout << "Дисперсия равна: " << variance << std::endl;
				break;
			case 3:
				std::cout << "Введите количество значений: ";
				std::cin >> size;
				std::cout << "Введите значения через пробел: ";
				for (int i = 0; i < size; i++) {
					std::cin >> values[i];
				}
				mean = calculateMean(values, size);
				std::cout << "Математическое ожидание равно: " << mean << std::endl;
				break;
			case 4:
				std::cout << "Программа завершена." << std::endl;
				break;
			default:
				std::cout << "Неверный выбор. Повторите попытку." << std::endl;
				break;
			}
		} while (choice != 4);

		
	}
	struct ans {
		double a;
		double b;
		double c;
		double d;
		double a1[100];
		double n;
		int type;
	};
	double Polinom1(double n, double a[100], double x) {
		double result = 0;
		for (int i1 = 0; i1 <= n; i1++) {
			result += a[i1] * pow(x, i1);
		}
		return result;
	}
	double Power1(double a, double b, double c, double x) {
		return a * pow(a, b) + c;
	}
	double Exp(double a, double  b, double  c, double  d, double  x) {
		return a * pow(b, c * x) + d;
	}
	double Log(double a, double b, double c, double x) {
		return a * log(b * x) + c;
	}
	double Sin(double a, double  b, double  c, double  d, double  x) {
		return a * sin(b * x + c) + d;
	}
	double Cos(double a, double  b, double  c, double  d, double  x) {
		return a * cos(b * x + c) + d;
	}
	ans Enter_Func() {
		int fun;
		printf("Enter your type of function: \n 1.Polynom\n2.Power\n3.Exponential Function\n 4.Log function \n5.Sin Function\n6.Cos Function"), scanf_s("%d", &fun);
		double a = 0, b = 0, c = 0, d = 0, n = 0;

		ans answer;
		answer.n = 0;
		switch (fun) {
		case 1: {
			int n;
			printf("Enter n: "), scanf_s("%d", &n);
			double aa[100], a1;
			for (int i1 = 0; i1 <= n; i1++) {
				printf("Enter a[%d]:", i1), scanf_s("%lf", &a1);
				aa[i1] = a1;
				answer.a1[i1] = aa[i1];
			}
			answer.a = 0;
			answer.b = 0;
			answer.c = 0;
			answer.d = 0;
			answer.n = n;
			answer.type = 1;
			break;
		}
		case 2: {

			printf_s("For a*x^b +c: Enter a, b, c: "), scanf_s("%lf %lf %lf ", &a, &b, &c);
			answer.a = a;
			answer.b = b;
			answer.c = c;
			answer.d = 0;
			answer.type = 2;
			break;
		}
		case 3: {

			printf_s("For a*b^(c*x)+d: Enter a, b, c, d: "), scanf_s("%lf %lf %lf %lf", &a, &b, &c, &d);
			answer.a = a;
			answer.b = b;
			answer.c = c;
			answer.d = d;
			answer.type = 3;
			break;
		}
		case 4: {

			printf_s("For a*ln(b*x)+c: Enter a, b, c: "), scanf_s("%lf %lf %lf ", &a, &b, &c);
			answer.a = a;
			answer.b = b;
			answer.c = c;
			answer.d = 0;
			answer.type = 4;
			break;
		}
		case 5: {

			printf_s("For a*sin(b*x+c)+d: Enter a, b, c, d: "), scanf_s("%lf %lf %lf %lf", &a, &b, &c, &d);
			answer.a = a;
			answer.b = b;
			answer.c = c;
			answer.d = d;
			answer.type = 5;
			break;
		}
		case 6: {

			printf_s("For a*cos(b*x+c)+d: Enter a, b, c, d: "), scanf_s("%lf %lf %lf %lf", &a, &b, &c, &d);
			answer.a = a;
			answer.b = b;
			answer.c = c;
			answer.d = d;
			answer.type = 6;
			break;
		}
		}
		return answer;
	}
	double f(ans answer, double x) {
		switch (answer.type) {
		case 1: {

			return Polinom1(answer.n, answer.a1, x); break;
		}
		case 2: {
			return Power1(answer.a, answer.b, answer.c, x); break;
		}
		case 3: {
			return Exp(answer.a, answer.b, answer.c, answer.d, x); break;
		}
		case 4: {
			//answer = Enter_Func();
			return Log(answer.a, answer.b, answer.c, x); break;
		}
		case 5: {
			return Sin(answer.a, answer.b, answer.c, answer.d, x); break;
		}
		case 6: {
			return Cos(answer.a, answer.b, answer.c, answer.d, x); break;
		}
		default: return 0; break;
		}
	}
	void Extremum(ans answer) {
		double a, b, max = -1000000, min = 9999;
		double max_poi = 0, min_poi = 0;
		printf("Enter a, b: ");
		scanf_s("%lf %lf", &a, &b);
		for (double i = a; i <= b; i += 0.01) {
			double value = f(answer, i);
			if (value > max) {
				max = value;
				max_poi = i;
			}
			if (value < min) {
				min = value;
				min_poi = i;
			}
		}

		printf_s("Max point = (%lf, %lf)\n", max_poi, max);
		printf_s("Min point = (%lf, %lf)\n", min_poi, min);
	}
	void Yzero(ans answer) {
		double a, b, c;
		printf("Enter a, b"), scanf_s("%lf %lf ", &a, &b);
		while (abs(b - a) > 0.01) {
			c = (a + b) / 2;
			if (f(answer, c) == 0) {
				break;
			}
			else {
				if (f(answer, c) * f(answer, a) < 0) {
					b = c;
				}

				else {
					a = c;
				}

			}
		}

		printf_s("Function = 0 in x = %lf", (a + b) / 2);

	}
	void Def_Integral(ans answer) {
		double a, b;
		printf_s("Enter a, b"), scanf_s("%lf %lf ", &a, &b);
		double h = (b - a) / 100.0;
		double integral = (f(answer, a) + f(answer, b)) / 2.0;

		for (int i = 1; i < 100; i++) {
			double x = a + i * h;
			integral += f(answer, x);
		}

		integral *= h;

		printf_s("integral = %lf", integral);
	}

	/*void SDL_graphic(ans answer) { не знаю почему не работает ((((((
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_Surface* screenSurface = NULL;
		const int SCREEN_SIZE = 1000;
		SDL_Window* window = SDL_CreateWindow("Func", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_SIZE, SCREEN_SIZE, SDL_WINDOW_SHOWN);
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

		if (window == NULL)
		{
			printf_s("Fail( SDL_Error: %s\n", SDL_GetError());

		}
		else
		{



			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 250, 250, 250));
			double x, y;//4.  Y=Acos(x)+b, [-10;10]
			double x_old, y_old;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
			SDL_RenderDrawLine(renderer, 300, 0, 300, SCREEN_SIZE);
			SDL_RenderDrawLine(renderer, 0, 300, SCREEN_SIZE, 300);
			for (int i = 0; i < SCREEN_SIZE; i = i + 30) {
				SDL_RenderDrawLine(renderer, SCREEN_SIZE / 2 - 5, i, SCREEN_SIZE / 2 + 5, i);
			}
			for (int i = 0; i < SCREEN_SIZE; i = i + 30) {
				SDL_RenderDrawLine(renderer, i, SCREEN_SIZE / 2 - 5, i, SCREEN_SIZE / 2 + 5);
			}
			for (double i = 0; i < SCREEN_SIZE; i++) {
				if (i == 0) {
					x_old = i / 10.0 - 10.0;
					y_old = (f(answer, x_old)) * 10.0;
				}
				else {
					x = i;
					y = SCREEN_SIZE / 2 - ((f(answer, x_old)) * 10.0);
					SDL_RenderDrawLine(renderer, (int)x_old, (int)y_old, (int)x, (int)y);
					x_old = x;
					y_old = y;

				}

			}


			SDL_RenderPresent(renderer);
			SDL_Delay(5000);

			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();

		}
	}
	*/



	void graph() {
		int action;
		ans koef = Enter_Func();
		do {
			printf_s("Enter your type of action: \n 1.Extremum\n2.Func nule\n 4.Defenite Integral\n0.EXIT "), scanf_s("%d", &action);
			switch (action) {
			case 1:
			{

				Extremum(koef);
				break;
			}
			case 2:
			{
				Yzero(koef);
				break;

			}
			/*case 3:
			{
				SDL_graphic(koef);
				break;

			}
			*/
			case 4:
			{
				Def_Integral(koef);
				break;

			}
			case 0:
			{
				
				break;

			}
			}
		} while (action != 0);
		
	}

