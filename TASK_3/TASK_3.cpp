#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define MAX_SIZE 1000

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));

    int choice;
    do {
        int n;
        double a, b;
        double arr[MAX_SIZE];

        do {
            printf("Введіть кількість елементів масиву n (1..1000): ");
            scanf_s("%d", &n);
            if (n < 1 || n > MAX_SIZE) {
                printf("Помилка! n має бути в межах від 1 до 1000, друже\n");
            }
        } while (n < 1 || n > MAX_SIZE);

        do {
            printf("Введіть межі [a, b] (число a має бути меншим за b):\n");
            printf("a = ");
            scanf_s("%lf", &a);
            printf("b = ");
            scanf_s("%lf", &b);
            if (a >= b) {
                printf("Помилка! Число a повинно бути строго меншим за b\n");
            }
        } while (a >= b);

        double prod = 1.0;
        int hasEven = 0;
        int firstZero = -1, lastZero = -1;
        double currentSum = 0.0, sumBetween = 0.0;

        printf("\nЗгенеровані елементи масиву:\n");
        for (int i = 0; i < n; i++) {
            double raw = a + ((double)rand() / RAND_MAX) * (b - a);
            arr[i] = (double)((int)(raw * 10.0)) / 10.0;
            if (fabs(arr[i]) < 1e-9) {
                arr[i] = 0.0;
            }

            printf("arr[%d] = %.1lf\n", i, arr[i]);

            if ((i + 1) % 2 == 0) {
                prod *= arr[i];
                hasEven = 1;
            }

            if (arr[i] == 0.0) {
                if (firstZero == -1) {
                    firstZero = i;
                    currentSum = 0.0;
                } else {
                    lastZero = i;
                    sumBetween = currentSum;
                }
            } else if (firstZero != -1) {
                currentSum += arr[i];
            }
        }

        printf("\nРезультати обчислень:\n");
        if (hasEven) {
            printf("1) Добуток елементів з парними номерами: %.4lf\n", prod);
        } else {
            printf("1) Елементів з парними номерами немає (n = 1).\n");
        }

        if (firstZero == -1 || lastZero == -1 || firstZero == lastZero) {
            printf("2) Нульових елементів менше двох, суму обчислити неможливо.\n");
        } else {
            printf("2) Перший нуль на позиції arr[%d], останній на arr[%d].\n", firstZero, lastZero);
            printf("А сума елементів між першим і останнім нулями: %.2lf\n", sumBetween);
        }

        printf("\n1 - продовжити роботу, 2 – завершити роботу.\nВаш вибір?: ");
        scanf_s("%d", &choice);
    } while (choice == 1);

    return 0;
}
