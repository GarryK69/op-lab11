#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));

    int choice = 2;
    do {
        int opt = 0;
        do {
            printf("\n--- Меню генераторів випадкових чисел --\n");
            printf("1.  [-4; -1) цілі\n");
            printf("2.  [100; 299] цілі\n");
            printf("3.  [-35; -1] цілі парні\n");
            printf("4.  [-128; 127] цілі\n");
            printf("5.  [-7; 13) цілі непарні\n");
            printf("6.  [-7.85; 28√3] дійсні\n");
            printf("7.  [-100; 100] цілі\n");
            printf("8.  [23; 71] цілі\n");
            printf("9.  [0; 2) дійсні\n");
            printf("10. [√17; √82) дійсні\n");
            printf("Оберіть генератор (1-10): ");

            if (scanf_s("%d", &opt) != 1 || opt < 1 || opt > 10) {
                printf("Помилка! Номер повинен бути від 1 до 10. Негіііднику\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                opt = 0;
            }
        } while (opt < 1 || opt > 10);

        printf("\nЗгенеровані числа (5 значень для перевірки):\n");
        switch (opt) {
        case 1:
            for (int i = 0; i < 5; i++) {
                int val = rand() % 3 - 4;
                printf("%d ", val);
            }
            break;
        case 2:
            for (int i = 0; i < 5; i++) {
                int val = rand() % 200 + 100;
                printf("%d ", val);
            }
            break;
        case 3:
            for (int i = 0; i < 5; i++) {
                int val = -34 + (rand() % 17) * 2;
                printf("%d ", val);
            }
            break;
        case 4:
            for (int i = 0; i < 5; i++) {
                int val = rand() % 256 - 128;
                printf("%d ", val);
            }
            break;
        case 5:
            for (int i = 0; i < 5; i++) {
                int val = -7 + (rand() % 10) * 2;
                printf("%d ", val);
            }
            break;
        case 6:
            for (int i = 0; i < 5; i++) {
                double minVal = -7.85;
                double maxVal = 28.0 * sqrt(3.0);
                double val = minVal + ((double)rand() / RAND_MAX) * (maxVal - minVal);
                printf("%.4lf ", val);
            }
            break;
        case 7:
            for (int i = 0; i < 5; i++) {
                int val = rand() % 201 - 100;
                printf("%d ", val);
            }
            break;
        case 8:
            for (int i = 0; i < 5; i++) {
                int val = rand() % 49 + 23;
                printf("%d ", val);
            }
            break;
        case 9:
            for (int i = 0; i < 5; i++) {
                double val = ((double)rand() / (RAND_MAX + 1.0)) * 2.0;
                printf("%.4lf ", val);
            }
            break;
        case 10:
            for (int i = 0; i < 5; i++) {
                double minVal = sqrt(17.0);
                double maxVal = sqrt(82.0);
                double val = minVal + ((double)rand() / (RAND_MAX + 1.0)) * (maxVal - minVal);
                printf("%.4lf ", val);
            }
            break;
        }
        printf("\n");

        printf("\n1 - продовжити роботу, 2 – завершити роботу.\nВаш вибір: ");
        if (scanf_s("%d", &choice) != 1) {
            choice = 2;
        }
    } while (choice == 1);

    return 0;
}
