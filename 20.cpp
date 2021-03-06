#include <stdio.h> //scanf() printf()
#include <locale.h> //setlocale()
#include <stdlib.h> //rand() malloc()

void input_arr1(int* A, int n) //Ввод массива с клавиатуры
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("A[%d]=", i);
		scanf_s("%d", &A[i]);
	}
}

int random(int a)
{
	return rand() % a;
}

void input_arr2(int* A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		A[i] = random(201);
}

void out_arr(int* A, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%5d", A[i]);
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	int j,n,p,i,max;
	//Создание массива
	printf("Введите размер массива: ");
	scanf_s("%d", &n);
	int* A = (int*)malloc(n * sizeof(int));
	int* B = (int*)malloc(n * sizeof(int));
	do
	{
		printf("Способ задания массива(0-вручную, 1-рандомно): ");
		scanf_s("%d", &p);
	} while (p < 0 && p > 1);
	if (p == 0)
	{
		printf("\nВведите элементы массива:\n");
		input_arr1(A, n);
	}
	else input_arr2(A, n);
	out_arr(A, n);
	// Удалить из массива «лишние» элементы, так чтобы оставшиеся образовывали возрастающую последовательность
	for (j = 1; j < n; j++)
	{
		for (i = 1; i < n; i++)
		{
			max = A[0];
			if (A[i] >= max)
				max = A[i];
			else B[j] = A[i];
		}
	}
	out_arr(B, n);
	}
