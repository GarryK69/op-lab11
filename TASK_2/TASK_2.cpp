#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));

    int choice;
    do {
        int m, n, k;

        do {
            printf("Введіть кількість цілих чисел m (m > 0): ");
            scanf_s("%d", &m);
            if (m <= 0) {
                printf("Помилка! Число m має бути більшим за нуль, агов\n");
            }
        } while (m <= 0);

        do {
            printf("Введіть кількість дійсних чисел n (n > 0): ");
            scanf_s("%d", &n);
            if (n <= 0) {
                printf("Помилка! Число n має бути більшим за нууль\n");
            }
        } while (n <= 0);

        do {
            printf("Введіть кількість чисел у рядку k (3 <= k <= 10): ");
            scanf_s("%d", &k);
            if (k < 3 || k > 10) {
                printf("Помилка! k має бути в межах від 3 до 10!\n");
            }
        } while (k < 3 || k > 10);

        printf("\nЗгенеровані цілі числа з проміжку [-200, 100] (по %d у рядку):\n", k);
        for (int i = 0; i < m; i++) {
            int val = rand() % 301 - 200;
            printf("%7d", val);
            if ((i + 1) % k == 0 || i == m - 1) {
                printf("\n");
            }
        }

        printf("\nЗгенеровані дійсні числа з проміжку [0, 10] (по %d у рядку):\n", k);
        for (int i = 0; i < n; i++) {
            double val = ((double)rand() / RAND_MAX) * 10.0;
            printf("%10.3lf", val);
            if ((i + 1) % k == 0 || i == n - 1) {
                printf("\n");
            }
        }

        printf("\n1 - продовжити роботу, 2 – завершити роботу.\nВаш вибір?: ");
        scanf_s("%d", &choice);
    } while (choice == 1);

    return 0;
}
