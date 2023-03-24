#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "currency.h"
#include "temperature.h"
#include "time.h"

void main()
{
    while (1)
    {
        printf("\nEnter 1--------> Currency Converter");
        printf("\nEnter 2--------> Temperature Converter");
        printf("\nEnter 3--------> Time Converter");
        printf("\nEnter 0--------> Quit\n");
        printf("\nEnter your choice : ");
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        else if (n == 1)
            currency();
        else if (n == 2)
            temperature();
        else if (n == 3)
            time();
        else
            printf("Enter proper choice !");
    }
    printf("The program has terminated...");
}