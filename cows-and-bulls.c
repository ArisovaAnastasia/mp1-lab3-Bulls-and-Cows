#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Array with decimal digits
    int number[5] = {0};
    int n;

    do {
        printf("\nEnter the value: ");
        scanf("%d", &n);
    } while (n < 2 || n > 5);

    for (int i = 1; i < 10; i++) {    // Shuffle array with decimal digits
        int temp = array[i];
        int randomIndex = rand() % 9;

        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }

    if (array[0] != 0) {            // Adding non-repeating non-zero value as the first array's element
        number[0] = array[0];
    } else {
        int temp = array[0];
        array[0] = array[1];
        array[1] = temp;
        number[0] = array[0];
    }

    for (int i = 1; i < n; ++i) {   // Adding non-repeating values to the secret number
        number[i] = array[i];
    }

    int answer;
    int answerArray[5];
    int bulls = 0, cows = 0;
    int count = 1;

    // Debug moment
    // for (int i = 0; i < n; ++i) printf("%d", number[i]);

    do {
        printf("\nEnter the number: ");
        scanf("%d", &answer);
        int answerTemp = answer;
        for (int i = n - 1; i >= 0; --i) {
            answerArray[i] = answer % 10;
            answer /= 10;
        }
        for (int i = 0; i < n; ++i) {
            if (answerArray[i] == number[i]) bulls++;
            else {
                for (int j = 0; j < n; ++j) {
                    if (answerArray[i] == number[j]) cows++;
                }
            }
        }

        if (bulls == n) {
            printf("\nYou've won!!! The number was %d ! You've made it in %d tries!\n", answerTemp, count);
            break;
        }
        printf("There are %d bulls and %d cows  ---  try: %d\n", bulls, cows, count);
        bulls = 0;
        cows = 0;
        count++;

    } while (true);

    return 0;
}