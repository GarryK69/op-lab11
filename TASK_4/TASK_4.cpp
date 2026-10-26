#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 15

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));

    int choice = 2;
    do {
        int D[SIZE];

        printf("Введіть 15 цілих чисел для масиву D (через пробіл або Enter, як вам там зручно :D ):\n");
        for (int i = 0; i < SIZE; i++) {
            scanf_s("%d", &D[i]);
        }

        printf("\nВихідний масив D:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", D[i]);
        }
        printf("\n");

        int maxVal = D[0];
        for (int i = 1; i < SIZE; i++) {
            if (D[i] > maxVal) {
                maxVal = D[i];
            }
        }

        int hasSecond = 0;
        int secondMax = 0;
        for (int i = 0; i < SIZE; i++) {
            if (D[i] < maxVal) {
                if (!hasSecond || D[i] > secondMax) {
                    secondMax = D[i];
                    hasSecond = 1;
                }
            }
        }

        printf("\nРезультати:\n");
        printf("Максимальне значення: %d\n", maxVal);
        if (hasSecond) {
            printf("Найбільше значення із залишених: %d\n", secondMax);
        } else {
            printf("Усі елементи масиву однакові, залишених елементів немає.\n");
        }

        printf("\n1 - продовжити роботу, 2 – завершити роботу.\nВаш вибір: ");
        if (scanf_s("%d", &choice) != 1) {
            choice = 2;
        }
    } while (choice == 1);

    return 0;
}
