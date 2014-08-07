//
//  lab2personnummer.c
//
//  Kontrollerar om ett personnummer är giltigt.
//
//  Created by Kj Drougge on 2012-09-05.
//  Copyright (c) 2012 Kj Drougge. All rights reserved.
//

#include <stdio.h>

#define personNummer 10

// siffersumman: räknar ut siffersumman av de nio första siffrorna. Varannan gånger 2 och sedan adderas ihop. Summan returneras
int siffersumman(int pnr[])
{
    int summa = 0;
    for (int i = 0; i < 9; i++) {
        if ((i % 2) == 0)
        {
            summa +=((pnr[i] * 2) % 10) + ((pnr[i] * 2)/10);
        }
        else
        {
            summa += pnr[i];
        }
    }
    return summa;
}

// kontrollera: kontrollerar entals siffran i siffersumman med kontrollsiffran. Om det stämmer är det giltligt annars ej.
void kontrollera(int summa, int nr)
{
    int kontrollsiffra = summa % 10;
    
    if (kontrollsiffra != 0)
    {
        kontrollsiffra = 10 - kontrollsiffra;
    }
    
    if (kontrollsiffra == nr)
    {
        printf("Woho! Du har ett giltligt personnummer\n");
    }
    else
    {
        printf("Antingen har du skrivit in fel eller så är det ogiltligt\n");
    }
}

// låter användaren mata in sitt 10-siffriga personnummer och kontrollerar om det är äkta. En char returneras.
char inmatning()
{
    int pnr[personNummer];
    char val;
    
    printf("Skriv in personnumret (YYMMDDXXXX) : ");
    for (int i = 0; i < personNummer; i++)
    {
        scanf("%1d-", &pnr[i]);
    }
    
    //kontrollerar om månad är över 12 eller dag är över 31.
    if ((pnr[2] == 1  && pnr[3] > 2) || (pnr[4] == 3 && pnr[5] > 1))
    {
        printf("Kontrollera inmatningen...\n");
        return val = 'y';
    }
    else
    {
        kontrollera((siffersumman(pnr)), pnr[9]);
        
        getchar();
        printf("Skriva in nytt? (y/n): ");
        scanf("%c", &val);
        return val;
    }
}

// 
int main()
{
    char val;
    
    do
    {
        val = inmatning();
    } while (val == 'y' || val == 'Y');
    
    printf("Programmet är avslutat");
    
    return 0;
}
