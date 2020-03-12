#include <stdlib.h> 
#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>

int irand(int n) // ���������� ����. �����.
{

    int n2 = pow(n, 2);

    return 1 + rand() % (n2 - 1 + 1);

}

void input_arr1(int** arr, int n, int m) // ���� �����. ����. �������.
{

    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(m * sizeof(int)); // ��������� ������ ��� �������� �����
        for (int j = 0; j < m; ++j) {
            arr[i][j] = irand(n);
        }
    }

}

void input_arr2(int* arr[], int n, int m) // ���� ����� � ������.
{

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc((m * sizeof(int))); // ��������� ������ ��� �������� �����
        for (int j = 0; j < m; ++j) {
            do {
                printf("a[%d][%d]= ", i, j);
                scanf_s("%d", &arr[i][j]);

            } while (arr[i][j] > n * m || arr[i][j] < 0);
        }
    }

}

void extra_arr(int** arr, int n, int m, int max) // ����� ��.�������
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

void output_arr(int** arr, int n, int m) // ����� ��.�������
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

    srand(time(NULL)); // ����������� ���������� �����.
    setlocale(LC_ALL, "Rus");

    int n, m; // ���-�� ��������� � ������� n*m.

    do // �������� �� ������������ ����� ������.
    {

        printf("������� ���-�� �����: ");
        scanf_s("%d", &n);

        printf("������� ���-�� ��������: ");
        scanf_s("%d", &m);

    } while (n <= 0 && m <= 0);

    int** arr = (int**)malloc(n * sizeof(int*)); // ��������� ������ ��� ������� ����������.

    if (arr == NULL) // ��������� � ��� ������, ���� ������ ����� �� ��������.
    {

        printf("������ �� ��������");
        return 1;
    }

    int O; // ���������� ��� ������, ��� ����� ������� ��. �������.

    do // �������� �� ������������ ����� ������ ��� ����� ��. �������.
    {

        printf("1 - ��������� �����\n2 - ���� � ����������\n");
        scanf_s("%d", &O);

    } while (O != 1 && O != 2);

    if (O == 1) // ���� ������, �� ���������� ������� ��� ����� ��������� ����� �������.
        input_arr1(arr, n, m);
    else // ��� ��� ����� ������� ����� ��� �������.
        input_arr2(arr, n, m);

    printf("�������� ������:\n");
    output_arr(arr, n, m); // ������� ��� ����������� ��. �������.

    extra_arr();

    free(arr); // �������� ������.

}