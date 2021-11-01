#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int num);
int isPalindrome1(int num);
int myPow(int base, int exp);
int isArmstrong(int num);
int isArmstrong1(int num, int countDigit, int temp);

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

int isArmstrong1(int num, int countDigit, int temp)
{
    if (temp == 0)
    {
        if (num == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return isArmstrong1(num - myPow(temp % 10, countDigit), countDigit, temp / 10);
}
int isArmstrong(int num)
{
    int temp = num;
    int countDigit = (int)log10(num) + 1;
    int counter1 = 0;
    int counter2 = 0;
    if (num < 0)
    {
        return 0;
    }
    return isArmstrong1(num, countDigit, temp);
}

int isPalindrome(int num)
{
    if (num == isPalindrome1(num))
    {
        return 1;
    }

    return 0;
}

int isPalindrome1(int num)
{
    int digit = (int)log10(num);
    if (num == 0)
        return 0;

    return (((num % 10) * pow(10, digit)) + isPalindrome1(num / 10));
}