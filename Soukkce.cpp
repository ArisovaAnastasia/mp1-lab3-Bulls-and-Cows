#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
void main() {
	int n = 0, bulls, cows;
	srand(time(NULL));
	do {
		printf("enter the length of the number from 2 to 5 \n");
		scanf_s("%i", &n);
		if ((n < 2) || (n > 5)) {
			printf("enter the data again");
		}
	} while ((n < 2) || (n > 5));
	int* arr = (int*)malloc(n *  sizeof(int));
	arr[0] = 1 + rand() % (9 - 1 + 1);
	int ind = arr[0];
	bool chec[10]={(0)};
	chec[ind] = 1;
	for (int i = 1; i < n;i++) {
		do {
			arr[i] = 0 + rand() % (9 - 0 + 1);
			ind = arr[i];
		}while (chec[ind] == 1);
		chec[ind] = 1;
	}
	int* numb = (int*)malloc(n * sizeof(int));
	do {
		 bulls = 0;
		 cows = 0;
		 printf("enter number ");
		 int num;
		 scanf_s("%i", &num);
		 for (int i = n - 1;i >= 0;i--) {
			 numb[i] = num % 10;
			 num = num / 10;
		 }
		 for (int i = 0;i < n; i++) {
			 for (int j = 0;j < n; j++) {
				 if ((i == j) && (numb[j] == arr[i])) {
					 bulls++;
				 }
				 else if (numb[j] == arr[i]) {
					 cows++;
				 }
			 }
		 }
		 printf("%ib %ic ", bulls, cows);
		 for (int i = 0; i < n;i++) {
			 printf("%i", numb[i]);
		 }

	} while (bulls != n);
	

	free(arr);
	free(numb);
}