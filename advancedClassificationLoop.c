#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int num);
int myPow(int base, int exp);
int isArmstrong(int num);

int myPow(int base, int exp)
{
    int sum = 1;
    if (exp == 0)
    {
        return 1;
    }
    for (int i = 1; i <= exp; i++)
    {
        sum *= base;
    }
    return sum;
}
int isArmstrong(int num)
{
    int temp = num;
    int countDigit = 0;
    int counter1 = 0;
    int counter2 = 0;
    if (num < 0)
    {
        return 0;
    }
    while (temp != 0)
    {
        temp = temp / 10;
        countDigit++;
    }
    temp = num;
    while (temp != 0)
    {
        counter1 = myPow(temp % 10, countDigit);
        counter2 += counter1;
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

int isPalindrome(int num)
{
    int temp = num;
    int countDigit = 0;
    int counter1 = 0;
    if (num < 0)
    {
        return 0;
    }
    while (temp != 0)
    {
        temp = temp / 10;
        countDigit++;
    }
    temp = num;
    int arr[countDigit];
    while (temp != 0)
    {
        arr[counter1] = temp % 10;
        temp = temp / 10;
        counter1++;
    }
    for (int i = 0; i < countDigit; i++)
    {
        if (arr[i] != arr[countDigit - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}