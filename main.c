#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main(){
    srand(time(NULL));
    setlocale(LC_ALL,"Russian");
    int n, N, unknown_number, user_number = 0, temporal_user, temporal, cows, bulls;
    int tr = 0, m = 0;

    printf("Введите длину числа от 2 до 5 включительно: ");
    scanf("%i", &n);

    while(n>5 || n<2){
        printf("Введено некорректное число, повторите попытку: ");
        getchar();
        scanf("%i", &n);
    }
    N = pow(10, n-1);

    while(tr == 0){
        unknown_number = N + rand() % (N - N * 10);
        int array[10] ={0};
        tr = 1;
        m = unknown_number;
        while(m > 0){
            ++array[m%10];
            m = m / 10;
        }
        for(int i = 0; i < 10; ++i){
            if(array[i] >1) {
                tr = 0;
                break;
            }
        }

    }
    printf("Попробуйте угадать загаданное компьютером число: ");


    do{
        scanf("%i", &user_number);
        int count_numbers[10] = {0};
        int count_user_numbers[10] = {0};
        cows = 0;
        bulls = 0;
        temporal_user = user_number;
        temporal = unknown_number;
        for(int i = 0; i < n; ++i){
            if(temporal_user % 10 == temporal % 10)
                ++bulls;
            ++count_user_numbers[temporal_user % 10];
            ++count_numbers[temporal % 10];
            temporal_user = temporal_user / 10;
            temporal = temporal / 10;
        }

        for(int i = 0; i < 10; ++i)
            if(count_numbers[i] <= count_user_numbers[i] && count_numbers[i] != 0)
                ++cows;
        if(bulls!=n)
            printf("%iк %iб\n", cows-bulls, bulls);


    }while(unknown_number != user_number);
    printf("Поздравляю! Вы угадали число");

    return 0;
}
