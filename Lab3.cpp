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
	int posi[10] = {0};
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
	posi[masrand[0]] = 5;
	for (int i = 1; i < n; ++i)
	{
		do {
			masrand[i] = rand() % 10;
		} while (posi[masrand[i]] == 5);
		posi[masrand[i]] = 5;
	}
	for (int i = 0; i < n; ++i) { //показывает, какое число было загадано, чтобы быстрее можно было проверить работу программы
		printf("%d", masrand[i]);
	}
	printf("\n");
	printf("Отгадайте число:\n");
	do {
		bull = 0;
		cow = 0;
		scanf_s("%d", &user);
		// Переписываем число пользователя в массив
		for (int i = 0; i < n; ++i) {
			lol = pow(10, (n - i - 1));
			if (i == 0) {
				posi[i] = user / 10;
			}
			else {
				posi[i] = user / lol % 10;
			}
		}
		// считаем кол-во быков и коров
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (posi[i] == masrand[j]&& i==j) 
					bull += 1;
				if (posi[i] == masrand[j] && i != j)
					cow += 1;
			}
		}
		k += 1;
		printf("\n%dкоров %dбыков количество попыток: %d\n\n", cow, bull,k);
	} while (bull != n);

	printf("ПОЗДРАВЛЯЕМ, ВЫ....ПРОШЛИ.....ИГРУ.....\n");

	return 0;
}