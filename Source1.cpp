#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(NULL));

	int n, user_num = 0; //user_num - число пользователя
	int hidden_num_pos[5] = { 0, 0, 0, 0, 0 }; // позиции цифр загаданного числа
	int user_num_pos[5] = { 0, 0, 0, 0, 0 }; // позиции цифр числа пользователя
	int k_cow = 0, k_bull = 0; // кол-во коров и быков соответственно
	int st = 0;

	//создание уникального числа
	hidden_num_pos[0] = 1 + rand() % 9;
	do {
		hidden_num_pos[1] = rand() % 10;
	} while (hidden_num_pos[1] == hidden_num_pos[0]);
	do {
		hidden_num_pos[2] = rand() % 10;
	} while ((hidden_num_pos[2] == hidden_num_pos[0]) or (hidden_num_pos[2] == hidden_num_pos[1]));
	do {
		hidden_num_pos[3] = rand() % 10;
	} while ((hidden_num_pos[3] == hidden_num_pos[0]) or (hidden_num_pos[3] == hidden_num_pos[1]) or (hidden_num_pos[3] == hidden_num_pos[2]));
	do {
		hidden_num_pos[4] = rand() % 10;
	} while ((hidden_num_pos[4] == hidden_num_pos[0]) or (hidden_num_pos[4] == hidden_num_pos[1]) or (hidden_num_pos[4] == hidden_num_pos[2]) or (hidden_num_pos[4] == hidden_num_pos[3]));
	
	printf("	Игра Быки и Коровы\n");
	printf("Правила: \n"
		"	1. Игрок выбирает длину загадываемого числа – n (от 2 до 5 включительно).\n"
		"	2. Компьютер задумывает n-значное число с неповторяющимися цифрами (цифра 0 может стоять на любой позиции кроме первой).\n"
		"	3. Игрок делает попытку отгадать число – вводит n-значное число с неповторяющимися цифрами.\n"
		"	4. Компьютер сообщает количество коров и быков для введенного числа.\n"
		"	5. Если количество быков совпадает с n-значным загаданным числом, то игрок побеждает. \n");
	printf("\nОбозначения: \n"
		"	Количество коров - сколько цифр есть и в загаданном, и введенном числе, но при этом их позиции не совпадают.\n"
		"	Количество быков - сколько цифр угадано с точностью до позиции в загаданном числе.\n");
	printf("\nВведите длину загадываемого числа:\n");

	// проверка введённых данных
	do {
		scanf_s("%i", &n);
		if (!((2 <= n) and (n <= 5))) {
			printf("Повторите попытку.\n");
		}
	} while (!((2 <= n) and (n <= 5)));
	
	printf("\nПопытайтесь отгадать загаданное число:\n");

	// Пользователь вводит число, а программа выводит кол-во коров и быков
	do {
		k_cow = 0, k_bull = 0;
		scanf_s("%i", &user_num);
		// Число пользователя переписывается в массив user_num_pos
		for (int i = 0; i < n; ++i) {
			st = pow(10, (n - 1 - i));
			if (i == 0) {
				user_num_pos[i] = user_num / st;
			} 
			else {
				user_num_pos[i] = user_num / st % 10;
			}
		}
		// Подсчёт кол-ва коров и быков
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (user_num_pos[i] == hidden_num_pos[j]) {
					k_cow += 1;
					if (i == j) {
						k_cow -= 1;
						k_bull += 1;
					}
				}
			}
		}
		printf("\n%iк %iб\n\n", k_cow, k_bull);
	} while (k_bull != n);

	printf("Вы отгадали загаданное число!\n");

	return 0;
}