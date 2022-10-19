#include <stdio.h>
#include<time.h>
#include<stdlib.h>


int main() {

    srand(time(NULL));
    int n;
    do {
        printf("Input correct data:");
        scanf("%i",&n);
        printf("\n");
    }
    while(1>n || n>5);

    int number[5];
    int digit[10]={(0)};
    number[0]=1+rand()%9;
    digit[number[0]]=1;
    for(int i=1;i<n;++i)
    {
        do {
            number[i]=rand()%10;
        }
        while(digit[number[i]]==1);
        digit[number[i]]=1;
    }


    int bulls,cows;
    do {
        bulls=0;
        cows=0;
        printf("Input guess:");
        int g;
        scanf("%i",&g);
        int guess[5]={(0)};
        for(int i=0;i<n;++i,g/=10)
            guess[n-1-i]=g%10;
        for(int i=0;i<n;++i)
        {
            if(number[i]==guess[i])
                bulls++;
            else
            {
                for(int j=0;j<n;++j)
                {
                    if(number[j]==guess[i])
                    {
                        cows++;
                        break;
                    }
                }
            }
        }

        printf("cows:%i bulls:%i\n",cows,bulls);
    }
    while(bulls!=n);
    printf("Hooray,you're right!");
    return 0;
}
