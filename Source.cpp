#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int length, user_number, bulls_count, cows_count;
	do
	{
		printf("Write length from 2 to 5: ");
		scanf_s("%i", &length);
	} while (length < 2 || length > 5);
	srand(time(NULL));
	int number[5] = { 0,0,0,0,0 };
	int digit[10] ={0};
	number[0] = 1 + rand() % (9 - 1 + 1);
	digit[number[0]] += 1;
	printf("%i", number[0]);
	for (int i = 1; i < length; ++i)
	{	
		do
		{
			number[i] = 0 + rand() % (9 - 0 + 1);
		} while (digit[number[i]] == 1);
		digit[number[i]] += 1;
		printf("%i", number[i]);
	}
	do
	{	
		bulls_count = 0;
		cows_count = 0;
		printf("\nWrite your number: \n");
		scanf_s("%i", &user_number);
		int user_number_array[5] = { 11,11,11,11,11 };
		for (int j = 0; j < length; ++j)
		{
			user_number_array[length - j - 1] = user_number % 10;
			user_number /= 10;
		}
		for (int l = 0; l < length; ++l)
		{
			if (number[l] == user_number_array[l])
			{
				bulls_count += 1;
			}
			else
			{
				for (int m = 0; m < length; ++m)
				{
					if (number[l] == user_number_array[m])
					{
						cows_count += 1;
						break;
					}
				}
			}
		}
		printf("Bulls - %i, cows - %i \n", bulls_count, cows_count);
	} while (bulls_count != length);
	printf("You are so good! :3");
}