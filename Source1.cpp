#include <stdio.h>
#include <math.h>
#include <random>
#include <time.h>
#include <math.h>

int main() {
	srand(time(NULL));
	int n, i, j, cow, bull = 0, a = 0;
	scanf_s("%i", &n);
	int num[5] = {-1};
	int num1[5] = {-1};
	for (i = 0; i < n - 1; ++i) {
		num[i] = 1 + rand() % 9;
	}
	num[n - 1] = rand() % 10;
	int gues[5] = {0}, gnum;
	while (bull != n) {
		for (i = 0; i < n - 1; ++i) {
			num1[i] = num[i];
		}
		bull = 0;
		cow = 0;
		scanf_s("%i", &gnum);
		for (i = 0; i < n; ++i) {
			a = pow(10, n - 1 - i);
			gues[i] = gnum / a;
			gnum = gnum - gnum / a * a;
		}
		for (i = 0; i < n; ++i) {
			if (num1[i] == gues[i]) {
				bull += 1;
				num1[i] = -1;
			}
			else {
				for (j = 0; j < n; ++j) {
					if (num1[j] == gues[i]) {
						cow += 1;
						num1[j] = -1;
						break;
						}
					}
				}
			}
		printf("Cow - %i, Bull - %i\n", cow, bull);
	}	
	printf("You win!");
}