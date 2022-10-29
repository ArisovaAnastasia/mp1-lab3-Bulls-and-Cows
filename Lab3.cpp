#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main() {
	setlocale(0, "");
	srand(time(NULL));
	int n, user = 0; //user - число пользователя
	int masrand[5];// позиции цифр загаданного числа
	int posi[10] = { 0 };
	int cow = 0, bull = 0;
	int k = 0;
	int lol = 0;
	printf("\nВыберите длину загаданного числа от 2 до 5:\n");
	// проверка
	do {
		scanf_s("%i", &n);
		if (!((2 <= n) && (n <= 5))) {
			printf("Повторите попытку.\n");
		}
	} while (!((2 <= n) && (n <= 5)));
	//создание рандомного загаданного числа
	masrand[0] = 1 + rand() % 9;
	posi[masrand[0]] = 1;
	for (int i = 1; i < n; ++i)
	{
		do {
			masrand[i] = rand() % 10;
		} while (posi[masrand[i]] == 1);
		posi[masrand[i]] = 1;
	}
	for (int i = 0; i < n; ++i) { //показывает, какое число было загадано, чтобы быстрее можно было проверить работу программы
		printf("%d", masrand[i]);
	}
	printf("\n");
	printf("Отгадайте число:\n");
	do {
		cow = 0;
		bull = 0;
		scanf_s("%i", &user);
		for (int i = n - 1; i >= 0; --i) {
			posi[i] = user % 10;
			user /= 10;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (posi[i] == masrand[j] && j == i) {
					bull++;
				}
				if (posi[i] == masrand[j] && j != i)
					cow++;
			}
		}
		k += 1;
		printf("\n%dкоров %dбыков количество попыток: %d\n\n", cow, bull, k);
	} while (bull != n);

	printf("ПОЗДРАВЛЯЕМ, ВЫ....ПРОШЛИ.....ИГРУ.....\n");

	return 0;
}