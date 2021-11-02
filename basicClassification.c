#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int num)
{
    if (num < 1)
    {
        return 0;
    }
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int isStrong(int num)
{
    int temp = num;
    int counter1 = 1;
    int counter2 = 0;
    if (num <= 0)
    {
        return 0;
    }

    while (temp != 0)
    {
        for (int i = 1; i <= temp % 10; i++)
        {
            counter1 *= i;
        }
        counter2 += counter1;
        counter1 = 1;
        temp = temp / 10;
    }
    if (counter2 == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}