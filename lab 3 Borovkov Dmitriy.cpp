#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>	
#define SIZE_MAS1 5
#define SIZE_MAS2 10

void main() {
	setlocale(LC_ALL, "rus");
	int size = 0, number = 0, bulls = 0, cows = 0;
	int compNumber[SIZE_MAS1] = { 0 }, mas2[SIZE_MAS2] = { 0 }, userNumber[SIZE_MAS1];

	srand(time(NULL));
	printf("Введите длину загадываемого числа(от 2 до 5 включительно): ");

	do {
		scanf_s("%d", &size);
		if (size < 2 || size > 5)
			printf("Данные некорректны, попробуйте еще раз.\n");
	} while (size < 2 || size > 5);

	compNumber[0] = 1 + rand() % 9;
	mas2[compNumber[0]] = 1;

	for (int i = 1; i < size; ++i) {
		do {
			compNumber[i] = rand() % 10;

		} while (mas2[compNumber[i]] == 1);
		mas2[compNumber[i]] = 1;
	}

	do {
		printf("Введите число: ");
		scanf_s("%d", &number);

		for (int i = size - 1; i >= 0; --i) {
			userNumber[i] = number % 10;
			number /= 10;
		}

		for (int i = 0; i < size; ++i) {
			if (userNumber[i] == compNumber[i]) {
				bulls++;
			}
			else {
				for (int j = 0; j < size; ++j) {
					if (userNumber[i] == compNumber[j]) {
						cows++;
					}
				}
			}
		}
		if (bulls == size) {
			printf("Поздравляю! Вы угадали число.");
			break;
		}
		printf("Количество коров = %d, количество быков = %d.\n", cows, bulls);
		cows = 0;
		bulls = 0;
	} while (true);

}