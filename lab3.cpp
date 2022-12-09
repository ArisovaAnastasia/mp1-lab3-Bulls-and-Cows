#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "RUS");
	int size = 0, number = 0, bulls = 0, cows = 0;
	int BotNumber[5] = { 0 },arr2[10] = { 0 }, user_Number[5];

	srand(time(NULL));
	printf("укажите длину загаданного числа(от 2 до 5: ");
	
	
	do {
		scanf_s("%d", &size);
		if (size > 5 || size < 2)
			printf("Указанные данные некорекктны, попробуйте еще раз!");
	
	} while (size < 2 || size>5);
	
	BotNumber[0] = 1 + rand() % 9;
	arr2[BotNumber[0]] = 1;

	for (int i = 1; i < size; ++i) {
		do {
			BotNumber[i] = rand() % 10;

		} while (arr2[BotNumber[i]] == 1);
		arr2[BotNumber[i]] = 1;
	}

	do {
		printf("Введите число: ");
		scanf_s("%d", &number);

		for (int i = size - 1; i >= 0; --i) {
			user_Number[i] = number % 10;
			number /= 10;
		}

		for (int i = 0; i < size; ++i) {
			if (user_Number[i] == BotNumber[i]) {
				bulls++;
			}
			else {
				for (int j = 0; j < size; ++j) {
					if (user_Number[i] == BotNumber[j]) {
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