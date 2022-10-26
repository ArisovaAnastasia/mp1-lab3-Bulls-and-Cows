#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

int main()
{
    setlocale(LC_ALL,"Rus");
    srand(time(NULL));
    int length;
    while (1)
    {
        printf("INPUT NUMBERS( от 2 до 5)\n");
        scanf_s("%i", &length);
        if ((length < 6) && (length > 1)) { break; }
    }
    const int size = length;
    int mass[size];
    int uniq[10] = { 0 };
    int count = 0;
    int d=0;
    while (count<size)
    {
        int ran = 1 + rand() % (10 - 1);
        if (uniq[ran]==0){uniq[ran]=1;mass[d]=ran;d+=1;count+=1;}
    }
    for (int i=0;i<size;++i)
    {printf("%i",mass[i]);}
    while(1)
    {
        int bull=0;
        int cow=0;
        int c[size];
        printf("Input number:  ");
        for (int i = 0; i < size; ++i)
        {
            scanf_s("%i", &c[i]);
        }
        for (int i=0;i<size;++i)
        {
            if (mass[i]==c[i]){bull+=1;}
        }
        printf("%i",bull);
        int r=0;
        while (r<size)
        {
            for (int i=0;i<size;++i)
            {
                if ((mass[r]==c[i])&&(r!=i))
                { cow+=1;}
            }
            r+=1;
        }
        printf("%i",cow);
        printf("Number of bulls and cowes: ");
        printf("%i %i ",bull,cow);
        if (bull==size){break;}
    }
}