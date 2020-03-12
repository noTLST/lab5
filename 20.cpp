#include <stdlib.h> 
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>

int irand(int n) // генерирует случ. числа.
{

    int n2 = pow(n, 2);

    return 1 + rand() % (n2 - 1 + 1);

}

void input_arr1(int** arr, int n, int m) // Ввод чисел. случ. образом.
{

    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(m * sizeof(int)); // выделение памяти под хранение строк
        for (int j = 0; j < m; ++j) {
            arr[i][j] = irand(n);
        }
    }

}

void input_arr2(int* arr[], int n, int m) // Ввод чисел в ручную.
{

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc((m * sizeof(int))); // выделение памяти под хранение строк
        for (int j = 0; j < m; ++j) {
            do {
                printf("a[%d][%d]= ", i, j);
                scanf_s("%d", &arr[i][j]);

            } while (arr[i][j] > n * m || arr[i][j] < 0);
        }
    }

}

void extra_arr(int** arr, int n, int m, int max) // Вывод эл.матрицы
{

    max = *&arr[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if 
        }
        printf("\n");
    }

    printf("\n");

}

void output_arr(int** arr, int n, int m) // Вывод эл.матрицы
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j) {
            printf("%4d", *&arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

}

int main()
{

    srand(time(NULL)); // сбрасывание генератора чисел.
    setlocale(LC_ALL, "Rus");

    int n, m; // кол-во элементов в массиве n*m.

    do // Проверка на корректность ввода данных.
    {

        printf("Введите кол-во строк: ");
        scanf_s("%d", &n);

        printf("Введите кол-во столбцов: ");
        scanf_s("%d", &m);

    } while (n <= 0 && m <= 0);

    int** arr = (int**)malloc(n * sizeof(int*)); // выделение памяти для массива указателей.

    if (arr == NULL) // сработает в том случае, если память будет не выделена.
    {

        printf("Память не выделена");
        return 1;
    }

    int O; // переменная для выбора, как будем вводить эл. массива.

    do // проверка на корректность ввода данных для ввода эл. массива.
    {

        printf("1 - случайное число\n2 - Ввод с клавиатуры\n");
        scanf_s("%d", &O);

    } while (O != 1 && O != 2);

    if (O == 1) // если истина, то выполнится функция для ввода случайных чисел матрицы.
        input_arr1(arr, n, m);
    else // или для ввода вручную чисел для массива.
        input_arr2(arr, n, m);

    printf("Исходный массив:\n");
    output_arr(arr, n, m); // функция для отображения эл. матрицы.

    extra_arr(); //Обработка массива

    free(arr); // очищение памяти.

}
