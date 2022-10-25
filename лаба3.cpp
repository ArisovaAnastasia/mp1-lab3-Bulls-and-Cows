#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void main() {
	srand(time(NULL));
	int  n, guess_number[5], user_number[5], user_guess,bull, cow, index, count = 1;
	bool checked_num[10]={(0)};
	do {
		printf("Type lenght of the number: ");
		scanf_s("%i", &n);
	} while (n < 2 && n>5);
	guess_number[0]= 1 + rand() % 10;
	index = guess_number[0];
	checked_num [index] = 1;
	for (int i = 1; i < n; ++i){
		do {
			guess_number[i] = rand() % 10;
			index = guess_number[i];
		} while (checked_num[index] == 1);
		checked_num[index] = 1;
	}
	do {
		cow = 0;
		bull = 0;
		printf("Guess number: ");
		scanf_s("%i", &user_guess);
		for (int i = n-1; i >= 0; --i) {
			user_number[i] = user_guess % 10;
			user_guess /= 10;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (user_number[i] == guess_number[j] && j == i) {
					bull++;
				}
				if (user_number[i] == guess_number[j] && j != i)
					cow++;
			}
			
		}
		printf_s("%ib %ic\n", bull, cow);
	} while (bull != n);
	printf("Yes, you're right");
}