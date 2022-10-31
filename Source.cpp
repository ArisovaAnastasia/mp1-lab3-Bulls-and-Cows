#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main() {
	srand(time(NULL));
	int  n, guess_number[5], user_number[5], user_guess, bulls, cows, index, count = 1;
	bool checked_num[10] = { (0) };
	do {
		printf("Choose the length of the guessed number:\n ");
		scanf_s("%i", &n);
	} while (n > 5 || n < 1);

	guess_number[0] = 1 + rand() % 10;
	index = guess_number[0];
	checked_num[index] = 1;
	for (int i = 1; i < n; ++i) {
		do {
			guess_number[i] = rand() % 10;
			index = guess_number[i];
		} while (checked_num[index] == 1);
		checked_num[index] = 1;
	}

	do {
		cows = 0;
		bulls = 0;
		printf("Enter an n-digit number with non-repeating digits:\n ");
		scanf_s("%i", &user_guess);
		for (int i = n - 1; i >= 0; --i) {
			user_number[i] = user_guess % 10;
			user_guess /= 10;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (user_number[i] == guess_number[j] && j == i) {
					bulls++;
				}
				if (user_number[i] == guess_number[j] && j != i)
					cows++;
			}

		}
		printf_s("%ib %ic\n ", bulls, cows);
	} while (bulls != n);
	printf("Complete sequence");
	return 0;
}