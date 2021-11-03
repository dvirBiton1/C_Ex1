#include<stdio.h>
#include"NumClass.h"

int main(){
    int min;
    int max;
    do
    {
        scanf("%d", &min);
        scanf("%d", &max);
    } while (min <=0 || max <=0);
    
    printf("The Armstrong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isArmstrong(i) == 1)
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Palindromes are:");
    for (int i = min; i <= max; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = min; i <= max; i++)
    {
        if (isStrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}