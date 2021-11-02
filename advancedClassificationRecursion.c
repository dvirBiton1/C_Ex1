#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome1(int num);
int isArmstrong1(int num, int countDigit, int temp);


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

    return isArmstrong1(num - (int)pow(temp % 10, countDigit), countDigit, temp / 10);
}
int isArmstrong(int num)
{
    int temp = num;
    int countDigit = (int)log10(num) + 1;
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