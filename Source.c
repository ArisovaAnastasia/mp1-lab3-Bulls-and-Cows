
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
//#include <iostream>
#define SIZE_1 5
#define SIZE_2 10
void main() {
	setlocale(LC_ALL,"rus");
	int cows = 0, bulls = 0, size = 0, numb = 0, count = 0;
	int mas[SIZE_2]={0}, comp[SIZE_1] = {0}, user[SIZE_1] = {0};
	srand(time(NULL));
	printf("Введите длину загадываемого числа от 2 до 5 (включительно)\n");
	do {
		scanf_s("%d", &size);
		if (2 > size || size > 5)
			printf("Данные некорректны! Попробуйте снова\n");
	} while (2 > size || size > 5);
	comp[0] = 1 + rand() % 9;
	mas[comp[0]] = 1;
	for (int i = 1; i < size; i++) {
		do {
			comp[i] = rand() % 10;
		} while (mas[comp[i]] == 1);
		mas[comp[i]] = 1;
	}printf("Введите ваше число:\n");
	do {
		
		scanf_s("%d", &numb);
		count++;
		for (int i = size - 1; i >= 0; --i) {
			user[i] = numb % 10;
			numb /= 10;
		}
		for (int i = 0; i < size; i++) {
			if (user[i] == comp[i]) {
				bulls++;
			
			}
			else {
				for (int j = 0; j < size; j++) {
					if (user[i] == comp[j]) {
						cows++;
						
					}
				}
			}
		}
		if (bulls == size) {
			printf("Вы выйграли!!!\n");
			printf("Число попыток = %d\n", count);
			break;
			
			
		}
		printf("Число коров = %d, Число быков = %d\n", cows, bulls);
		cows = 0;
		bulls = 0;
	} while (true);
	
}



